int pin_in1 = 5;
int pin_in2 = 6;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  Serial.begin(9600);
 }

void loop() {
  // 시계방향으로 회전
  digitalWrite(pin_in1, HIGH);
  digitalWrite(pin_in2, LOW);
  delay(3000);

 // 반시계 방향으로 회전
  digitalWrite(pin_in1, LOW);
  digitalWrite(pin_in2, HIGH);
  delay(3000);
}
