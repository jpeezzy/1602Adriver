sudo apt install curl arduino
curl https://raw.githubusercontent.com/johnrickman/LiquidCrystal_I2C/master/LiquidCrystal_I2C.cpp --output LiquidCrystal_I2C.cpp
curl https://raw.githubusercontent.com/johnrickman/LiquidCrystal_I2C/master/LiquidCrystal_I2C.h --output LiquidCrystal_I2C.h
sudo mkdir /usr/share/arduino/libraries/LiquidCrystal_I2C/
sudo mv LiquidCrystal_I2C.cpp /usr/share/arduino/libraries/LiquidCrystal_I2C/
sudo mv LiquidCrystal_I2C.h /usr/share/arduino/libraries/LiquidCrystal_I2C/
