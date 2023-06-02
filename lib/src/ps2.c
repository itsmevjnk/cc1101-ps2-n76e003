#include "ps2.h"
#include "timer.h"
#include "delay.h"
#include "spi.h"
#include "N76E003.h"

static unsigned long xdata ps2_last_read = 0;
unsigned char xdata ps2_buffer[32];

#ifdef PS2_ANALOG
static unsigned long xdata ps2_last_polled = 0; // timestamp of last poll, needed to determine whether reconfiguration is needed (analog mode only
#endif

#define PS2_ATT_LOW				while(timer_ticks - ps2_last_read < PS2_DELAY_PACKET); PS2_ATT_Px &= ~(1 << PS2_ATT_PIN); delay_us(PS2_DELAY_BYTE)
#define PS2_ATT_HIGH			PS2_ATT_Px |= (1 << PS2_ATT_PIN); ps2_last_read = timer_ticks

unsigned char ps2_transfer(unsigned char cmd) {
	unsigned char ret = 0; // return value
	unsigned char i;
	
	SPI_DISABLE;
	SPI_MODE2;
	SPI_LSBFIRST;
	SPI_ENABLE;
	
	PS2_ATT_LOW;
	
	if(spi_transfer(0x01) != 0xFF) goto finish; // first byte mismatch
	ret = spi_transfer(cmd);
	if(spi_transfer(0x00) != 0x5A) { ret = 0; goto finish; } // third byte mismatch
	for(i = 0; i < (ps2_transfer_words(ret) << 1); i++) ps2_buffer[i] = spi_transfer(ps2_buffer[i]); // this first reads ps2_buffer[i] to get the command byte, then saves the received data byte to ps2_buffer[i]
  
finish:
  PS2_ATT_HIGH;
  return ret;
}

char ps2_configure(void) {
	unsigned char ret, i;
	
	/* enter escape mode */
	ps2_buffer[0] = 0x01; ps2_buffer[1] = 0x00;
	if(ps2_transfer(0x43) == 0) return 1; // cannot enter escape mode
	
	/* set controller mode accordingly */
#ifdef PS2_ANALOG
	ps2_buffer[0] = 0x01;
#else
	ps2_buffer[0] = 0x00;
#endif
	ps2_buffer[1] = 0x03; ps2_buffer[2] = 0; ps2_buffer[3] = 0; ps2_buffer[4] = ps2_buffer[5] = 0;
	if(ps2_transfer(0x44) == 0) return 2; // cannot set controller mode
	
	/* enable all polling result fields (analog mode only) */
#ifdef PS2_PRESSURE
	ps2_buffer[0] = 0xFF; ps2_buffer[1] = 0xFF; ps2_buffer[2] = 0x03;
#else
	ps2_buffer[0] = 0x3F; ps2_buffer[1] = 0x00; ps2_buffer[2] = 0x00;
#endif
	ps2_buffer[3] = 0x00; ps2_buffer[4] = 0x00; ps2_buffer[5] = 0x00;
	if(ps2_transfer(0x4F) == 0) return 3; // cannot set polling result fields
	
	/* enable vibrators (if specified) */
#ifdef PS2_RUMBLE
	ps2_buffer[0] = 0x00; ps2_buffer[1] = 0x01;
	ps2_buffer[2] = 0xFF; ps2_buffer[3] = 0xFF; ps2_buffer[4] = 0xFF; ps2_buffer[5] = 0xFF;
	if(ps2_transfer(0x4D) == 0) return 4; // cannot enable vibrators
#endif

	/* exit escape mode */
	ps2_buffer[0] = 0x00; ps2_buffer[1] = 0x00;
	if(ps2_transfer(0x43) == 0) return 5; // cannot exit escape mode
	
	/* verify escape mode exit */
	for(i = 0; i < 18; i++) ps2_buffer[i] = 0; // just to be on the safe side
	ret = ps2_transfer_mode(ret);
	if(ret == 0) return 6; // cannot exit escape mode (connectivity issue)
	// goofy ahh if statements to circumvent Keil's broken compiler
#ifdef PS2_ANALOG
	if(ret - 0x07 != 0) return 7; // controller does not respond to mode change correctly
#else
	if(ret - 0x04 != 0) return 7;
#endif
	if(ret - 0x0F == 0) return 8; // controller is stuck in escape mode
	
	return 0; // success
}

char ps2_init(void) {
	char ret; // may need this
	
	/* set ATT to push-pull */
	PS2_ATT_PxM1 &= ~(1 << PS2_ATT_PIN);
	PS2_ATT_PxM2 |= (1 << PS2_ATT_PIN);
	PS2_ATT_HIGH;
	
	/* poll as a test */
	if(ps2_transfer(0x42) == 0) return 1; // cannot poll controller
	
	ret = ps2_configure();
	if(ret != 0) return (1 + ret);
#ifdef PS2_ANALOG
	ps2_last_polled = timer_ticks;
#endif
	
	return 0;
}

//#define PS2_DEBUG // uncomment to indicate we're in a debug session (so the controller gets reconfigured on every poll)

unsigned char ps2_poll(void) {
	unsigned char i, ret;
	
	/* reconfigure if needed */
#ifdef PS2_ANALOG
#ifndef PS2_DEBUG
	if(timer_ticks - ps2_last_polled >= PS2_DUR_RECONFIG) {
#endif
		if(ps2_configure() != 0) return 0;
#ifndef PS2_DEBUG
	}
#endif
#endif
	for(i = 0; i < 18; i++) ps2_buffer[i] = 0; // just to be on the safe side
	ret = ps2_transfer(0x42);
#ifdef PS2_ANALOG
	ps2_last_polled = timer_ticks;
#endif
	return ret;
}