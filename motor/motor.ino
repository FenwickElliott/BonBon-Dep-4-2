#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up motor control");
  AFMS.begin();

  Serial.println("Waiting for start signal... (2 seconds)");
  delay(2000);
  startUp();
  delay(5000);
  rampDown();
  finalStop();
  Serial.println("Demonstration complete");
}

void loop() {
//  Serial.println("Waiting for start signal... (3 seconds)");
}

void startUp() {
  Serial.println("Starting phase 0: Running");
  M1->run(FORWARD);
  M1->setSpeed(255);
}

void rampDown() {
  Serial.println("Starting phase 1: Ramping down");
  uint8_t i;
  for(i = 254; i > 200; i--) {
    M1->setSpeed(i);
    delay(50);
  }
}

void finalStop() {
  Serial.println("Starting phase 2: complete rest");
  M1->run(FORWARD);
  M1->setSpeed(0);
}
