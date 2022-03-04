#include <16f877A.h>
#use delay (clock=4000000) 
#fuses xt, nowdt
#include <lcd3.c>

void main()
{
 SET_TRIS_C(0xFF);
 SET_TRIS_D(0x00);
 output_low(PIN_D2);
 
 While(true)
 {
     while(input(pin_c4))
     {
      output_high(PIN_D2);
      delay_ms(0.1);
      output_low(PIN_D2);
      delay_ms(0.1);
     }
     while(input(pin_c5))
     {
      output_high(PIN_D2);
      delay_ms(0.05);
      output_low(PIN_D2);
      delay_ms(0.05);
     }
     while(input(pin_c6))
     {
      output_high(PIN_D2);
      delay_ms(0.025);
      output_low(PIN_D2);
      delay_ms(0.025);
     }
     while(input(pin_c7))
     {
      output_high(PIN_D2);
      delay_ms(0.02);
      output_low(PIN_D2);
      delay_ms(0.02);
     }
   
 }
 
}
