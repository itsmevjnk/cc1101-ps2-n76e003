#ifndef FUNCTION_DEFINE_H
#define FUNCTION_DEFINE_H

/*--------------------------------------------------------------------------
N76E003 Function_define.h V1.02

All function define inital setting file for Nuvoton N76E003
--------------------------------------------------------------------------*/



typedef bit                   BIT;
typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;

typedef signed char           int8_t;
typedef signed int            int16_t;
typedef signed long           int32_t;

#define Disable  0
#define Enable   1

#define FAIL            1
#define PASS            0

#define TRUE                    1
#define FALSE                   0

//16 --> 8 x 2
#define HIBYTE(v1)              ((UINT8)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              ((UINT8)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         ((((UINT16)(v1))<<8)+(UINT16)(v2))      //v1,v2 is UINT8
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   (UINT32)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is UINT8
//32 --> 16 x 2
#define YBYTE1(v1)              ((UINT16)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              ((UINT16)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              ((UINT8)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              ((UINT8)((v1)>>16))
#define TBYTE1(v1)              ((UINT8)((v1)>>8)) 
#define TBYTE0(v1)              ((UINT8)((v1)&0xFF))

#define SET_BIT0        0x01  
#define SET_BIT1        0x02  
#define SET_BIT2        0x04  
#define SET_BIT3        0x08  
#define SET_BIT4        0x10  
#define SET_BIT5        0x20  
#define SET_BIT6        0x40  
#define SET_BIT7        0x80  

#define CLR_BIT0        0xFE
#define CLR_BIT1        0xFD
#define CLR_BIT2        0xFB
#define CLR_BIT3        0xF7
#define CLR_BIT4        0xEF
#define CLR_BIT5        0xDF
#define CLR_BIT6        0xBF
#define CLR_BIT7        0x7F

#define nop _nop_();


/*****************************************************************************************
* For GPIO INIT setting 
*****************************************************************************************/
//------------------- Define Port as Quasi mode  -------------------
#define P00_Quasi_Mode				P0M1&=~SET_BIT0;P0M2&=~SET_BIT0
#define P01_Quasi_Mode				P0M1&=~SET_BIT1;P0M2&=~SET_BIT1
#define P02_Quasi_Mode				P0M1&=~SET_BIT2;P0M2&=~SET_BIT2
#define P03_Quasi_Mode				P0M1&=~SET_BIT3;P0M2&=~SET_BIT3
#define P04_Quasi_Mode				P0M1&=~SET_BIT4;P0M2&=~SET_BIT4
#define P05_Quasi_Mode				P0M1&=~SET_BIT5;P0M2&=~SET_BIT5
#define P06_Quasi_Mode				P0M1&=~SET_BIT6;P0M2&=~SET_BIT6
#define P07_Quasi_Mode				P0M1&=~SET_BIT7;P0M2&=~SET_BIT7
#define P10_Quasi_Mode				P1M1&=~SET_BIT0;P1M2&=~SET_BIT0
#define P11_Quasi_Mode				P1M1&=~SET_BIT1;P1M2&=~SET_BIT1
#define P12_Quasi_Mode				P1M1&=~SET_BIT2;P1M2&=~SET_BIT2
#define P13_Quasi_Mode				P1M1&=~SET_BIT3;P1M2&=~SET_BIT3
#define P14_Quasi_Mode				P1M1&=~SET_BIT4;P1M2&=~SET_BIT4
#define P15_Quasi_Mode				P1M1&=~SET_BIT5;P1M2&=~SET_BIT5
#define P16_Quasi_Mode				P1M1&=~SET_BIT6;P1M2&=~SET_BIT6
#define P17_Quasi_Mode				P1M1&=~SET_BIT7;P1M2&=~SET_BIT7
#define P30_Quasi_Mode				P3M1&=~SET_BIT0;P3M2&=~SET_BIT0
//------------------- Define Port as Push Pull mode -------------------
#define P00_PushPull_Mode			P0M1&=~SET_BIT0;P0M2|=SET_BIT0
#define P01_PushPull_Mode			P0M1&=~SET_BIT1;P0M2|=SET_BIT1
#define P02_PushPull_Mode			P0M1&=~SET_BIT2;P0M2|=SET_BIT2
#define P03_PushPull_Mode			P0M1&=~SET_BIT3;P0M2|=SET_BIT3
#define P04_PushPull_Mode			P0M1&=~SET_BIT4;P0M2|=SET_BIT4
#define P05_PushPull_Mode			P0M1&=~SET_BIT5;P0M2|=SET_BIT5
#define P06_PushPull_Mode			P0M1&=~SET_BIT6;P0M2|=SET_BIT6
#define P07_PushPull_Mode			P0M1&=~SET_BIT7;P0M2|=SET_BIT7
#define P10_PushPull_Mode			P1M1&=~SET_BIT0;P1M2|=SET_BIT0
#define P11_PushPull_Mode			P1M1&=~SET_BIT1;P1M2|=SET_BIT1
#define P12_PushPull_Mode			P1M1&=~SET_BIT2;P1M2|=SET_BIT2
#define P13_PushPull_Mode			P1M1&=~SET_BIT3;P1M2|=SET_BIT3
#define P14_PushPull_Mode			P1M1&=~SET_BIT4;P1M2|=SET_BIT4
#define P15_PushPull_Mode			P1M1&=~SET_BIT5;P1M2|=SET_BIT5
#define P16_PushPull_Mode			P1M1&=~SET_BIT6;P1M2|=SET_BIT6
#define P17_PushPull_Mode			P1M1&=~SET_BIT7;P1M2|=SET_BIT7
#define P30_PushPull_Mode			P3M1&=~SET_BIT0;P3M2|=SET_BIT0
#define GPIO1_PushPull_Mode		P1M1&=~SET_BIT0;P1M2|=SET_BIT0
//------------------- Define Port as Input Only mode -------------------
#define P00_Input_Mode				P0M1|=SET_BIT0;P0M2&=~SET_BIT0
#define P01_Input_Mode				P0M1|=SET_BIT1;P0M2&=~SET_BIT1
#define P02_Input_Mode				P0M1|=SET_BIT2;P0M2&=~SET_BIT2
#define P03_Input_Mode				P0M1|=SET_BIT3;P0M2&=~SET_BIT3
#define P04_Input_Mode				P0M1|=SET_BIT4;P0M2&=~SET_BIT4
#define P05_Input_Mode				P0M1|=SET_BIT5;P0M2&=~SET_BIT5
#define P06_Input_Mode				P0M1|=SET_BIT6;P0M2&=~SET_BIT6
#define P07_Input_Mode				P0M1|=SET_BIT7;P0M2&=~SET_BIT7
#define P10_Input_Mode				P1M1|=SET_BIT0;P1M2&=~SET_BIT0
#define P11_Input_Mode				P1M1|=SET_BIT1;P1M2&=~SET_BIT1
#define P12_Input_Mode				P1M1|=SET_BIT2;P1M2&=~SET_BIT2
#define P13_Input_Mode				P1M1|=SET_BIT3;P1M2&=~SET_BIT3
#define P14_Input_Mode				P1M1|=SET_BIT4;P1M2&=~SET_BIT4
#define P15_Input_Mode				P1M1|=SET_BIT5;P1M2&=~SET_BIT5
#define P16_Input_Mode				P1M1|=SET_BIT6;P1M2&=~SET_BIT6
#define P17_Input_Mode				P1M1|=SET_BIT7;P1M2&=~SET_BIT7
#define P30_Input_Mode				P3M1|=SET_BIT0;P3M2&=~SET_BIT0
//-------------------Define Port as Open Drain mode -------------------
#define P00_OpenDrain_Mode		P0M1|=SET_BIT0;P0M2|=SET_BIT0
#define P01_OpenDrain_Mode		P0M1|=SET_BIT1;P0M2|=SET_BIT1
#define P02_OpenDrain_Mode		P0M1|=SET_BIT2;P0M2|=SET_BIT2
#define P03_OpenDrain_Mode		P0M1|=SET_BIT3;P0M2|=SET_BIT3
#define P04_OpenDrain_Mode		P0M1|=SET_BIT4;P0M2|=SET_BIT4
#define P05_OpenDrain_Mode		P0M1|=SET_BIT5;P0M2|=SET_BIT5
#define P06_OpenDrain_Mode		P0M1|=SET_BIT6;P0M2|=SET_BIT6
#define P07_OpenDrain_Mode		P0M1|=SET_BIT7;P0M2|=SET_BIT7
#define P10_OpenDrain_Mode		P1M1|=SET_BIT0;P1M2|=SET_BIT0
#define P11_OpenDrain_Mode		P1M1|=SET_BIT1;P1M2|=SET_BIT1
#define P12_OpenDrain_Mode		P1M1|=SET_BIT2;P1M2|=SET_BIT2
#define P13_OpenDrain_Mode		P1M1|=SET_BIT3;P1M2|=SET_BIT3
#define P14_OpenDrain_Mode		P1M1|=SET_BIT4;P1M2|=SET_BIT4
#define P15_OpenDrain_Mode		P1M1|=SET_BIT5;P1M2|=SET_BIT5
#define P16_OpenDrain_Mode		P1M1|=SET_BIT6;P1M2|=SET_BIT6
#define P17_OpenDrain_Mode		P1M1|=SET_BIT7;P1M2|=SET_BIT7
#define P30_OpenDrain_Mode		P3M1|=SET_BIT0;P3M2|=SET_BIT0
//--------- Define all port as quasi mode ---------
#define Set_All_GPIO_Quasi_Mode			P0M1=0;P0M2=0;P1M1=0;P1M2=0;P3M1=0;P3M2=0

#define 		set_GPIO1		P12=1
#define 		clr_GPIO1		P12=0

/****************************************************************************
   Enable INT port 0~3
***************************************************************************/
#define 	Enable_INT_Port0					PICON &= 0xFB;
#define		Enable_INT_Port1					PICON |= 0x01;
#define		Enable_INT_Port2					PICON |= 0x02;
#define		Enable_INT_Port3					PICON |= 0x03;
/*****************************************************************************
 Enable each bit low level trig mode
*****************************************************************************/
#define		Enable_BIT7_LowLevel_Trig			PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define		Enable_BIT6_LowLevel_Trig			PICON&=0x7F;PINEN|=0x40;PIPEN&=0xBF
#define		Enable_BIT5_LowLevel_Trig			PICON&=0xBF;PINEN|=0x20;PIPEN&=0xDF
#define		Enable_BIT4_LowLevel_Trig			PICON&=0xBF;PINEN|=0x10;PIPEN&=0xEF
#define		Enable_BIT3_LowLevel_Trig			PICON&=0xDF;PINEN|=0x08;PIPEN&=0xF7
#define		Enable_BIT2_LowLevel_Trig			PICON&=0xEF;PINEN|=0x04;PIPEN&=0xFB
#define		Enable_BIT1_LowLevel_Trig			PICON&=0xF7;PINEN|=0x02;PIPEN&=0xFD
#define		Enable_BIT0_LowLevel_Trig			PICON&=0xFB;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit high level trig mode
*****************************************************************************/
#define		Enable_BIT7_HighLevel_Trig			PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define		Enable_BIT6_HighLevel_Trig			PICON&=0x7F;PINEN&=0xBF;PIPEN|=0x40
#define		Enable_BIT5_HighLevel_Trig			PICON&=0xBF;PINEN&=0xDF;PIPEN|=0x20
#define		Enable_BIT4_HighLevel_Trig			PICON&=0xBF;PINEN&=0xEF;PIPEN|=0x10
#define		Enable_BIT3_HighLevel_Trig			PICON&=0xDF;PINEN&=0xF7;PIPEN|=0x08
#define		Enable_BIT2_HighLevel_Trig			PICON&=0xEF;PINEN&=0xFB;PIPEN|=0x04
#define		Enable_BIT1_HighLevel_Trig			PICON&=0xF7;PINEN&=0xFD;PIPEN|=0x02
#define		Enable_BIT0_HighLevel_Trig			PICON&=0xFD;PINEN&=0xFE;PIPEN|=0x01
/*****************************************************************************
 Enable each bit falling edge trig mode
*****************************************************************************/
#define		Enable_BIT7_FallEdge_Trig			PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define		Enable_BIT6_FallEdge_Trig			PICON|=0x80;PINEN|=0x40;PIPEN&=0xBF
#define		Enable_BIT5_FallEdge_Trig			PICON|=0x40;PINEN|=0x20;PIPEN&=0xDF
#define		Enable_BIT4_FallEdge_Trig			PICON|=0x40;PINEN|=0x10;PIPEN&=0xEF
#define		Enable_BIT3_FallEdge_Trig			PICON|=0x20;PINEN|=0x08;PIPEN&=0xF7
#define		Enable_BIT2_FallEdge_Trig			PICON|=0x10;PINEN|=0x04;PIPEN&=0xFB
#define		Enable_BIT1_FallEdge_Trig			PICON|=0x08;PINEN|=0x02;PIPEN&=0xFD
#define		Enable_BIT0_FallEdge_Trig			PICON|=0x04;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit rasing edge trig mode
*****************************************************************************/
#define		Enable_BIT7_RasingEdge_Trig			PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define		Enable_BIT6_RasingEdge_Trig			PICON|=0x80;PINEN&=0xBF;PIPEN|=0x40
#define		Enable_BIT5_RasingEdge_Trig			PICON|=0x40;PINEN&=0xDF;PIPEN|=0x20
#define		Enable_BIT4_RasingEdge_Trig			PICON|=0x40;PINEN&=0xEF;PIPEN|=0x10
#define		Enable_BIT3_RasingEdge_Trig			PICON|=0x20;PINEN&=0xF7;PIPEN|=0x08
#define		Enable_BIT2_RasingEdge_Trig			PICON|=0x10;PINEN&=0xFB;PIPEN|=0x04
#define		Enable_BIT1_RasingEdge_Trig			PICON|=0x08;PINEN&=0xFD;PIPEN|=0x02
#define		Enable_BIT0_RasingEdge_Trig			PICON|=0x04;PINEN&=0xFE;PIPEN|=0x01


/* removed preset timer values since we don't need it */

//-------------------- Timer0 function define --------------------
#define		TIMER1_MODE0_ENABLE		TMOD&=0x0F
#define		TIMER1_MODE1_ENABLE		TMOD&=0x0F;TMOD|=0x10
#define		TIMER1_MODE2_ENABLE		TMOD&=0x0F;TMOD|=0x20
#define		TIMER1_MODE3_ENABLE		TMOD&=0x0F;TMOD|=0x30
//-------------------- Timer1 function define --------------------
#define		TIMER0_MODE0_ENABLE		TMOD&=0xF0
#define		TIMER0_MODE1_ENABLE		TMOD&=0xF0;TMOD|=0x01
#define		TIMER0_MODE2_ENABLE		TMOD&=0xF0;TMOD|=0x02
#define		TIMER0_MODE3_ENABLE		TMOD&=0xF0;TMOD|=0x03
//-------------------- Timer2 function define --------------------
#define 	TIMER2_DIV_4			T2MOD|=0x10;T2MOD&=0x9F
#define 	TIMER2_DIV_16			T2MOD|=0x20;T2MOD&=0xAF
#define 	TIMER2_DIV_32			T2MOD|=0x30;T2MOD&=0xBF
#define 	TIMER2_DIV_64			T2MOD|=0x40;T2MOD&=0xCF
#define		TIMER2_DIV_128		T2MOD|=0x50;T2MOD&=0xDF
#define 	TIMER2_DIV_256		T2MOD|=0x60;T2MOD&=0xEF
#define 	TIMER2_DIV_512		T2MOD|=0x70
#define 	TIMER2_Auto_Reload_Delay_Mode				T2CON&=~SET_BIT0;T2MOD|=SET_BIT7;T2MOD|=SET_BIT3
#define		TIMER2_Compare_Capture_Mode					T2CON|=SET_BIT0;T2MOD&=~SET_BIT7;T2MOD|=SET_BIT2

#define 	TIMER2_CAP0_Capture_Mode			T2CON&=~SET_BIT0;T2MOD=0x89
#define 	TIMER2_CAP1_Capture_Mode			T2CON&=~SET_BIT0;T2MOD=0x8A
#define 	TIMER2_CAP2_Capture_Mode			T2CON&=~SET_BIT0;T2MOD=0x8B

//-------------------- Timer2 Capture define --------------------
//--- Falling Edge -----
#define IC0_P12_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC1_P11_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC2_P10_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC3_P00_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC3_P04_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC4_P01_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC5_P03_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC6_P05_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC7_P15_CAP0_FallingEdge_Capture		CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4

#define IC0_P12_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC1_P11_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=SET_BIT5;CAPCON0|=SET_BIT5
#define	IC2_P10_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC3_P00_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC3_P04_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC4_P01_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC5_P03_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC6_P05_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC7_P15_CAP1_FallingEdge_Capture		CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5

#define IC0_P12_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC1_P11_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x10;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC2_P10_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x20;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC3_P00_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x30;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC3_P04_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x40;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC4_P01_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x50;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC5_P03_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x60;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC6_P05_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x70;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6
#define	IC7_P15_CAP2_FallingEdge_Capture		CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x80;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6

//----- Rising edge ----
#define IC0_P12_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC1_P11_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC2_P10_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC3_P00_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC3_P04_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC4_P01_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC5_P03_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC6_P05_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;
#define	IC7_P15_CAP0_RisingEdge_Capture			CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4;

#define IC0_P12_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0FCAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC1_P11_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC2_P10_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC3_P00_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC3_P04_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC4_P01_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC5_P03_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC6_P05_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC7_P15_CAP1_RisingEdge_Capture			CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;

#define IC0_P12_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC1_P11_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC2_P10_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC3_P00_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC3_P04_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC4_P01_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC5_P03_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC6_P05_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC7_P15_CAP3_RisingEdge_Capture			CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;

//-----BOTH  edge ----
#define IC0_P12_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC1_P11_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC2_P10_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC3_P00_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC3_P04_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC4_P01_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC5_P03_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC6_P05_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4
#define	IC7_P15_CAP0_BothEdge_Capture				CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=SET_BIT4;CAPCON2|=SET_BIT4

#define IC0_P12_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5
#define	IC1_P11_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC2_P10_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC3_P00_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC3_P04_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC4_P01_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC5_P03_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC6_P05_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;
#define	IC7_P15_CAP1_BothEdge_Capture				CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=SET_BIT5;CAPCON2|=SET_BIT5;

#define IC0_P12_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC1_P11_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC2_P10_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC3_P00_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC3_P04_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC4_P01_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC5_P03_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC6_P05_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;
#define	IC7_P15_CAP3_BothEdge_Capture				CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=SET_BIT6;CAPCON2|=SET_BIT6;

#define TIMER2_IC2_DISABLE									CAPCON0&=~SET_BIT6			 
#define TIMER2_IC1_DISABLE									CAPCON0&=~SET_BIT5			
#define TIMER2_IC0_DISABLE									CAPCON0&=~SET_BIT4	

/*****************************************************************************************
* For PWM setting 
*****************************************************************************************/
//--------- PMW clock source select define ---------------------
#define		PWM_CLOCK_FSYS					CKCON&=0xBF
#define		PWM_CLOCK_TIMER1				CKCON|=0x40
//--------- PWM clock devide define ----------------------------
#define		PWM_CLOCK_DIV_2					PWMCON1|=0x01;PWMCON1&=0xF9
#define		PWM_CLOCK_DIV_4					PWMCON1|=0x02;PWMCON1&=0xFA
#define		PWM_CLOCK_DIV_8					PWMCON1|=0x03;PWMCON1&=0xFB
#define		PWM_CLOCK_DIV_16				PWMCON1|=0x04;PWMCON1&=0xFC
#define		PWM_CLOCK_DIV_32				PWMCON1|=0x05;PWMCON1&=0xFD
#define		PWM_CLOCK_DIV_64				PWMCON1|=0x06;PWMCON1&=0xFE
#define		PWM_CLOCK_DIV_128				PWMCON1|=0x07
//--------- PWM I/O select define ------------------------------
#define		PWM5_P15_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x20;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output enable
#define		PWM5_P03_OUTPUT_ENABLE		PIOCON0|=0x20																										//P0.3 as PWM5
#define		PWM4_P01_OUTPUT_ENABLE		PIOCON0|=0x10																										//P0.1 as PWM4 output enable
#define		PWM3_P04_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x08;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output enable
#define		PWM3_P00_OUTPUT_ENABLE		PIOCON0|=0x08																										//P0.0 as PWM3 
#define		PWM2_P05_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x04;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output enable
#define		PWM2_P10_OUTPUT_ENABLE		PIOCON0|=0x04																										//P1.0 as PWM2
#define		PWM1_P14_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x02;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output enable
#define		PWM1_P11_OUTPUT_ENABLE		PIOCON0|=0x02																										//P1.1 as PWM1 
#define		PWM0_P12_OUTPUT_ENABLE		PIOCON0|=0x01																										//P1.2 as PWM0 output enable
#define 	ALL_PWM_OUTPUT_ENABLE			PIOCON0=0xFF;PIOCON1=0xFF
#define		PWM5_P15_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xDF;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output disable
#define		PWM5_P03_OUTPUT_DISABLE		PIOCON0&=0xDF																										//P0.3 as PWM5
#define		PWM4_P01_OUTPUT_DISABLE		PIOCON0&=0xEF																										//P0.1 as PWM4 output disable
#define		PWM3_P04_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xF7;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output disable
#define		PWM3_P00_OUTPUT_DISABLE		PIOCON0&=0xF7																										//P0.0 as PWM3 
#define		PWM2_P05_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFB;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output disable
#define		PWM2_P10_OUTPUT_DISABLE		PIOCON0&=0xFB																										//P1.0 as PWM2
#define		PWM1_P14_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFD;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output disable
#define		PWM1_P11_OUTPUT_DISABLE		PIOCON0&=0xFD																										//P1.1 as PWM1 
#define		PWM0_P12_OUTPUT_DISABLE		PIOCON0&=0xFE																										//P1.2 as PWM0 output disable
#define 	ALL_PWM_OUTPUT_DISABLE		PIOCON0=0x00;PIOCON1=0x00
//--------- PWM I/O Polarity Control ---------------------------
#define		PWM5_OUTPUT_INVERSE			PNP|=0x20				
#define		PWM4_OUTPUT_INVERSE			PNP|=0x10				
#define		PWM3_OUTPUT_INVERSE			PNP|=0x08				
#define		PWM2_OUTPUT_INVERSE			PNP|=0x04				
#define		PWM1_OUTPUT_INVERSE			PNP|=0x02				
#define		PWM0_OUTPUT_INVERSE			PNP|=0x01				
#define		PWM_OUTPUT_ALL_INVERSE	PNP=0xFF
#define		PWM5_OUTPUT_NORMAL			PNP&=0xDF				
#define		PWM4_OUTPUT_NORMAL			PNP&=0xEF				
#define		PWM3_OUTPUT_NORMAL			PNP&=0xF7				
#define		PWM2_OUTPUT_NORMAL			PNP&=0xFB				
#define		PWM1_OUTPUT_NORMAL			PNP&=0xFD				
#define		PWM0_OUTPUT_NORMAL			PNP&=0xFE				
#define		PWM_OUTPUT_ALL_NORMAL		PNP=0x00
//--------- PWM type define ------------------------------------
#define		PWM_EDGE_TYPE						PWMCON1&=~SET_BIT4
#define		PWM_CENTER_TYPE					PWMCON1|=SET_BIT4
//--------- PWM mode define ------------------------------------
#define		PWM_IMDEPENDENT_MODE		PWMCON1&=0x3F
#define		PWM_COMPLEMENTARY_MODE	PWMCON1|=0x40;PWMCON1&=0x7F
#define		PWM_SYNCHRONIZED_MODE		PWMCON1|=0x80;PWMCON1&=0xBF
#define 	PWM_GP_MODE_ENABLE			PWMCON1|=0x20
#define		PWM_GP_MODE_DISABLE			PWMCON1&=0xDF
//--------- PMW interrupt setting ------------------------------
#define		PWM_FALLING_INT					BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xCF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_RISING_INT					BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x10;PWMCON0&=0xDF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_CENTRAL_POINT_INT		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x20;PWMCON0&=0xEF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_PERIOD_END_INT			BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x30;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
//--------- PWM interrupt pin select ---------------------------
#define		PWM_INT_PWM0						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM1						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x01;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM2						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x02;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM3						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x03;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM4						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x04;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM5						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x05;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
//--------- PWM Dead time setting ------------------------------
#define 	PWM45_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x04;EA=BIT_TMP
#define 	PWM34_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x02;EA=BIT_TMP
#define 	PWM01_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x01;EA=BIT_TMP

/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#define Enable_ADC_AIN0			ADCCON0&=0xF0;P17_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT0;ADCCON1|=SET_BIT0									//P17
#define Enable_ADC_AIN1			ADCCON0&=0xF0;ADCCON0|=0x01;P30_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT1;ADCCON1|=SET_BIT0		//P30
#define Enable_ADC_AIN2			ADCCON0&=0xF0;ADCCON0|=0x02;P07_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT2;ADCCON1|=SET_BIT0		//P07
#define Enable_ADC_AIN3			ADCCON0&=0xF0;ADCCON0|=0x03;P06_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT3;ADCCON1|=SET_BIT0		//P06
#define Enable_ADC_AIN4			ADCCON0&=0xF0;ADCCON0|=0x04;P05_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT4;ADCCON1|=SET_BIT0		//P05
#define Enable_ADC_AIN5			ADCCON0&=0xF0;ADCCON0|=0x05;P04_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT5;ADCCON1|=SET_BIT0		//P04
#define Enable_ADC_AIN6			ADCCON0&=0xF0;ADCCON0|=0x06;P03_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT6;ADCCON1|=SET_BIT0		//P03
#define Enable_ADC_AIN7			ADCCON0&=0xF0;ADCCON0|=0x07;P11_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT7;ADCCON1|=SET_BIT0		//P11
#define Enable_ADC_BandGap	ADCCON0|=SET_BIT3;ADCCON0&=0xF8;ADCCON1|=SET_BIT0																							//Band-gap 1.22V
#define Disable_ADC					ADCCON1&=0xFE;

#define PWM0_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_FALLINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_RISINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_CENTRAL_TRIG_ADC				ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_CENTRAL_TRIG_ADC				ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_CENTRAL_TRIG_ADC				ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_END_TRIG_ADC						ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_END_TRIG_ADC						ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_END_TRIG_ADC						ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1

#define P04_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
#define P13_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6
#define P04_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
#define P13_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6

/*****************************************************************************************
* For SPI INIT setting 
*****************************************************************************************/
#define		SPICLK_DIV2							clr_SPR0;clr_SPR1
#define		SPICLK_DIV4							set_SPR0;clr_SPR1
#define		SPICLK_DIV8							clr_SPR0;set_SPR1
#define		SPICLK_DIV16						set_SPR0;set_SPR1
#define		Enable_SPI_Interrupt		set_ESPI;set_EA
#define		SS		P15

#endif