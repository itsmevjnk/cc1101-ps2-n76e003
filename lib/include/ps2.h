#ifndef PS2_H
#define PS2_H

extern unsigned char xdata ps2_buffer[32];

/* PS2 controller timing configuration - change this if you're having issues */
#define PS2_DELAY_BYTE                  10 // delay duration between ATT becoming active and first byte read/between byte reads (in uS)
#define PS2_DELAY_PACKET                16 // delay duration between packets (between ATT becoming inactive and becoming active again) (in mS) - set to playstation.txt value
#define PS2_DUR_RECONFIG								1500 // duration between polls to trigger reconfiguration in mS

#define PS2_ATT_PxM1							P1M1
#define PS2_ATT_PxM2							P1M2
#define PS2_ATT_Px								P1
#define PS2_ATT_PIN								1

#define ps2_transfer_mode(ret)          ((ret) >> 4)
#define ps2_transfer_words(ret)         ((ret) & 0x0F)

/* PS2 controller mode configuration */
#define PS2_ANALOG // use analog mode instead of digital mode
#define PS2_RUMBLE // use rumble motors
#define PS2_PRESSURE // get pressure reading from all buttons

/* macros to interpret poll buffer */
#define PS2_DIG_SELECT						(!(ps2_buffer[0] & (1 << 0)))
#define PS2_DIG_L3								(!(ps2_buffer[0] & (1 << 1)))
#define PS2_DIG_R3								(!(ps2_buffer[0] & (1 << 2)))
#define PS2_DIG_START							(!(ps2_buffer[0] & (1 << 3)))
#define PS2_DIG_UP								(!(ps2_buffer[0] & (1 << 4)))
#define PS2_DIG_RIGHT							(!(ps2_buffer[0] & (1 << 5)))
#define PS2_DIG_DOWN							(!(ps2_buffer[0] & (1 << 6)))
#define PS2_DIG_LEFT							(!(ps2_buffer[0] & (1 << 7)))
#define PS2_DIG_L2								(!(ps2_buffer[1] & (1 << 0)))
#define PS2_DIG_R2								(!(ps2_buffer[1] & (1 << 1)))
#define PS2_DIG_L1								(!(ps2_buffer[1] & (1 << 2)))
#define PS2_DIG_R1								(!(ps2_buffer[1] & (1 << 3)))
#define PS2_DIG_TRIANGLE					(!(ps2_buffer[1] & (1 << 4)))
#define PS2_DIG_CIRCLE						(!(ps2_buffer[1] & (1 << 5)))
#define PS2_DIG_CROSS							(!(ps2_buffer[1] & (1 << 6)))
#define PS2_DIG_SQUARE						(!(ps2_buffer[1] & (1 << 7)))

#ifdef PS2_ANALOG
#define PS2_ANA_RX								ps2_buffer[2]
#define PS2_ANA_RY								ps2_buffer[3]
#define PS2_ANA_LX								ps2_buffer[4]
#define PS2_ANA_LY								ps2_buffer[5]
#define PS2_ANA_RIGHT							ps2_buffer[6]
#define PS2_ANA_LEFT							ps2_buffer[7]
#define PS2_ANA_UP								ps2_buffer[8]
#define PS2_ANA_DOWN							ps2_buffer[9]
#define PS2_ANA_TRIANGLE					ps2_buffer[10]
#define PS2_ANA_CIRCLE						ps2_buffer[11]
#define PS2_ANA_CROSS							ps2_buffer[12]
#define PS2_ANA_SQUARE						ps2_buffer[13]
#define PS2_ANA_L2								ps2_buffer[14]
#define PS2_ANA_R2								ps2_buffer[15]
#define PS2_ANA_L1								ps2_buffer[16]
#define PS2_ANA_R1								ps2_buffer[17]
#endif

/* alternate define names */
#define PS2_DIG_O									PS2_DIG_CIRCLE
#define PS2_DIG_X									PS2_DIG_CROSS
#define PS2_ANA_O									PS2_ANA_CIRCLE
#define PS2_ANA_X									PS2_ANA_CROSS

unsigned char ps2_transfer(unsigned char cmd);
char ps2_init(void);
unsigned char ps2_poll(void);

#endif