#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sound_pin = A0;
int red_pin = 11;
int green_pin = 6;
int yellow_pin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
  pinMode(yellow_pin,OUTPUT);
  
  lcd.begin();
  lcd.backlight();
  
}

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value,0,1023,0,255);

  if(light_value > 200){
    count++;
  }
  
  Serial.print("sound value : ");
  Serial.println(sound_value);
  Serial.print("light value : ");
  Serial.println(light_value);
  Serial.print("count : ");
  Serial.println(count);

  analogWrite(green_pin,255);

//  if(count >= 0 && count < 5) {
//    analogWrite(green_pin,255);  
//  }
//  else if(count >= 5 && count < 10){
//    analogWrite(yellow_pin,255);  
//  }
//  else if(count >=10 && count < 20){
//    analogWrite(red_pin,255);  
//  }

  lcd.clear();
  lcd.setCursor(count,0);
  lcd.print("@(^o^)@");
  if(count>9){
    count = 0;
  }
  delay(100);
}
