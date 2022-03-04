#include <16f877a.h>
#use delay(clock=4000000)
#fuses xt,nowdt


void main()
{
 SET_TRIS_A(0x0f);
 SET_TRIS_D(0XC0);
 while(true)
 {
   while(input(pin_d6)==1)
   {
     output_d(0x08);
     delay_ms(1000);
     output_d(0x0c);
     delay_ms(1000);
     output_d(0x04);
     delay_ms(1000);
     output_d(0x06);
     delay_ms(1000);
     output_d(0x02);
     delay_ms(1000);
     output_d(0x03);
     delay_ms(1000);
     output_d(0x01);
     delay_ms(1000);
  }
 }
 
 
}
