#include "SanUSB1.h"
#include "lcd.h"

unsigned int i;
unsigned char buffer1[20];

#pragma interrupt interrupcao 
void interrupcao(){}

void main(void) {
	clock_int_4MHz();
	habilita_canal_AD(AN0);
	
	lcd_ini();
	//Lcd_Cmd(LCD_CLEAR);
	Lcd_Cmd(LCD_CURSOR_OFF);
	tempo_ms(100);
	
	lcd_escreve(1, 1, "tinyurl.com/");
	tempo_ms(600);
	
	lcd_escreve(2, 1, "SanUSB");
	tempo_ms(500);
	
    while(1)
    {
		i= le_AD10bits(0);
		
		sprintf(buffer1,"%d  ",i);
		lcd_escreve2(2, 12, buffer1); //com buffer
		tempo_ms(100);
       	}
}
























