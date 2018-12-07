int red_pin = 11;
int green_pin = 6;
int yellow_pin = 9;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
  pinMode(yellow_pin,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = 0;
  int value2 = 0;
  int value3 = 0;
//  
//  for(value= 0; value < 250 ; value++){
//    analogWrite(red_pin,value);
//    delay(500);
//    if(value >240){
//      for(int down = 0; down > 0; down--){
//        analogWrite(red_pin,down);
//      }
//    }
//    if(value > 100){
//      for(value2 = 0; value2 < 250; value2++){
//        analogWrite(green_pin,value2);
//        delay(500);
//        if(value2 >240){
//          for(int down = 0; down > 0; down--){
//          analogWrite(green_pin,down);
//          }
//        }
//      }
//    }
//    if(value > 200){
//      for(value3 = 0; value3 < 250; value3++){
//        analogWrite(yellow_pin,value3);
//        delay(500);
//        if(value3 >240){
//          for(int down = 0; down > 0; down--){
//            analogWrite(yellow_pin,down);
//          }
//        }
//      }
//    }
//  }

for(value = 0; value<250; value++){
  analogWrite(red_pin,value);
  delay(100);

  if(value > 100){
    for(value2 = 0; value2 <250;value2 ++){
      analogWrite(green_pin,value2);
      delay(100);
    }
  }
  if(value > 200){
    for(value3=0;value3<250;value3++){
      analogWrite(yellow_pin,value3);
      delay(100);
    }
  }
}


    
  
}

void changeLight(int pin, int value){
//  if(value <= 250) {
//    for(value = 0; value <= 250; value=value+10){
//      digitalWrite(pin,value);  
//    }
//  }
//  else if(value >= 250){
//    for(value = 250; value >=0; value=value-10){
//      digitalWrite(pin,value);    
//    }
//  }
  delay(500);
}
