#include <16F877.h> 
//Configuración de los fusibles. 
#FUSES NOWDT, XT
#use delay(clock=4000000) //Frecuencia de reloj 4MHz 
#byte puerto_B = 0x06 // Identificador para el puerto B. 
#byte puerto_D = 0x08 // Identificador para el puerto C. 

#int_RB 
void RB_isr(void) //función de interrupción 
{ 

switch(puerto_B) 
{ 
case 239: 
puerto_D = 0x06; 
break; 
case 223: 
puerto_D = 0x5B; 
break; 
case 191: 
puerto_D = 0x4F; 
break; 
case 127: 
puerto_D = 0x66; 
break; 
default: 

break; 
} 
} 

void main() 
{ 
set_tris_b(0xFF); //Puerto B como entrada 
set_tris_d( 0x00 ); // Puerto D como salida. 

enable_interrupts(INT_RB);//habilita interrupción particular 
enable_interrupts(GLOBAL);//habilita interrupción global 

puerto_D =0x00; //inicializo puerto D 

while(True) 
{ 
//código principal 

} 

}
