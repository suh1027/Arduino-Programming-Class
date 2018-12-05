int trig_pin = 2;
int echo_pin = 3;
int red_pin = 12;
int green_pin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);

  long duration = pulseIn(3,HIGH);
  long distance = duration/58.2;
  //tone(8,1000,20);
  delay(20);
  noTone(8);
  delay(2*distance);
  Serial.println(distance);
  
  if(distance > 5 && distance < 10){
    digitalWrite(red_pin,LOW);
    
    digitalWrite(green_pin,HIGH);
    
  }
  else{
    digitalWrite(green_pin,LOW);
    
    digitalWrite(red_pin,HIGH);
    
  }
}
