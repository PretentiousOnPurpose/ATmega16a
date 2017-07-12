#include<avr/io.h>
#include<util/delay.h>
#include "adc.h"

void main() {
	adc_init();
	DDRC = 0xff;
	DDRD = 0xff;
	DDRB = 0xff;
	PORTB = 0x03;
	
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x0C);
	cmd(0x06);
	
	while(1) {
		char temp[14] = "Temp: ";
		char temp2[3] = " C";
		char val[4];
		double tem = getdata(0x00) - 100;
		tem -= 32;
		tem = tem * 5/9;
		itoa((int)tem , val , 10);
		strcat(temp , val);
		strcat(temp , temp2);
		int i = 0;
		while(temp[i] != '\0') {
			data(temp[i]);
			i++;
		}
		_delay_ms(500);
		cmd(0x01);
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
