#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  int rad = map(val,0,1023,0,180);
  myServo.write(rad);
  delay(15);
}
