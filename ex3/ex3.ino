#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int trig = 2;
int echo = 3;
int whiteBtn = 8;
int yellowBtn = 9;


LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  pinMode(whiteBtn,INPUT);
  pinMode(yellowBtn,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  
  int whiteValue = digitalRead(8);
  int yellowValue = digitalRead(9);

  //조도센서

  int light = analogRead(A0);


//거리측정

  int duration = pulseIn(3,HIGH);
  int distance = duration/58.2;


//LCD 출력
  if(whiteValue == HIGH){
    lcd.clear();
    lcd.print("Distance : ");
    lcd.print(distance);
    delay(1000);
  }
  else if(yellowValue == HIGH){
    lcd.clear();
    lcd.print("Light : ");
    lcd.print(light);
    delay(1000);
  }
  else{
    lcd.clear();
    lcd.print("Light(Yellow)");
    lcd.setCursor(0,1);
    lcd.print("Distance(White)");
    delay(1000);     
  }
  
//Serial 값 확인
  Serial.println(light);
  Serial.println(distance);

}
