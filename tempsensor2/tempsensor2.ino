#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int DHT11PIN = 2;

dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  float temp = (float)DHT11.temperature;
  float hum = (float)DHT11.humidity;

  float result = ((9/5)*temp) - (0.55*(1-hum)*((9/5)*temp-26)) + 32;

//  Serial.println(temp);
//  Serial.println(hum);
  Serial.println(result);

  if(result >= 80){
    lcd.clear();
    lcd.print("over 80");
    delay(1000);
  }
  else if(result >= 75 && result < 80){
    lcd.clear();
    lcd.print("over 75 ~ 80");
  }
  else if(result >= 68 && result < 75){
    lcd.clear();
    lcd.print("over 68 ~ 75");
  }
  else {
    lcd.clear();
    lcd.print("lower 68");
  }
}
