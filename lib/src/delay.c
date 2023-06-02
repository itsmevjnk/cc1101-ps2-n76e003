#include "delay.h"
#include "timer.h"
#include "N76E003.h"

void delay_ms(unsigned short t) {
	unsigned long t_start = timer_ticks;
	while(timer_ticks - t_start < t);
}

/* Timer 1 reload value for use by delay_us */
#if F_SYS % 12000000UL != 0
#define TIMER1_RELOAD_VALUE	65536 - F_SYS / (1000000UL)  // reload value = 65536 - F_CPU * time
#else
#define TIMER1_RELOAD_VALUE	65536 - F_SYS / (1000000UL * 12)  // reload value = 65536 - F_CPU * time / 12
#endif
#define TIMER_TL1						LOBYTE(TIMER1_RELOAD_VALUE)
#define TIMER_TH1						HIBYTE(TIMER1_RELOAD_VALUE)
#define TIMER1_RELOAD				TH1 = TIMER_TH1; TL1 = TIMER_TL1 // macro for reloading timer

void delay_us(unsigned short t) {
#if F_SYS % 12000000UL != 0
	set_T1M; // set Timer 1 to use Fsys (non-divided) for clock source (since Fsys/12 would be inaccurate as hell)
#else
	clr_T1M; // set Timer 1 to use Fsys/12 for clock source
#endif
	TMOD = (TMOD & ~(SET_BIT4 | SET_BIT5)) | SET_BIT4; // set Timer 1 to run in mode 1 (16-bit timer)
	set_TR1; // start Timer 1
	while(t--) {
		clr_TF1; // clear overflow flag
		TIMER1_RELOAD;
		while(TF1 != 1); // wait until Timer 1 overflows
	}
	clr_TF1;
	clr_TR1; // stop Timer 1
}	