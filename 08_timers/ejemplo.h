#include <16F877A.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES XT                    	//Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES PUT                   	//Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NODEBUG               	//No Debug mode for ICD
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                 	//No EE protection
#FUSES NOWRT                 	//Program memory not write protected
#FUSES RESERVED              	//Used to set the reserved FUSE bits

#use delay(clock=4000000)
#define BTTON1   PIN_C0
#define LED1   PIN_D0
#define LED2   PIN_D1

