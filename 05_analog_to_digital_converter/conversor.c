#include <16F877A.h>
#device adc=8
#use delay (clock=4000000) //frecuencia de operacion
#fuses xt, nowdt  //palabra de configuracion

int valor;
void main()
{
Set_tris_b(0x00);
Setup_adc_ports(AN0);
Setup_adc(adc_clock_div_32);
Set_adc_channel(0);

For(;;)
{
 
Valor=read_adc();
Output_b(valor);
Delay_ms(100);
}
}

