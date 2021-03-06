#include <16f877A.h>
#device adc=8 //10
#use delay(clock=4000000)
#fuses xt,nowdt
#include <lcd3.c>
#include <math.h>
int16 value,t=0,t2=0,r=0,k=0,i,i2; //int16 para guardar resultado de 10bits
int p=0;
float volt,c,ac,max,min,prom,max2,min2,prom2,maximo,minimo,promedio,a;
float vector[15];
float vector2[13];
#int_TIMER0
void  TIMER0_isr(void) 
{
 if(t==40)//Cada 2 segundos toma muestra
  {
   output_toggle(pin_d4);
   value=read_adc();
   volt=value*0.0196;
   c = volt*100;
   if(r<=15)
   {
   vector[r]=c;
   }
   if(r>15){
    
    vector2[k]=c;
    k++;
   }
   
   
   r++;
   t=0;
  }
  if(t2==1200)//Cuando pase el minuto
  {
       max = vector[0];
       for (i = 0; i < 15; i++)
       {
        if (max < vector[i])
        {
          max = vector[i];      
        }
       }
       min = vector[0];
       for (i = 0; i < 15; i++)
       {
        if (min > vector[i])
        {
          min = vector[i];     
        }
       }
       prom=0;
       for (i = 0; i < 15; i++)
       {       
        prom += vector[i];
        
       }prom =(prom)/15;
       max2 = vector2[0];
       for (i2 = 0; i2 < 13; i2++)
       {
        if (max2 < vector2[i2])
        {
          max = vector2[i2];      
        }
       }
       min2 = vector2[0];
       for (i2 = 0; i2 < 13; i2++)
       {
        if (min2 > vector2[i2])
        {
          min2 = vector2[i2];     
        }
       }
       prom2=0;
       for (i2 = 0; i2 < 13; i2++)
       {
       prom2 += vector[i2];
        
       }prom2 =(prom2)/13;
       if(max>max2)
       {
         maximo = max;
       }
       if(max<max2)
       {
         maximo = max2;
       }
       if(max==max2)
       {
         maximo = max2;
       }
       if(min>min2)
       {
         minimo = min2;
       }
       if(min<min2)
       {
         minimo = min;
       }
       if(min==min2)
       {
         minimo = min;
       }
       promedio=(prom+prom2)/2;
       ac = vector2[13];
       t2=0;
       for(i=0;i<15;i++)
       {
        vector[i]=0;
       }
       for(i2=0;i2<15;i2++)
       {
        vector2[i2]=0;
       }
       t2=0;
       r=0;
       k=0;
      
  }
  t2++;
  t++;
  set_timer0(61);//Carga valor para conteo
}
void main()
{
 set_tris_d(0x0f);
 lcd_init(); 
 lcd_enviar(lcd_comando,lcd_home);//cursor a casa  
 lcd_gotoxy(4,1);
 printf(lcd_putc,"Termometro");//Mensaje
 lcd_gotoxy(5,2); 
 printf(lcd_putc,"Digital");
 delay_ms(800);
 lcd_enviar(lcd_comando,lcd_clear); 
 lcd_gotoxy(1,1);
 printf(lcd_putc,"Temperatura:");//Mensaje
 SETUP_ADC_PORTS(AN0_AN1_AN3);
 setup_adc(ADC_CLOCK_DIV_32);
 set_adc_channel( 0 ); 
 
 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);//Configura timer0
 enable_interrupts(INT_TIMER0);//Habilita interrupcion por timer0
 enable_interrupts(GLOBAL);//Interrrupciones externas
 set_timer0(61);//Carga valor para conteo
 while(true)
 {
 if(t2<1200)
 {
   value=read_adc();
   volt=value*0.0196;
   a = volt*100;
  lcd_gotoxy(13,1);
  printf(lcd_putc,"%f",a);//Mensaje
 }
  if((input(Pin_d0)==1)) 
  {
    delay_ms(10);
    while((input(pin_d0)==1))
    {
     delay_ms(10);
    }
    p++;
  }
  switch(p)
   {
   case 1: 
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                 ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Ultima:%f",ac);
   P++;
   break;
   case 3:  
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                 ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Maxima:%f",maximo);
   P++;
   break;
   case 5:
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Minima:%f",minimo);
   P++;
   break;
   case 7:
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Promedio:%f",promedio);
   p=0;
   break;
   }
  
   
   
  
 }
}

