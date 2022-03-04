#include<16f877a.h>
#use delay(clock=4000000)
#fuses xt,nowdt
#include <lcd2.c>
#include <kbd1.c>
#include <math.h>
int h,x,cont,i,z;
float numero,resultado,numero2;
int vector[20];//Se crea vector para que se almacene cada numero que se digite.
int obtenerNumero(int a);//Cavecera de la funcion
void main()
{
   lcd_init();    //inicicializar el LCD   
   kbd_init();    //inicicializar teclado
   lcd_enviar(lcd_comando,lcd_home);//cursor a casa  
   lcd_gotoxy(4,1);
   printf(lcd_putc,"WILSON J.");//Mensaje
   lcd_gotoxy(3,2); 
   printf(lcd_putc,"CALCULADORA");
   delay_ms(600);
   lcd_enviar(lcd_comando,lcd_clear);
   for(i=0;i<20;i++)//Borra vector para que no coja valores aleatorios
   {
     vector[i]=0;
   }
   while(true)
   {  
      principio://Etiqueta
      z=tecla();           // esta función se queda esperando hasta que se oprima una tecla 
      vector[cont]=(z-48); // Cada vez que se pulsa una tecla la almacena y la vuelve entero
      
      if(z!='=',z!='+',z!='-',z!='x',z!='/',z!='n')
      {
      printf(lcd_putc, "%c",z);//Imprime únicamente numeros en la lcd
      
      }
      switch ( z )//Compara si se introduce un operador
      {
      case '+'://Si es + la coloca h = 1 y obtiene el número del vector
         lcd_enviar(lcd_comando,lcd_clear);
         numero = obtenerNumero(cont );
         h=1;
         for(i=0;i<20;i++)//Limpia vector para la digitación del siguiente número
         {
           vector[i]=0;
         }
         cont =0;
         goto principio;//devuelve al pricipio para que se digite el siguiente
         break;
      case '-'://Si es - la coloca h = 2 y obtiene el número del vector
        lcd_enviar(lcd_comando,lcd_clear);
        numero = obtenerNumero(cont );
        h=2;
        for(i=0;i<20;i++)//Limpia vector para la digitación del siguiente número
         {
           vector[i]=0;
         }
         cont =0;
        goto principio;//Vuelve a la etiqueta principio paraque se digite el siguiente número
         break;
      case 'x'://Si es x la coloca h = 3 y obtiene el número del vector
        lcd_enviar(lcd_comando,lcd_clear);
        numero = obtenerNumero(cont );
        h=3;
        for(i=0;i<20;i++)//Limpia vector para la digitación del siguiente número
         {
           vector[i]=0;
         }
         cont =0;
        goto principio;//Vuelve a la etiqueta principio paraque se digite el siguiente número
        break;
      case '/'://Si es / la coloca h = 4 y obtiene el número del vector
        lcd_enviar(lcd_comando,lcd_clear);
        numero = obtenerNumero(cont );
        h=4;
        for(i=0;i<20;i++)//Limpia vector para la digitación del siguiente número
         {
           vector[i]=0;
         }
         cont =0;
        goto principio;//Vuelve a la etiqueta principio paraque se digite el siguiente número
        break;
      case 'n':
        lcd_enviar(lcd_comando,lcd_clear);
        numero = obtenerNumero(cont );
        h=5;
        for(i=0;i<20;i++)//Limpia vector para la digitación del siguiente número
         {
           vector[i]=0;
         }
         cont =0;
        goto principio;//Vuelve a la etiqueta principio paraque se digite el siguiente número
        break;
      }
      if(z=='=')//si es igual compara la varible h en que valor esta 
      { 
        switch(h)//y obtiene el segundo número
        {
        case 1://si esta en 1 suma
           lcd_enviar(lcd_comando,lcd_clear);
           numero2 = obtenerNumero(cont )-numero;
           resultado = numero+numero2;
           break;
        case 2://si esta en 2 resta
           lcd_enviar(lcd_comando,lcd_clear);
           numero2 = obtenerNumero(cont )-numero;
           resultado = numero-numero2;
           break;
        case 3://si esta en 3 multiplica
           lcd_enviar(lcd_comando,lcd_clear);
           numero2 = obtenerNumero(cont )-numero;
           resultado = numero*numero2;
           break;
        case 4://si esta en 4 divide
           lcd_enviar(lcd_comando,lcd_clear);
           numero2 = obtenerNumero(cont )-numero;
           resultado = numero/numero2;  
           break;
        case 5://si esta en 4 divide
           lcd_enviar(lcd_comando,lcd_clear);
           resultado = sin(numero);
           
           break;     
        }
        lcd_gotoxy(1,1);//imprime el resultado
        printf(lcd_putc, "Resultado =");
        lcd_gotoxy(1,2);
        printf(lcd_putc, "%f",resultado);
        goto principio;//vuelve al principio      
      }
      
      cont++;     
   }
}
int obtenerNumero(int a)//Funcion para que se obtenga el numero entero
{
       int r,sum,num1,num;
       int y=a-1;
       for(x=0;x<a;x++)
       {
        r=vector[x];
        sum =r*(pow(10,y));
        num1+=sum;
        y--;
       }
       if(num1>99)
       {
        num=num1+1;
       }
        else
       {
        num=num1;
       }
       return num;
}

