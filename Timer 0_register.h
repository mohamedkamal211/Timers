
#ifndef TIMER_0_REGISTER_H_
#define TIMER_0_REGISTER_H_

#define TIMER0_TCCR0          *((volatile u8*)0x53)
#define TCCR0_WGM00           6
#define TCCR0_WGM01           3
#define TCCR0_CS02            2
#define TCCR0_CS01            1
#define TCCR0_CS00            0

#define TIMER0_TIMSK          *((volatile u8*)0x59)
#define TIMSK_OCIE0           1

#define TIMER0_OCR0          *((volatile u8*)0x5C)




#endif
