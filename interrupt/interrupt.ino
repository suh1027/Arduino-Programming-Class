int btn1_pin = 2;
int btn2_pin = 3;

volatile int count1 = 0;
volatile int count2 = 1;

void setup() {
  Serial.begin(9600);
  pinMode(btn1_pin, OUTPUT);
  pinMode(btn2_pin, OUTPUT);

  attachInterrupt(0, btn1ISR, RISING);
  attachInterrupt(1, btn2ISR, CHANGE);
}

void loop() {
  delay(1000);
}

void btn1ISR() {
  count1 += 1;
  Serial.print("count1 : ");
  Serial.println(count1);
}

void btn2ISR() {
  count2 += 1;
  Serial.print("count2 : ");
  Serial.println(count2);
}
