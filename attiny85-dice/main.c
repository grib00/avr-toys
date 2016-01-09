#include <avr/io.h>
#include <util/delay.h>

int i = 1;

void displayNumber(int n) {
	if (n == 1) PORTB = 0b0001;
	else if (n == 2) PORTB = 0b0100;
	else if (n == 3) PORTB = 0b0101;
	else if (n == 4) PORTB = 0b0110;
	else if (n == 5) PORTB = 0b0111;
	else if (n == 6) PORTB = 0b1110;
	else PORTB = 0;
}

void setup(void) {
	DDRB = 0b001111;
	PORTB = 0;
}

void loop(void) {
	int pressed = PINB & 0b010000;
	if (pressed) {
		displayNumber(i);
		_delay_ms(10);
		i = i + 1;
		if (i == 7) i = 1;
	} else {
		_delay_ms(10);
	}
}

int main(void) {
	setup();
	while(1) {
		loop();
	}
	return 0;
}

