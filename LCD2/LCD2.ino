#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  Serial.println(light);

  lcd.clear();
  lcd.print("Light value : ");
  lcd.setCursor(0,1);
  lcd.print(light);

//  lcd.scrollDisplayRight();
  delay(1000);
}
