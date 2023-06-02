#ifndef SYSCLK_H
#define SYSCLK_H

/* clock source selection - only define one at a time */
#define SYSCLK_USE_HIRC // 16MHz internal oscillator
//#define SYSCLK_USE_LIRC // 10kHz internal oscillator
//#define SYSCLK_USE_XTAL // external crystal oscillator on XIN

/* F_OSC value */
#if defined(SYSCLK_USE_HIRC)
#define F_OSC					16000000UL
#elif defined(SYSCLK_USE_LIRC)
#define F_OSC					10000UL
#elif defined(SYSCLK_USE_XTAL)
#if defined(F_ECLK)
#define F_OSC					F_ECLK
#else
#error "External crystal oscillator selected but no F_ECLK is given at compile time"
#endif
#else
#error "No clock source selected"
#endif

/* CKDIV value */
#if F_OSC < F_SYS
#error "Requested F_SYS is higher than clock source frequency"
#elif F_OSC % (2 * F_SYS) != 0
#error "Cannot set suitable CKDIV"
#else
#define SYSCLK_CKDIV	(F_OSC / F_SYS) / 2
#if SYSCLK_CKDIV > 0xFF
#error "Cannot set suitable CKDIV"
#endif
#endif

void sysclk_init(void);

#endif