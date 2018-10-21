#include "timer0.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

#include "es.h"

volatile uint8_t timer0 = 0;

void initialize_timer0(void)
{
#if F_CPU == 16000000UL
	// Set CTC mode and CLK/1024 (16000000 / 64 == 250000 Hz)
	TCCR0 = _BV(WGM01)|_BV(CS02)|_BV(CS00);
#elif F_CPU == 8000000UL
	// Set CTC mode and CLK/1024 (8000000 / 64 == 125000 Hz)
	TCCR0 = _BV(WGM01)|_BV(CS02)|_BV(CS00);
#elif F_CPU == 4000000UL
	// Set CTC mode and CLK/1024 (8000000 / 8 == 500000 Hz)
	TCCR0 = _BV(WGM01)|_BV(CS01);
#else
	#error "F_CPU not supported, allow only 16MHz, 8MHz, 4MHz"
#endif

	// Reset timer
	TCNT0 = 0;

#if F_CPU == 16000000UL
	// Set compare value to reset at 250 (250000 / 250 == 1000 Hz)
	OCR0 = 250;
#elif F_CPU == 8000000UL
	// Set compare value to reset at 125 (125000 / 125 == 1000 Hz)
	OCR0 = 125;
#elif F_CPU == 4000000UL
	// Set compare value to reset at 125 (500000 / 250 == 2000 Hz)
	OCR0 = 250;
#endif

	// Enable interrupt by compare match
	TIMSK |= _BV(OCIE0);

	// Clear compare match interrupt flag
	TIFR  |= _BV(OCF0);
}

ISR(TIMER0_COMP_vect)
{
    timer0++;

#if F_CPU == 4000000UL
    // Check sub-counter value == 100 (2000 / 200 == 10Hz)
    if (timer0 >= 200) {
#else
    // Check sub-counter value == 100 (1000 / 100 == 10Hz)
    if (timer0 >= 100) {
#endif
        es_trigger(ES_EVENT_TIMER0_COMP);
        timer0 = 0;
    }
}
