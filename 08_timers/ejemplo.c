#include "C:\Users\USER\Archivos\Wilson\Microcontroladores\PROYECTOS\timers\ejemplo.h"
#int_TIMER1





void  TIMER1_isr(void) 
{
   
  output_toggle(LED1);
  //delay_ms(1000);
  set_timer1(3036);
}

void main()
{
   delay_ms(1000);
   
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   
   set_timer1(3036);
   // TODO: USER CODE!!
   //delay_ms(1000);
   SET_TRIS_C(0xFF);
   SET_TRIS_D(0x00);
   output_c(0x01);
   while(true)
   {
     
     if(input(BTTON1)==1)
     {
     //while(input(BTTON1)==1)
       //{
        //delay_ms(100);
       //}
     output_toggle(LED2);
     delay_ms(500);
     }
   }

}
