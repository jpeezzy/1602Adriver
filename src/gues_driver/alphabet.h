/*
A set of custom made large numbers for a 16x2 LCD using the 
 LiquidCrystal librabry. Works with displays compatible with the 
 Hitachi HD44780 driver. 
 
 The Cuicuit:
 LCD RS pin to D7
 LCD Enable pin to D6
 LCD D4 pin to D5
 LCD D5 pin to D4
 LCD D6 pin to D3
 LCD D7 pin to D2
 LCD Vee tied to a pot to control brightness
 LCD Vss and R/W tied to ground
 LCD Vcc to +5V
 LCD pin 15 tied to pushbutton for control of backlight
 
 Made by Michael Pilcher
 2/9/2010
 */

// include the library

// the 8 arrays that form each segment of the custom numbers
#ifndef ALPHABET_H
#define ALPHABET_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


void setup_big_char(LiquidCrystal_I2C *lcd);
void custom0O(LiquidCrystal_I2C *lcd, int x);
void custom1(LiquidCrystal_I2C *lcd, int x);
void custom2(LiquidCrystal_I2C *lcd, int x);
void custom3(LiquidCrystal_I2C *lcd, int x);
void custom4(LiquidCrystal_I2C *lcd, int x);
void custom5(LiquidCrystal_I2C *lcd, int x);
void custom6(LiquidCrystal_I2C *lcd, int x);
void custom7(LiquidCrystal_I2C *lcd, int x);
void custom8(LiquidCrystal_I2C *lcd, int x);
void custom9(LiquidCrystal_I2C *lcd, int x);
void customA(LiquidCrystal_I2C *lcd, int x);
void customB(LiquidCrystal_I2C *lcd, int x);
void customC(LiquidCrystal_I2C *lcd, int x);
void customD(LiquidCrystal_I2C *lcd, int x);
void customE(LiquidCrystal_I2C *lcd, int x);
void customF(LiquidCrystal_I2C *lcd, int x);
void customG(LiquidCrystal_I2C *lcd, int x);
void customH(LiquidCrystal_I2C *lcd, int x);
void customI(LiquidCrystal_I2C *lcd, int x);
void customJ(LiquidCrystal_I2C *lcd, int x);
void customK(LiquidCrystal_I2C *lcd, int x);
void customL(LiquidCrystal_I2C *lcd, int x);
void customM(LiquidCrystal_I2C *lcd, int x);
void customN(LiquidCrystal_I2C *lcd, int x);
void customP(LiquidCrystal_I2C *lcd, int x);
void customQ(LiquidCrystal_I2C *lcd, int x);
void customR(LiquidCrystal_I2C *lcd, int x);
void customS(LiquidCrystal_I2C *lcd, int x);
void customT(LiquidCrystal_I2C *lcd, int x);
void customU(LiquidCrystal_I2C *lcd, int x);
void customV(LiquidCrystal_I2C *lcd, int x);
void customW(LiquidCrystal_I2C *lcd, int x);
void customX(LiquidCrystal_I2C *lcd, int x);
void customY(LiquidCrystal_I2C *lcd, int x);
void customZ(LiquidCrystal_I2C *lcd, int x);
void customqm(LiquidCrystal_I2C *lcd, int x);
void customsm(LiquidCrystal_I2C *lcd, int x);


#endif




