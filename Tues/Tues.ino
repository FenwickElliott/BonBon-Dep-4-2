#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);

int phase = 0;
int i;
int t;

int SW[] = {2,3,4};
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
}

void loop() {
  for(i = 0; i < n; i++) {
    if( phase == i) {
      digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
}

