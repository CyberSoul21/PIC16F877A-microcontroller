list p=16F877A          ; SE DEFINE EL MICRO A UTILIZAR
#INCLUDE <P16F877A.INC> ; NOS PERMITE TRABAJAR LOS REGISTROS DE PROPOSITO ESPECIFICO CON NOMBRES

DATOA equ b'111111'
DATO2 EQU b'11111111'
DATO3 EQU b'00000000'
CONF_ADCON1 equ b'00000110' ; Configuracion PORTA E/S digital


	BSF		STATUS,5	;BANCO 1
	BCF		STATUS,6
	
    MOVLW   CONF_ADCON1 ; Configurar el PORTA como digital
    MOVWF   ADCON1

	CLRF	TRISD       ;PUERTO D COMO SALIDA 
    MOVLW   DATOA
    MOVWF   TRISA       ;PUERTO A COMO ENTRADA
    MOVLW   DATO2     
    MOVWF   TRISB       ;PUERTO B COMO ENTRADA
    BCF     STATUS,5    ; BANCO 0
    BCF     STATUS,6
    WIL:
    MOVLW   DATO3
    MOVF    PORTA,0
    ADDWF   PORTB,0
    MOVWF   PORTD
    GOTO WIL 
    		

END
