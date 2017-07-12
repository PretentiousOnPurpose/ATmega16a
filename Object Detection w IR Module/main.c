#include<avr/io.h>
#include<util/delay.h>
#include "adc.h"
#include<string.h>
void main() {
	adc_init();
// PORTD is used for LCD Data transfer	
    DDRD = 0xff;
// PORTC is used for setting values of EN , RS , RW  
		DDRC = 0xff;
// PORTB is set high and used as input power for Red LED
// Arduino in the video is used for supplying input voltage for LCD Backlight. (I fell short of wires)
		DDRB= 0xff;
	//	PORTB = 0x01;
		int i = 0;
		cmd(0x38);
		cmd(0x01);
		cmd(0x80);
		cmd(0x0C);
		cmd(0x06);	
	
	while(1) {
		while(getdata(0x00) > 10) {	
			//int y = getdata(0x01);
			char xs[] = "Object Found";
			i = 0;
			while(xs[i] != '\0') {
				data(xs[i]);
				i++;
			}	
			PORTB = 0x01;
			_delay_ms(200);
			PORTB = 0x00;
			_delay_ms(250);
			cmd(0x01);
	}
	
		char cl[] = " Path Clean";
		_delay_ms(10);
		i = 0;
		cmd(0x01);
		while(cl[i] != '\0') {
			data(cl[i]);
			i++;
		}
		_delay_ms(500);
	}

}

void cmd(unsigned char a) {
	PORTD = a;
	PORTC = 0x04;
	_delay_ms(1);
	PORTC = 0x00;
	_delay_ms(1);
}
void data(unsigned char a) {
	PORTD = a;
	PORTC = 0x05;
	_delay_ms(1);
	PORTC = 0x01;
	_delay_ms(1);
}
