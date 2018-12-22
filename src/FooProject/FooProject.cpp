#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Found This value after scanning
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
	lcd.init();
	lcd.backlight();
  	lcd.setCursor(0, 0); // set the cursor to column 3, line 0
  
	lcd.print("HELLO WORLD");
	delay(1000);

}

void loop() {
	//lcd.print("HELLO WORLD");

}

