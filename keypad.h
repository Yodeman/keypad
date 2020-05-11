#define	XC_HEADER_TEMPLATE_H
#include <xc.h> // include processor files - each processor file is guarded.  
#pragma FOSC = HS
#define _XTAL_FREQ 20000000

int numberPressed;
char characterPressed;
int Scan(){
    numberPressed = 12;
    while(numberPressed == 12)
    {
        __delay_ms(5); 
        PORTB = 0b11101111;
        if (PORTBbits.RB0 == 0)
        {
            __delay_ms(50);             //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB0 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 1;
            return numberPressed;
        }
        
        if (PORTBbits.RB1 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB1 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 4;
            return numberPressed;
        }
        
        if (PORTBbits.RB2 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB2 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 7;
            return numberPressed;
        }
        
        if (PORTBbits.RB3 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB3 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            characterPressed = '*';
            return characterPressed;
        }
        
        __delay_ms(5);        
        PORTB = 0b11011111;
        
        if (PORTBbits.RB0 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB0 == 0); //wait 0.1s for switch bounce to stop
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 2;
            return numberPressed;
        }
        
        if (PORTBbits.RB1 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB1 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 5;
            return numberPressed;
        }
        
        if (PORTBbits.RB2 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB2 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 8;
            return numberPressed;
        }
        
        if (PORTBbits.RB3 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB3 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 0;
            return numberPressed;
        }
       
        __delay_ms(5); 
        PORTB = 0b10111111;
        if (PORTBbits.RB0 == 0)
        {   __delay_ms(50);             //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB0 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 3;
            return numberPressed;
        }
        
        if (PORTBbits.RB1 == 0)
        {
            __delay_ms(50);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB1 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 6;
            return numberPressed;
        }
        
        if (PORTBbits.RB2 == 0)
        {
            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB2 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            numberPressed = 9;
            return numberPressed;
        }
        
        if (PORTBbits.RB3 == 0)
        {
            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            while(PORTBbits.RB3 == 0);  //wait until switch has been released
//            __delay_ms(100);            //wait 0.1s for switch bounce to stop
            characterPressed = '#';
            return characterPressed;
        }

    }
}