#include <SoftwareSerial.h>

int blueTX = 2;
int blueRX = 3;

SoftwareSerial mySerial(blueTX,blueRX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()){
    Serial.write(mySerial.read());
  }
  if(Serial.available()){
    mySerial.write(Serial.read());
  }
}

//Serial 에서 AT+NAME..... // AT+PIN..... 설정
