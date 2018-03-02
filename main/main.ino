#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);

int i;
int state;
int n = 3;

int SW[] = {3,6,7};

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  Serial.println("Setting up...");
  for(i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
  }
  Serial.println("Set up complete!");
}

void loop() {
  if(digitalRead(SW[0]) == HIGH && state != 0) {
    startUp();
  }
  if(digitalRead(SW[1]) == HIGH && state != 1) {
    rampDown();
  }
  if(digitalRead(SW[2]) == HIGH && state != 2) {
    finalStop();
  }
}

void startUp() {
  state = 0;
  Serial.println("Starting phase 0: Running");
  M1->run(FORWARD);
  M1->setSpeed(255);
}

void rampDown() {
  state = 1;
  Serial.println("Starting phase 1: Ramping down");
  uint8_t i;
  for(i = 254; i > 200; i--) {
    M1->setSpeed(i);
    delay(50);
  }
}

void finalStop() {
  state = 2;
  Serial.println("Starting phase 2: complete rest");
  M1->run(FORWARD);
  M1->setSpeed(0);
}
