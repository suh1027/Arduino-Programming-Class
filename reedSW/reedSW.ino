#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo myServo;


int detectpin = A0;
int servo_pin = 8;
int red_pin = 13;
int sensorpin = 3;
int yellow_pin = 12;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servo_pin);

  lcd.begin();
  lcd.backlight();
  
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin,OUTPUT);
  pinMode(sensorpin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(sensorpin);
  int alcohol = analogRead(detectpin);
  int count = 0;
  
  if(reedSW == LOW){
    digitalWrite(red_pin,HIGH);
    myServo.write(90); //키를 잠굼
    
    
    delay(5000);
  //음주 테스트
  
  //  else{
  //    digitalWrite(red_pin,LOW);
  //    myServo.write(0);
  //  }
    //음주상태일때
    if(alcohol >= 400) {
      lcd.clear();
      lcd.print("alcohol over 500");
      lcd.setCursor(0,1);
      lcd.print("servo 90");
    }
      else{
        lcd.clear();
        lcd.print("alcohol : ");
        lcd.setCursor(0,1);
        lcd.print(alcohol); 
        myServo.write(0); // -> 서보모터 끄기로 바꿔야지 움직이기 가능 
    }
  }

  //상자문이 열려있을때
  else{
    digitalWrite(red_pin,LOW);
    lcd.clear();
    lcd.print("case open");
  }
  Serial.print("alcohol : ");
  Serial.println(alcohol);
  Serial.print("reed: ");
  Serial.println(reedSW);
  delay(1000);
}
