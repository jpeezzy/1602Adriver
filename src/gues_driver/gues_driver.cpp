#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <pins_arduino.h>

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

#define CONNECTED_PIN A7 //Interrupt Pin
#define MAX_VOLTAGE_READING 5 //Max Voltage 
#define SWAP_GND 8 //NO CARTRIDGE GND
#define INTERRUPT_PIN INT5 //check if catridge is pulled out

#define DISK1 0x50 //Address of 24LC256 EEPROM chip

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16x2 display
volatile byte CARTRIDGE_INSERTED = HIGH;
int C_LOOP = 0;

void set_lcd_color(unsigned int COLOR);
void writeEEPROM(int deviceaddress, unsigned int eeaddress, 
				 char* data );

void readEEPROM(int deviceaddress, unsigned int eeaddress,
				char* data, unsigned int num_chars);

void setup_gues_info(char* version, char* name, char* pot_names, char* pot_function); //setups the gues

void power_off(); // saves the state of the pots 

void hot_swap(); //allows for hot swapping game catridges: requirements- must use arduino mega 

void setup() 
{
	//Serial.begin(9600);
	Wire.begin(); //enables the pullup resistors in sda scl
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0, 0); // set the cursor to column 3, line 0
	//set eeprom address to 000 (for now)
	//the address is 1010 A2 A1 A0. 
	
	//If A0-A2 is 0, the addresss for the eeprom is 0x50
	for(int i = 0; i < 3; i++)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	//This eeprom has between 0 and 32,767 addresses,
	//we start with 0
	unsigned int address = 0;
	//String that is sent to the EEPROM, must be less than 
	//64 characters
	//char* PEDAL_DATA= (char*)("FUZZ/2/RED");
	//writeEEPROM(DISK1, address, PEDAL_DATA);

	//PIN 3 is WP, so after writing data, set if off.
	digitalWrite(3,HIGH);

	char buf[16] = {0};
	readEEPROM(DISK1, address, (char*)buf, 10);
	lcd.print((char*)buf);
	delay(300);
	pinMode(RED_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	
	set_lcd_color(RED);

	//initialize catridge checker pin 
	//pinMode(CONNECTED_PIN, INPUT);
	//attach interrupt
	//pinMode(INTERRUPT_PIN, INPUT_PULLUP);
	attachInterrupt(INTERRUPT_PIN, hot_swap, LOW);
}

void loop() 
{
	if((CARTRIDGE_INSERTED == 0) && (C_LOOP == 0))
	{
		set_lcd_color(WHITE);
		C_LOOP = 1;
		lcd.clear();
		delay(100);
		char cstr[10] = "INSERT";
		lcd.print(cstr);
		delay(100);
		pinMode(SWAP_GND, OUTPUT);
		digitalWrite(SWAP_GND,LOW);
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
	unsigned int slot_voltage = analogRead(CONNECTED_PIN);
	float voltage = slot_voltage * 5.0/1023.0;
	if(voltage < 1.0)
	{
		CARTRIDGE_INSERTED = LOW;
	}
	else 
	{
		CARTRIDGE_INSERTED = HIGH;
	}
	return;	
}
