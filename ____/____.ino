void setup(){
  
}
void loop(){
  int light = analogRead(A0);
  int hertz = map(light,0,800,255,0);
  //analogWrite(9,ledLight);
  tone(8,hertz,100);
  delay(100);
  noTone(8);

  Serial.println(light);
  Serial.println(hertz);
  
  delay(200);
}
