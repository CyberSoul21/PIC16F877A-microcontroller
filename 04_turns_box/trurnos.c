#include <16F877A.h>
#use delay (clock=4000000) //frecuencia de operacion
#fuses xt, nowdt  //palabra de configuracion

int unidades[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x83,0xf8,0x80,0x98};
int decenas[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x83,0xf8,0x80,0x98};

int un, dec;

void main()
{

SET_TRIS_A(0XFF); // Puerto A como entradas
SET_TRIS_B( 0x00);// PUERTO B COMO SALIDAS
SET_TRIS_C( 0x00);// PUERTO C COMO SALIDAS
SET_TRIS_D( 0x00);// PUERTO D COMO SALIDAS
un = 0;
dec = 0;
output_b(unidades[un]);
output_c(decenas[dec]);
output_d(unidades[un]);

   while(true)
   {
       if(input(pin_a0)==1)
       {
       
       un++;
          if(un>9)
          {
           un = 0;
           dec++
          }
           output_C(unidades[un]);
           output_D(decenas[dec]);
           delay_ms(1000);
           output_B(unidades[0x01])
       }
       if(input(pin_a1)==1)
       {
        un++;
          if(un>9)
          {
           un = 0;
           dec++
          }
           output_C(unidades[un]);
           output_D(decenas[dec]);
           delay_ms(1000);
           output_B(unidades[0x02])
       
       }
       if(input(pin_a2)==1)
       {
       un++;
          if(un>9)
          {
           un = 0;
           dec++
          }
           output_C(unidades[un]);
           output_D(decenas[dec]);
           delay_ms(1000);
           output_B(unidades[0x03])
       }
       if(input(pin_a3)==1)
       {
       un++;
          if(un>9)
          {
           un = 0;
           dec++
          }
           output_C(unidades[un]);
           output_D(decenas[dec]);
           delay_ms(1000);
           output_B(unidades[0x04])
       }
   }
}
   




