#include "main.h"

unsigned char txbuf[20]; // TX buffer

void main(void) {
	unsigned char i;
	
	sysclk_init();
	timer_init();
	
	spi_init();
	
	//TI_CC_SPISetup();
	//delay_ms(5);
	//TI_CC_PowerupResetCCxxxx();
	//writeRFSettings(4);
	//delay_ms(100);
	ps2_init();
	
	txbuf[0] = 19; // 18+1 bytes (we need to send address also)
	txbuf[1] = 0x5A; // TODO: change this
	
	P14_PushPull_Mode; // use P1.4 as debug (X button)
	while(1) {
		ps2_poll();
		for(i = 0; i < 18; i++) txbuf[2 + i] = ps2_buffer[i]; // copy PS2 packet buffer to TX buffer
		//RFSendPacket(txbuf, 20); // send buffer
		//ps2_buffer[0] = ~ps2_buffer[0]; ps2_buffer[1] = ~ps2_buffer[1];
		if(PS2_DIG_X) P1 &= ~SET_BIT4;
		else P1 |= SET_BIT4;
		//delay_ms(20);
	}
}