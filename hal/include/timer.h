#ifndef TIMER_H
#define TIMER_H

extern volatile unsigned long xdata timer_ticks;

void timer_init(void);

#endif