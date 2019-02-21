#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <pins_arduino.h>
#include "gues_driver.h"
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 7

#define RED 1
#define GREEN 2
#define BROWN 3
#define BLUE 4
#define PURPLE 5
#define CYAN 6
#define WHITE 7

#define CONNECTED_PIN 3 //Interrupt Pin
#define MAX_VOLTAGE_READING 5 //Max Voltage 
#define INTERRUPT_PIN INT5 //check if catridge is pulled out
#define WRITE_PROTECT 3

#define DISK1 0x50 //Address of 24LC256 EEPROM chip
#define MAX_SAVE_SIZE 16
#define MAX_NAME_SIZE 10
#define EEPROM_address 0

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16x2 display

volatile byte CARTRIDGE_INTERRUPT = LOW;
int C_LOOP = 0;
int device_num = 0; 
byte address = 0;
byte error = 0;
char buf[MAX_SAVE_SIZE] = {0};
char pedal_name[MAX_NAME_SIZE] = {0};
char cstr[10] = "INSERT";

void setup() 
{
	//Serial.begin(9600);
	Wire.begin(); //enables pullup resistors in SDA/SCL
	lcd.init();
	lcd.backlight();
	lcd.setBacklight(255);
	lcd.setCursor(0, 0); // set the cursor to column 3, line 0
	//{A2, A1, A0} == 000 (for now)
	//EEPROM ADDRESS = {1010, A2, A1, A0} = 0x50
	for(int i = 0; i < 3; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	//EEPROM has 0-32,767 addresses,
	//we start with 0
	//String that is sent to the EEPROM, must be less than 
	//64 characters
	/*
	   char* PEDAL_DATA= (char*)("FUZZ/2/RED");
	   writeEEPROM(DISK1, address, PEDAL_DATA);

	//PIN 3 is WP, so after writing data, set if off.
	*/
	pinMode(WRITE_PROTECT,OUTPUT);
	digitalWrite(WRITE_PROTECT,HIGH);

	readEEPROM(DISK1, EEPROM_address, (char*)buf, 10);
	get_pedal_name(buf, pedal_name);

	lcd.print((char*)pedal_name);
	delay(300);
	pinMode(RED_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	set_lcd_color(RED);
	//ATTACH INTERRUPT
	pinMode(INTERRUPT_PIN, INPUT_PULLUP);
	attachInterrupt(INTERRUPT_PIN, hot_swap, CHANGE);
}

void loop() 
{
	if(CARTRIDGE_INTERRUPT == HIGH) {
		if(C_LOOP == 0){
			device_num = get_num_devices();
			if(device_num == 1) {
				set_lcd_color(WHITE);
				C_LOOP = 1;
				lcd.clear();
				delay(100);
				lcd.print(cstr);
				delay(100);
				C_LOOP = 1;
				digitalWrite(WRITE_PROTECT, LOW);
			}
		}
	} else if(CARTRIDGE_INTERRUPT == LOW){
		if(C_LOOP == 1) {
			device_num = get_num_devices();
			if(device_num == 2) {
				for(int i = 0; i < MAX_SAVE_SIZE; i++) {
					buf[i] = 0;
				}
				for(int i = 0; i < MAX_NAME_SIZE; i++) {
					pedal_name[i] = 0;
				}
				readEEPROM(DISK1, EEPROM_address, (char*)buf, MAX_NAME_SIZE);
				get_pedal_name(buf, pedal_name);
				lcd.clear();
				delay(100);
				set_lcd_color(RED);
				lcd.print(pedal_name);
				delay(100);
				C_LOOP = 0;
				digitalWrite(WRITE_PROTECT, HIGH);
			}
		}
	}
}

void writeEEPROM(int deviceaddress, unsigned int eeaddress, 
		char* data ) 
{
	Wire.beginTransmission(deviceaddress);
	Wire.write((int)(eeaddress >> 8));   // MSB
	Wire.write((int)(eeaddress & 0xFF)); // LSB
	unsigned char i = 0;
	do{
		Wire.write((byte) data[i]);
		i++;
	} while(data[i]);
	Wire.endTransmission();

	delay(6);
}

void readEEPROM(int deviceaddress, unsigned int eeaddress,
		char* data, unsigned int num_chars) 
{
	unsigned char i = 0;
	Wire.beginTransmission(deviceaddress);
	Wire.write((int)(eeaddress >> 8));   // MSB
	Wire.write((int)(eeaddress & 0xFF)); // LSB
	Wire.endTransmission();

	Wire.requestFrom(deviceaddress,num_chars);

	while(Wire.available()) data[i++] = Wire.read();
}

void set_lcd_color(unsigned int color)
{
	if(color>=1 && color<8){
		digitalWrite(RED_PIN, (((color & 1) == 1) ? HIGH:LOW));
		digitalWrite(GREEN_PIN, (((color & 2) == 2) ? HIGH:LOW));
		digitalWrite(BLUE_PIN, (((color & 4) == 4) ?  HIGH:LOW));
		delay(100);
	}
	return;
}

void hot_swap()
{
	CARTRIDGE_INTERRUPT = (CARTRIDGE_INTERRUPT == 1) ? 0: 1;
	//RESET I2C PROTOCOL
	TWCR = 0;
	//CARTRIDGE_INTERRUPT = HIGH;
}

void get_pedal_name(char* INFO, char* NAME)
{
	for(int i = 0; i < MAX_SAVE_SIZE; i++)
	{
		if(INFO[i] == '/')
		{
			return;
		}
		NAME[i] = INFO[i];
	}
	return;
}

int get_num_devices()
{
	Wire.begin(); //enables pullup resistors in SDA/SCL
	int num = 0;
	for(int address = 0; address < 127; address++) {
		Wire.beginTransmission(address);
		error = Wire.endTransmission(); 
		if(error == 0) {
			num++;
		}
	}
	return num;
}
