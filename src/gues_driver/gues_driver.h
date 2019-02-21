#ifndef GUES_DRIVER
#define GUES_DRIVER
#include <Arduino.h>

void set_lcd_color(unsigned int COLOR);

void writeEEPROM(int deviceaddress, unsigned int eeaddress, 
		char* data );

void readEEPROM(int deviceaddress, unsigned int eeaddress,
		char* data, unsigned int num_chars);

void setup_gues_info(char* version, char* name, char* pot_names, char* pot_function); //setups the gues

void power_off(); // saves the state of the pots 

void hot_swap(); //allows for hot swapping game catridges: requirements- must use arduino mega 
void get_pedal_name(char* INFO, char* NAME);

int get_num_devices();

void print_insert(); //prints out insert in big letters to LCD

#endif
