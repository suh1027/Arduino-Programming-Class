#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


int red_pin = 13;
int yellow_pin = 12;
int detectpin = A0;
int sum = 0;
int count = 0;
int avg = 0;
  

void setup() {
  // put your setup code here, to run once:
  lcd.begin();

  lcd.backlight();
  
  pinMode(red_pin,OUTPUT);
  pinMode(yellow_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int alcohol = analogRead(detectpin);
  int result = map(alcohol,0,1023,0,255);
  count ++;
  sum = sum + alcohol;

  if(count%10 == 0){
      avg =sum / 10;
      sum = 0;
      Serial.println("~~~~~~~~~~~~~~~~~~~~~");
      Serial.print("avg : ");
      Serial.println(avg);
  }

//알콜 분해 시간체크 시간당 0.8 => 80
  double result2 = avg/80;
  lcd.clear();
  lcd.print("avg time(hour)");
  lcd.setCursor(0,1);
  lcd.print(result2);
  
// 음주운전 체크
//  if(avg >= 700){
//    lcd.clear();
//    lcd.print("License Canceled");
//  }
//  else if(avg >= 500 && avg <=700){
//    lcd.clear();
//    lcd.print("License Stop");
//  }
//  else{
//    lcd.clear();
//    lcd.print("Warning");
//  }


  
  if(alcohol<=300){
    analogWrite(yellow_pin,255);
    analogWrite(red_pin,0);
  }
  else{
    analogWrite(yellow_pin,(255-result)/20);
    analogWrite(red_pin,result);
  }

  Serial.println("~~~~~~~~~~~~~~~~~~~~~");
  Serial.print(count);
  Serial.println("~~~~~~~~~~~~~~~~~~~~~");
  Serial.print("alcohol : ");
  Serial.println(result);
  Serial.print("raw data : ");
  Serial.println(alcohol);
  delay(1000);
}
