int led_pin = 13;
int detectpin = 7;
int sensor_state = LOW;
int input = LOW;
int red = 11;
int green = 10;
int blue = 9;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(detectpin, INPUT);
  Serial.begin(9600);
  
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input = digitalRead(detectpin);

  digitalWrite(red,HIGH);
//
//  if(input == HIGH){
//    digitalWrite(led_pin,HIGH);
//    Serial.println("motion detected");
//    Serial.print("count : ");
//    Serial.println(count);
//    count++;
//  }else{
//    digitalWrite(led_pin,LOW);
//    Serial.println("motion end");
//  }
//  if(count > 10 && count < 20){
//       setColor(255,0,0);      
//    }
//    else if(count > 20 && count < 30){
//      setColor(0,255,0);
//     
//    }
//    else if(count > 30 && count <40){
//      setColor(0,0,255);
//    }
//    else{
//      analogWrite(red,LOW);
//      analogWrite(green,LOW);
//      analogWrite(blue,LOW);
//    }
    delay(1000);
}
void setColor(int redv, int greenv, int bluev){
  analogWrite(red,redv);
  analogWrite(green,greenv);
  analogWrite(blue,bluev);
}
