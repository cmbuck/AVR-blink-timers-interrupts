#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL  // 1 MHz

#define bit_get(p,m) ((p) & (m)) 
#define bit_set(p,m) ((p) |= (m)) 
#define bit_clr(p,m) ((p) &= ~(m)) 
#define bit_flip(p,m) ((p) ^= (m)) 
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m)) 
#define BIT(x) (0x01 << (x))

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << 0);  //toggle LED
}

int main(void)
{
	DDRB |= BIT(0);
	
	TCCR1B |= (1 << WGM12); //enable CTC mode
	
	OCR1A = 488; //about 2 Hz with 1024 prescale
	
	TCCR1B |= (1 << CS10) | (1 << CS12); // Set up timer with 1024 prescale
	
	TIMSK1 |= (1 << OCIE1A); //enable timer1 CTC interrupt
	sei();			//enable global interrupts
	
	while (1)
	{
		//blinking is handled with ISR	
	}
	
}