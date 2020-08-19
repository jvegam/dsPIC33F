/* 
 * File:   GPIO.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Program that configure the PORTB as digital and generate
 * a blink in the PORTB[7..0] each 500 ms.
 *  
 * Compiler: XC16 V1.5
 *
 * Version: v0.1
 * Initial release.
 *
 * Date:	1308220
 * Created on 13 de August de 2020, 06:51 PM
 */
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <libpic30.h>


int main(int argc, char** argv) {

    SystemClock_Config();
    
    AD1PCFGL = 0x1FFF;			// All the PORTB as digital
    TRISB  = 0x1F00;			// PORTB[7..0] as digital out
    LATB   = 0x0000;			// Initial Value PORTB[7..0] = 0 
    
    while(1){       
       LATB=0x81;
       __delay_ms(500);
       LATB=0x42;
       __delay_ms(500);
       LATB=0x24;
       __delay_ms(500);
       LATB=0x18;
       __delay_ms(500);
       LATB=0x24;
       __delay_ms(500);
       LATB=0x42;
       __delay_ms(500);
    }
    
    return (EXIT_SUCCESS);
}

