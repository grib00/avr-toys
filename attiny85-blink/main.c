#include <avr/io.h>
#include <util/delay.h>
 
int main(void) {
	DDRB = 0b00000011;
	 
	PORTB ^= (1 << PB0);
	for(;;) {
		PORTB ^= (1 << PB0);
		PORTB ^= (1 << PB1);
		_delay_ms(500);
	}
	
	return 0;
}

