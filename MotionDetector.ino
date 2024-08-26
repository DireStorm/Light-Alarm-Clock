void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
}

// PWM of 66% duty cycle
void PWMFlash() {
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
  delay(500);
}

void loop() {
  // PIR Sensor
  // int motion = digitalRead(8);
  // Serial.println(motion);
  // if (motion == 1) {
  //   PWMFlash();
  //   //digitalWrite(7, HIGH);
  // } else {
  //   digitalWrite(7, LOW);
  // }

  // Photocell
  int lighting = analogRead(0);
  Serial.println(lighting);
}
