#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);

int phase;
int i;
int t;

int SW[] = {3,4,5};
int LED[] = {10,11, 12};
int n = 3;

void setup() {
  Serial.begin(9600);
  Serial.println("Begining setup");
  AFMS.begin();
  M1->setSpeed(0);
  M1->run(FORWARD);

  for(i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
    pinMode(LED[i], OUTPUT);
  }
  setPhase(0);
  Serial.println("Setup complete");
}

void loop() {
  for(i = 0; i< n; i++) {
    if(digitalRead(SW[i]) == HIGH && phase != i) {
      setPhase(i);
    }
  }
}

void setPhase(int p) {
  Serial.print("Setting phase: ");
  Serial.println(p);
  phase = p;
  for(i = 0; i < n; i++) {
    if( i == p) {
      digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
}
