#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); //set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
    lcd.init(); 
    lcd.noDisplay();
    delayMicroseconds(100000);
    lcd.display();
    lcd.blink();
}
void loop()
{
  
}


