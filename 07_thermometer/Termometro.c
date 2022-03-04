#include <16f877A.h>
#device adc=8 //10
#use delay(clock=4000000)
#fuses xt,nowdt
#include <lcd3.c>
#include <math.h>
int value; //int16 para guardar resultado de 10bits
float volt,c;
void main()
{
 set_tris_d(0x00);
 lcd_init(); 
 lcd_enviar(lcd_comando,lcd_home);//cursor a casa  
 lcd_gotoxy(4,1);
 printf(lcd_putc,"Termometro");//Mensaje
 lcd_gotoxy(5,2); 
 printf(lcd_putc,"Digital");
 delay_ms(800);
 lcd_enviar(lcd_comando,lcd_clear); 
 SETUP_ADC_PORTS(AN0_AN1_AN3);
 setup_adc(ADC_CLOCK_DIV_32);
 set_adc_channel( 0 ); 
 while(true)
 {
   value=read_adc();
   volt=value*0.0196;
   delay_ms(30);
   c = volt*100;
   lcd_gotoxy(1,1);                       
   printf(lcd_putc,"Temperatura:%f",c);
   if(c>=32)
   {
      output_high(Pin_d2);
      lcd_gotoxy(1,2);                       
      printf(lcd_putc,"Ventilador ON");           
   }
   if(c<32)
   {
      output_low(pin_d2);
      lcd_gotoxy(1,2);                       
      printf(lcd_putc,"Ventilador Off");           
   }
 }
}
