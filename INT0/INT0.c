/* 
 * File:   INT0.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Program that count pulses from RB7 pin to the INT0 interrupt
 *  
 * Compiler: XC16 V1.5
 *
 * Version: v0.1
 * Initial release.
 *
 * Date:	13082020
 * Created on 13 de August 2020, 06:51 PM
 */
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <libpic30.h>
 
void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt(void);
void INT0_init(void);

int main(int argc, char** argv) {

    SystemClock_Config();
    
    AD1PCFGL = 0x1FFF;			// All the PORTB as digital
    TRISB  = 0x1F80;			// PORTB[6..0] as digital out
    LATB   = 0x0000;			// Initial Value PORTB[7..0] = 0 
    
    INT0_init();
    
    while(1){       
    }
    
    return (EXIT_SUCCESS);
}

void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt(void)
{
    LATB=LATB+1;
    IFS0bits.INT0IF = 0;
}

void INT0_init(void){
    
    TRISBbits.TRISB7=1;     //RB7 as Digital Input
    INTCON2bits.INT0EP=0;
    IFS0bits.INT0IF = 0;
    IPC0bits.INT0IP = 7;
    IEC0bits.INT0IE = 7;        
}