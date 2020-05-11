/* 
 * File: LCD library   
 * Author: Pauli
 * Comments: I wrote this library with the help of PIC project and application using C book.
 * Revision history: 
 */
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#pragma FOSC = HS
#define _XTAL_FREQ 20000000
#define CLEAR_SCREEN    0b00000001
#define FOUR_BIT        0b00101100
#define LINES_5x7       0b00111000
#define CURSOR_BLINK    0b00001111
#define CURSOR_RIGHT    0b00000110
#define DATA_PORT       PORTD
#define RS_PIN          PORTDbits.RD6
#define E_PIN           PORTDbits.RD7

void delay(){
    __delay_ms(30);
}

void WriteCmd(unsigned char cmd){       //used to send command to LCD
    //higher Nibble interface
    DATA_PORT &= 0xf0;
    DATA_PORT |= (cmd >> 4) & 0x0f;
    RS_PIN = 0; //set control bit for command
    delay();
    E_PIN = 1;  // clock command into display
    delay();
    E_PIN = 0;
    
    // lower Nibble interface
    DATA_PORT &= 0xf0;
    DATA_PORT |= cmd & 0x0f;
    delay();
    E_PIN = 1;
    delay();
    E_PIN = 0;
}

void Set_Cursor(unsigned char r){     // used to set character address for the LCD, r = row
    unsigned char Temp;
    if (r == 1){
        Temp = 0x80;    // 0x80 is used to move the cursor up
        WriteCmd(Temp);
    }
    if (r == 2){
        Temp = 0xC0;
        WriteCmd(Temp);
    }
}

void WriteChar(char data){
    //higher Nibble interface
    DATA_PORT &= 0xf0;
    DATA_PORT |= ((data >> 4) & 0x0f);
    RS_PIN = 1;  // set character bit
    delay();
    E_PIN = 1;  // clock the character into the display
    delay();
    E_PIN = 0;
    
    //lower Nibble interface
    DATA_PORT &= 0xf0;
    DATA_PORT |= (data & 0x0f);
    delay();
    E_PIN = 1;  //clock character into the display
    delay();
    E_PIN = 0;
}

void WriteString(char *buffer){
    while(*buffer){
        delay();
        WriteChar(*buffer);
        buffer++;
    }
    return;
}

void Display_Right(){
    WriteCmd(0x1c);
}

void Display_Left(){
    WriteCmd(0x18);
}

void Cursor_Left(){
    WriteCmd(0x10);
}

void Cursor_Right(){
    WriteCmd(0x14);
}

void Clear_Screen(){
    WriteCmd(CLEAR_SCREEN);
}
void Config_Display(){
    //configure display
    WriteCmd(0x02);  //sets 4 bit operation
    WriteCmd(FOUR_BIT & LINES_5x7); //sets 5x7 font and multi-line operation
    WriteCmd(CURSOR_BLINK); //blinks Cursor
    WriteCmd(CURSOR_RIGHT); // moves cursor right
}