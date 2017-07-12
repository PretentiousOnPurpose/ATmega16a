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
//PORTB is set high and used as input power for LCD Backlight 
		DDRB= 0xff;
		PORTB = 0x01;
		int i = 0;
		cmd(0x38);
		cmd(0x01);
		cmd(0x80);
		cmd(0x0C);
		cmd(0x06);	
	
	
	while(1) {	
		char xs[10] = "x = ";
		char str[5];
		itoa(getdata(0x00) , str , 10);
		strcat(xs , str);
		i = 0;
		while(xs[i] != '\0') {
			data(xs[i]);
			i++;
		}		
		
		cmd(0x38);
		cmd(0xC0);
		cmd(0x0C);
		cmd(0x06);
		
		char ys[10] = "y = ";
		char str1[5];
		itoa(getdata(0x01) , str1 , 10);
		strcat(ys , str1);
		i = 0;
		while(ys[i] != '\0') {
			data(ys[i]);
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
