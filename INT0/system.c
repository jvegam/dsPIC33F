/* 
 * File:   system.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Program that define the system parameter of the configuration of
 * microcontroller. The program use for default a 8MHz external crystal 
 *   
 *  
 * Compiler: XC16 V1.5
 * 
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170331
 * Created on 13 de August de 2020, 06:51 PM
 */

#include <xc.h>
#include "system.h"

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))
#pragma config IESO = OFF               // Internal External Switch Over Mode (Start-up device with user-selected oscillator source)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Source (XT Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Clock switching is enabled, Fail-Safe Clock Monitor is disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)


/* FRC and then ->  Clock switching to XT w/ PLL
 * XTAL extern = 8MHZ 
 * FCY = 40MIPS
 */ 
void SystemClock_Config(void){
    
    PLLFBD=78;              // M=80
    CLKDIVbits.PLLPOST=1;   // N2=4 
    CLKDIVbits.PLLPRE=0;    // N1=2 
    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(OSCCON | 0x01);     
    while (OSCCONbits.COSC!= 0b011);    // Wait for Clock switch to occur
    while (OSCCONbits.LOCK!= 1);        // Wait for PLL to lock
       
}
