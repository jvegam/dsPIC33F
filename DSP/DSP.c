/* 
 * File:   DSP.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * 
 *  
 * Compiler: XC16 V1.5
 *
 * Version: v0.1
 * Initial release.
 *
 * Date:	13082020
 * Created on 13 de August de 2020, 06:51 PM
 */
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <libpic30.h>
 
int MotorDSP_Init(void);
int ACCA_SetValue(int );
int ACCB_SetValue(int );

int main(int argc, char** argv) {

    SystemClock_Config();
    
    MotorDSP_Init();
    ACCA_SetValue(0x7FFF);
    ACCB_SetValue(0xA000);
    
    while(1){       
    }
    return (EXIT_SUCCESS);
}

