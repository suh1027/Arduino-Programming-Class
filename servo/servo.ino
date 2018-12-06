#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 120; ++i){
    myServo.write(i);
    delay(15);
  }
  for(int j = 120; j>0; --j){
    myServo.write(j);
    delay(15);
  }
}
