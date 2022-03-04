list p=16F877A          ; SE DEFINE EL MICRO A UTILIZAR
#INCLUDE <P16F877A.INC> ; NOS PERMITE TRABAJAR LOS REGISTROS DE PROPOSITO ESPECIFICO CON NOMBRES

CONF_ADCON1 equ b'00000110' ; Configuracion PORTA E/S digital
__CONFIG _CP_OFF & _WDT_OFF & _BODEN_OFF & _PWRTE_ON & _XT_OSC & _WRT_OFF & _LVP_OFF & _CPD_OFF
BSF STATUS,5 ;Banco1
BCF STATUS,6
MOVLW   CONF_ADCON1 ; Configurar el PORTA como digital
MOVWF   ADCON1

MOVLW b'00001111' ; El puerto D para las entradas de los "sensores"
MOVWF TRISD
MOVLW b'0000000' ; El puerto B y A para la salida, visualizacion por display y led Zonas
MOVWF TRISB
MOVWF TRISA
MOVWF TRISC


BCF STATUS,5 ; Banco 2
BCF STATUS,6
BCF PORTA,0

MOVLW B'00000000'
CLRF PORTD
CLRF PORTC
CLRF PORTB
INICIO	

         BTFSC PORTD,0
         GOTO PRE1
		 
		 BTFSC PORTD,1 
		 GOTO PRE1
		 BCF  PORTA,0
		 CALL PONER_0
         



ZONA2  BTFSC PORTD,2 
       GOTO  PRE3

	   BTFSC PORTD,3
       GOTO PRE3
       BCF PORTA,1


		
		GOTO INICIO


PRE1 BSF PORTA,0
     BTFSC PORTD,2
     BSF PORTA,1
     BTFSC PORTD,3
     BSF PORTA,1
     MOVF PORTD,W
     MOVWF PORTC
     INCF PORTC
     BTFSC PORTC,4
     CALL PONER_3
     BTFSS PORTC,4
     CALL PONER_1
     GOTO INICIO
     


PRE3 BSF PORTA,1
     BTFSC PORTD,0
     BSF PORTA,0
     BTFSC PORTD,1
     BSF PORTA,0
     MOVF PORTD,W
     MOVWF PORTC
     INCF PORTC
     BTFSC PORTC,4
     CALL PONER_3
     BTFSS PORTC,4
     CALL PONER_2
     GOTO ZONA2
     


PONER_1 MOVLW B'1001111'
        MOVWF PORTB
        RETURN
PONER_0 MOVLW B'0000001'
        MOVWF PORTB
        RETURN
PONER_2 MOVLW B'0010010'
        MOVWF PORTB
        RETURN
PONER_3 MOVLW B'0000110'
        MOVWF PORTB
        RETURN
END
