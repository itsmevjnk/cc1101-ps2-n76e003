#include "sysclk.h"
#include "N76E003.h"

#define TA_UNLOCK			TA = 0xAA; TA = 0x55 // unlock TA write protection (for next 4 cycles)

void sysclk_init(void) {
	/* disable interrupts */
	unsigned char ea_val = EA;
	unsigned char ckswt_val = CKSWT & ~(SET_BIT1 | SET_BIT2); // CKSWT with the OSC bits masked out (should be stored in a register)
	EA = 0;
	
	/* enable clock source and wait until it's stable (we'll disable what we don't need later) */
#if defined(SYSCLK_USE_HIRC)
	TA_UNLOCK; CKEN |= SET_BIT5;
	while(!(CKSWT & SET_BIT5)); // wait until HIRC is stable
#elif defined(SYSCLK_USE_XTAL)
	TA_UNLOCK; CKEN |= SET_BIT6 | SET_BIT7;
	while(!(CKSWT & SET_BIT3)); // wait until external clock is stable
#elif defined(SYSCLK_USE_LIRC)
	while(!(CKSWT & SET_BIT4)); // wait until LIRC is stable
#endif
	
	/* switch clock source and wait until it's successful */
	
	TA_UNLOCK;
#if defined(SYSCLK_USE_HIRC)
	CKSWT = ckswt_val; // switch to HIRC (00)
#elif defined(SYSCLK_USE_XTAL)
	CKSWT = ckswt_val | SET_BIT1; // switch to external clock source (01)
#elif defined(SYSCLK_USE_LIRC)
	CKSWT = ckswt_val | SET_BIT2; // switch to LIRC (10)
#endif
	CKDIV = SYSCLK_CKDIV; // set CKDIV value
	while(CKEN & SET_BIT0); // wait until clock switch fault flag is cleared (stable clock)
	
	/* disable the sources that we don't need */
#if defined(SYSCLK_USE_HIRC)
	TA_UNLOCK; CKEN &= ~(SET_BIT6 | SET_BIT7); // disable external clock source
#elif defined(SYSCLK_USE_XTAL)
	TA_UNLOCK; CKEN &= ~SET_BIT5; // disable HIRC
#endif

	EA = ea_val; // restore EA value
}