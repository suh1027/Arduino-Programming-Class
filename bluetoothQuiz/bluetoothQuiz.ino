#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(2,3);
Servo myServo;

int green = 7;
int red = 8;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();
  if(bluetooth.available()){
    Serial.write(val);
    
  }
  if(val == 'l'){
    myServo.write(180);
    delay(15);
  }

  if(val == 'r'){
    myServo.write(-180);
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
