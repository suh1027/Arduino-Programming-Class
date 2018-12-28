int pin_measure = A0;
int pin_led = 2;
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  digitalWrite(pin_led, LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(pin_measure);
  delayMicroseconds(deltaTime);
  digitalWrite(pin_led, HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Raw Signal Value(0-1023) : ");
  Serial.print(voMeasured);
  Serial.print(" - Voltage : ");
  Serial.print(calcVoltage);
  Serial.print(" - Dust Density : ");
  Serial.println(dustDensity);
  delay(1000);
}
