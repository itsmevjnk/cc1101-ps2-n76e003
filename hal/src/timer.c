#include "timer.h"
#include "N76E003.h"

volatile unsigned long xdata timer_ticks = 0; // store in XRAM so we don't waste the epic IRAM

/* reload values, precalculated in compile time using frequency in F_CPU */
#define TIMER0_RELOAD_VALUE	65536 - F_SYS / (1000 * 12)  // reload value = 65536 - F_CPU * time / 12; time in this case = 1ms = 0.001s = 1/1000s
#define TIMER_TL0						LOBYTE(TIMER0_RELOAD_VALUE)
#define TIMER_TH0						HIBYTE(TIMER0_RELOAD_VALUE)
#define TIMER0_RELOAD				TH0 = TIMER_TH0; TL0 = TIMER_TL0 // macro for reloading timer

void timer_init(void) {
	/* Timer 0 initialization */
	clr_T0M; // set Timer 0 to use Fsys/12 for clock source (as with the standard 8051)
	TMOD = (TMOD & ~(SET_BIT0 | SET_BIT1)) | SET_BIT0; // set Timer 0 to run in mode 1 (16-bit timer)
	TIMER0_RELOAD; // preload timer value
	set_ET0; // enable Timer 0 interrupt
	set_EA; // enable interrupts
	set_TR0; // start Timer 0
}

void timer0_isr(void) interrupt 1 {
	TIMER0_RELOAD;
	timer_ticks++; // increment our ticks
}
