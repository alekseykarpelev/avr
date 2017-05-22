/*
 * tinny_pwm_2.c
 *
 * Created: 07.04.2017 20:37:55
 * Author : ОПРС Богуславец
 */ 
#define  F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#define butt_1   !(PINA&(1 << PINA0)) 
#define butt_2   !(PINA&(1 << PINA1))


int main(void)
{

PORTA = 0x00;
DDRA = 0x00; 	
	
	
PORTB=0x00;
DDRB=0xFF;


TCCR1A=0xF3;
TCCR1B=0x04;
TCCR1C=0xC1;
OCR1C=0xFF;
OCR1A=0x1E;
//OCR1A=0x00;
//int x;
void blinc(int x)
{
PORTB=0x01;
_delay_ms(x);
PORTB=0x00;
_delay_ms(x);	
}





while (1)
{
   
	if (butt_1 == 0 && OCR1A<255)
	{
	OCR1A = OCR1A +5 ;	
	_delay_ms(100);	
	}
	
	
	if (butt_2 == 0 && OCR1A>0)
	{
		OCR1A = OCR1A - 5 ;
		_delay_ms(100);
	}
	
	if (butt_2 == 0 && OCR1A==0)
	
	{
	blinc(50);
	}
	
	
	if (butt_1 == 0 && OCR1A==255)
	
	{
	blinc(200);
	}
		
}
}

