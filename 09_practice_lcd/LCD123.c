#include <16f877a.h>
#use delay(clock=4000000)
#fuses xt,nowdt

#USE fast_IO(A)
 
#define LCD_DB4   PIN_C4
#define LCD_DB5   PIN_C5
#define LCD_DB6   PIN_C6
#define LCD_DB7   PIN_C7

#define LCD_RS    PIN_C3
#define LCD_RW    PIN_C1
#define LCD_E     PIN_C2

#include <flex_lcd.c>



void main()
{
lcd_init();          //inicia comunicacion con lcd y lo configura
delay_ms(500);
lcd_gotoxy(3,1);                       //escribe el mensaje en la posicion x=3,y=1
printf(lcd_putc,"  Electiva I");           //escribe el mensaje en la pantalla
DELAY_MS(500);
printf(lcd_putc,"\f");

while(true)
   {  
      lcd_gotoxy(3,1);                       //escribe el mensaje en la posicion x=3,y=1
      printf(lcd_putc,"Revolucion!!"); 
   }
}                                      




