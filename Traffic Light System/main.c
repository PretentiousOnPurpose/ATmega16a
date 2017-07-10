#include<avr/io.h>
#include<util/delay.h>
// using Pin B0 , B1 , B2 for Red lights
// using Pin D0 , D1 , D2 for green lights
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
