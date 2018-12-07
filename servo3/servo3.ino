#include <Servo.h>

Servo myServo;

int btn = 8;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);  
  pinMode(btn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(btn) == HIGH){
    int val = analogRead(A0);
    int rad = map(val,0,1023,0,180);
    myServo.write(rad);
    delay(15);
  }
  
  
}
