#include <MPU6050_tockn.h>
#include <Wire.h>

int pzo = 8;
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  pinMode(pzo,OUTPUT);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  //mpu6050.setGyroOffsets(x, y, z);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();

  if(mpu6050.getAngleY() > 45){
    tone(pzo,250,250);
    delay(400);
    noTone(pzo);
  }
}
