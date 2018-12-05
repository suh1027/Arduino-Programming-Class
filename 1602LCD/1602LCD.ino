#include <LiquidCrystal_I2C.h>
#include<Wire.h>


LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, world!");
  lcd.cursor();
  lcd.setCursor(2,2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
