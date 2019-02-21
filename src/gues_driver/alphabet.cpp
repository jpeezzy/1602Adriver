#include "alphabet.h"

byte LT[8] = 
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte LL[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};
byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};
byte UMB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte LMB[8] =
{
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

void setup_big_char(LiquidCrystal_I2C *lcd)
{
	lcd->createChar(8,LT);
	lcd->createChar(1,UB);
	lcd->createChar(2,RT);
	lcd->createChar(3,LL);
	lcd->createChar(4,LB);
	lcd->createChar(5,LR);
	lcd->createChar(6,UMB);
	lcd->createChar(7,LMB);
}
void custom0O(LiquidCrystal_I2C *lcd, int x)
{ // uses segments to build the number 0
  lcd->setCursor(x, 0); 
  lcd->write(8);  
  lcd->write(1); 
  lcd->write(2);
  lcd->setCursor(x, 1); 
  lcd->write(3);  
  lcd->write(4);  
  lcd->write(5);
}

void custom1(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(2);
  lcd->setCursor(x+1,1);
  lcd->write(255);
}

void custom2(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(6);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(3);
  lcd->write(7);
  lcd->write(7);
}

void custom3(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(6);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(7);
  lcd->write(7);
  lcd->write(5); 
}

void custom4(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(3);
  lcd->write(4);
  lcd->write(2);
  lcd->setCursor(x+2, 1);
  lcd->write(255);
}

void custom5(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(6);
  lcd->setCursor(x, 1);
  lcd->write(7);
  lcd->write(7);
  lcd->write(5);
}

void custom6(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(6);
  lcd->write(6);
  lcd->setCursor(x, 1);
  lcd->write(3);
  lcd->write(7);
  lcd->write(5);
}

void custom7(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(1);
  lcd->write(2);
  lcd->setCursor(x+1, 1);
  lcd->write(8);
}

void custom8(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(3);
  lcd->write(7);
  lcd->write(5);
}

void custom9(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x+2, 1);
  lcd->write(255);
}

void customA(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(255);
}

void customB(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(5);
  lcd->setCursor(x, 1);
  lcd->write(255);
  lcd->write(7);
  lcd->write(2);
}

void customC(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(1);
  lcd->write(1);
  lcd->setCursor(x,1);
  lcd->write(3);
  lcd->write(4);
  lcd->write(4);
}

void customD(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x, 0); 
  lcd->write(255);  
  lcd->write(1); 
  lcd->write(2);
  lcd->setCursor(x, 1); 
  lcd->write(255);  
  lcd->write(4);  
  lcd->write(5);
}

void customE(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(6);
  lcd->setCursor(x, 1);
  lcd->write(255);
  lcd->write(7);
  lcd->write(7); 
}

void customF(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(6);
  lcd->setCursor(x, 1);
  lcd->write(255);
}

void customG(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(1);
  lcd->write(1);
  lcd->setCursor(x,1);
  lcd->write(3);
  lcd->write(4);
  lcd->write(2);
}

void customH(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(4);
  lcd->write(255);
  lcd->setCursor(x, 1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(255); 
}

void customI(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(255);
  lcd->write(1);
  lcd->setCursor(x,1);
  lcd->write(4);
  lcd->write(255);
  lcd->write(4);
}

void customJ(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x+2,0);
  lcd->write(255);
  lcd->setCursor(x,1);
  lcd->write(4);
  lcd->write(4);
  lcd->write(5);
}

void customK(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(4);
  lcd->write(5);
  lcd->setCursor(x,1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(2); 
}

void customL(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->setCursor(x,1);
  lcd->write(255);
  lcd->write(4);
  lcd->write(4);
}

void customM(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(3);
  lcd->write(5);
  lcd->write(2);
  lcd->setCursor(x,1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(254);
  lcd->write(255);
}

void customN(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(2);
  lcd->write(254);
  lcd->write(255);
  lcd->setCursor(x,1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(3);
  lcd->write(5);
}

void customP(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(255);
}

void customQ(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(1);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(3);
  lcd->write(4);
  lcd->write(255);
  lcd->write(4);
}

void customR(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x,1);
  lcd->write(255);
  lcd->write(254);
  lcd->write(2); 
}

void customS(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(8);
  lcd->write(6);
  lcd->write(6);
  lcd->setCursor(x, 1);
  lcd->write(7);
  lcd->write(7);
  lcd->write(5);
}

void customT(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(255);
  lcd->write(1);
  lcd->setCursor(x,1);
  lcd->write(254);
  lcd->write(255);
}

void customU(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x, 0); 
  lcd->write(255);  
  lcd->write(254); 
  lcd->write(255);
  lcd->setCursor(x, 1); 
  lcd->write(3);  
  lcd->write(4);  
  lcd->write(5);
}

void customV(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x, 0); 
  lcd->write(3);  
  lcd->write(254);
  lcd->write(254); 
  lcd->write(5);
  lcd->setCursor(x+1, 1); 
  lcd->write(2);  
  lcd->write(8);
}

void customW(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->write(254);
  lcd->write(254);
  lcd->write(255);
  lcd->setCursor(x,1);
  lcd->write(3);
  lcd->write(8);
  lcd->write(2);
  lcd->write(5);
}

void customX(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(3);
  lcd->write(4);
  lcd->write(5);
  lcd->setCursor(x,1);
  lcd->write(8);
  lcd->write(254);
  lcd->write(2); 
}

void customY(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(3);
  lcd->write(4);
  lcd->write(5);
  lcd->setCursor(x+1,1);
  lcd->write(255);
}

void customZ(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(6);
  lcd->write(5);
  lcd->setCursor(x, 1);
  lcd->write(8);
  lcd->write(7);
  lcd->write(4);
}

void customqm(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(1);
  lcd->write(6);
  lcd->write(2);
  lcd->setCursor(x, 1);
  lcd->write(254);
  lcd->write(7);
}

void customsm(LiquidCrystal_I2C *lcd, int x)
{
  lcd->setCursor(x,0);
  lcd->write(255);
  lcd->setCursor(x, 1);
  lcd->write(7);
}

