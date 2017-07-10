#include<avr/io.h>
#include<util/delay.h>

void main() {
	DDRD = 0xff;
	DDRB = 0xff;
	while(1) {
		PORTD = 0x01;
		PORTB = 0x06;
		_delay_ms(2000);
		PORTD = 0x02;
		PORTB = 0x05;
		_delay_ms(2000);
		PORTD = 0x04;
		PORTB = 0x03;
		_delay_ms(2000);
	}
}
