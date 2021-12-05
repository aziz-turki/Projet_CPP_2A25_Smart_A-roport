//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
char data;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
}


void loop()
{
if (Serial.available()){
  data=Serial.read();
  if(data=='1')
  {
    lcd.init();
    lcd.print("    Welcome");  
    delay(1000);
    lcd.init();

  }else if(data=='0')
  {
    lcd.init();
    lcd.print("   Error!!!!");
    lcd.setCursor(0,1);
    lcd.print("   Try Again ");
    delay(1000);
    lcd.init();
  }
}
}
