#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(2,3);
Servo myServo;

LiquidCrystal_I2C lcd(0x27,16,2);

int green = 7;
int red = 8;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);

  lcd.begin();
  lcd.backlight();
  lcd.print("Press Start Btn");
  delay(15);
    
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
}
int x = 0;
int y = 0;

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();

  
  // command 출력
  if(bluetooth.available()){
    
    Serial.print("Command = ");
    Serial.write(val);
    Serial.println();

  }

  // 구현
  if(val == 's'){
    lcd.clear();
    lcd.setCursor(x,y);
    lcd.print("o(^o^)o");
    delay(15);
  }

//  if(){
//    lcd.clear();
//    lcd.print("Press Start Btn");
//  }

  if(val == 'l'){
    myServo.write(180);
    lcd.clear();
    x--;
    if(x < 0){
      x = 9; 
    }
    lcd.setCursor(x,y);
    lcd.print("o(^o^)o");
    delay(15);
  }

  if(val == 'r'){
    myServo.write(-180);
    lcd.clear();
    x++;
    if(x>9){
      x = 0;
    }
    lcd.setCursor(x,y);
    lcd.print("o(^o^)o");

    delay(15);
  }

  if(val == 'u'){
    lcd.clear();

    y--;

    if(y < 0){
      y = 1;
    }
    
    lcd.setCursor(x,y);
    lcd.print("o(^o^)o");

    delay(15);
  }

  if(val == 'd'){
    lcd.clear();
    
    y++;

    if(y > 1){
      y = 0;
    }
    
    lcd.setCursor(x,y);
    lcd.print("o(^o^)o");

    delay(15);    
  }
  
  if(val == 'a'){
    digitalWrite(green,HIGH);
  }
  if(val == 'b'){
    digitalWrite(red,HIGH);
  }
  else if (val == 'c'){
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
  }
 
}
