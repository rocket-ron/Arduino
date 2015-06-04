/*
** Example Arduino sketch for SainSmart I2C LCD2004 adapter for HD44780 LCD screens
** Readily found on eBay or http://www.sainsmart.com/ 
** The LCD2004 module appears to be identical to one marketed by YwRobot
**
** Address pins 0,1 & 2 are all permenantly tied high so the address is fixed at 0x27
**
** Written for and tested with Arduino 1.0
** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal 
**
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)
**
** NOTE: TEsted on Arduino NANO whose I2C pins are A4==SDA, A5==SCL
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

byte myChar1[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte myChar2[8] =
{
  B00000,
  B00000,  
  B00000,  
  B00000,  
  B00000,  
  B00000,
  B11111,
  B11111
};

byte myChar3[8] =
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

byte myChar4[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte myChar5[8] =
{
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte myChar6[8] =
{
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte myChar7[8] =
{
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte myChar8[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.clear();

  
  lcd.begin (20,4);

  lcd.createChar(0, myChar1);
  lcd.createChar(1, myChar2);
  lcd.createChar(2, myChar3);
  lcd.createChar(3, myChar4);
  lcd.createChar(4, myChar5);
  lcd.createChar(5, myChar6);
  lcd.createChar(6, myChar7);
  lcd.createChar(7, myChar8);
  
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                   // go home

}

void loop()
{
  for (byte k=4; k > 0; --k) {

    for (byte i=0; i<8; i++) {
      lcd.setCursor(0,k-1);
      lcd.write(i);
      delay(100);
    }

  }
  for (byte k=0; k < 4; k++) {
    
    for (int i=7; i >= 0; i--) {
      lcd.setCursor(0,k);
      lcd.write(i);
      delay(100);
    }
    lcd.setCursor(0,k);
    lcd.print(' ');
  }
  delay(100);
}
