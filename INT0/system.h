/* 
 * File:   system.h
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Defines FCY and SystemClock_Config Function configuration.  
 *  
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	13082020
 * Created on 13 de August de 2020, 06:51 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H


#define FCY 40000000UL			//Value Required by library "libpic30.c".
void SystemClock_Config(void);


#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

