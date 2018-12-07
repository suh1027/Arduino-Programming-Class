int sound_pin = A0;
int red_pin = 11;
int green_pin = 6;
int yellow_pin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value,0,1023,0,255);

  Serial.print("sound value : ");
  Serial.println(sound_value);

  Serial.print("light value : ");
  Serial.println(light_value);

  analogWrite(led_pin,light_value);
  delay(100);
}
