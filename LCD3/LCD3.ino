#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int trig = 2;
int echo = 3;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);


//조도센서

  int light = analogRead(A0);


//거리측정

  int duration = pulseIn(3,HIGH);
  int distance = duration/58.2;

// LCD 출력
  lcd.clear();
  lcd.print("Light : ");
  lcd.print(light);
  lcd.setCursor(0,1);
  lcd.print("Distance : ");
  lcd.print(distance);

//Serial 값 확인
  Serial.println(light);
  Serial.println(distance);

  delay(1000);
}
