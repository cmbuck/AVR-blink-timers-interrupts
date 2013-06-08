#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL  // 1 MHz

#define bit_get(p,m) ((p) & (m)) 
#define bit_set(p,m) ((p) |= (m)) 
#define bit_clr(p,m) ((p) &= ~(m)) 
#define bit_flip(p,m) ((p) ^= (m)) 
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m)) 
#define BIT(x) (0x01 << (x))


int main(void)
{
	DDRB |= BIT(0);
	
	TCCR1B |= (1 << CS10 ); // Set up timer
	
	while (1)
	{
		/**
		 *bit_set( PORTB, BIT(0) );
		 *_delay_ms(100);
		 *bit_clr( PORTB, BIT(0) );
		 *_delay_ms(100);
		 */

		if (TCNT1 > 49999)
		{
			bit_flip( PORTB, BIT(0) );
			
			TCNT1 = 0;
		}
		
		
	}
	
}