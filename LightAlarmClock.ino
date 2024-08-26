// Vars
static volatile int awake;

// Timer Handler
ISR(TIMER1_COMPA_vect) {
  OCR1A += 25000;  // Advance The COMPA Register
  // Handle The 100ms Timer Interrupt

  int lighting = analogRead(0);
  Serial.println(awake);

  // Set semaphore for response to threshold light level
  if (lighting >= 100) {
    awake = 1;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  OCR1A = 25000;        // Timer CompareA Register
  TIMSK1 |= B00000010;  // Enable Timer COMPA Interrupt
  awake = 0;
}

// PWM of 66% duty cycle
void PWMFlash() {
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
  delay(500);
}

void DisableFlash() {
  digitalWrite(7, LOW);
}

void loop() {
  // Processing Mailbox data from awake flag
  if (awake == 1) {
    PWMFlash();
    awake = 0;
    DisableFlash();
  }


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
  // int lighting = analogRead(0);
  // Serial.println(lighting);
}
