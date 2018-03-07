#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);
int M1s; // Motor_1_speed

int phase; // 0 := running, 1 := ramping down, 2: halting
int i; // all perpuse iterator

unsigned long t; // time since commencment
unsigned long last; // time since last count
int interval = 50; // count interval

int SW[] = {2,3,4}; // switches
int LED[] = {10,11,12}; // LEDs
int n = 3; // number to interate to
int ramp; // ramping coefficient

void setup() {
  Serial.begin(9600);
  Serial.println("Begining setup");
  AFMS.begin();

  for(i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
    pinMode(LED[i], OUTPUT);
  }
  setPhase(2);
  Serial.println("Setup complete");
}

void loop() {
  for(i = 0; i< n; i++) {
    if(digitalRead(SW[i]) == HIGH && phase != i) {
      setPhase(i);
    }
  }

  t = millis();
  if(t - last > interval) {
    if(M1s < 100) {
      ramp = 0;
    }
    last = t;
    M1s = M1s + ramp;
    M1->setSpeed(M1s);
  }
}

void setPhase(int p) {
  Serial.print("Setting phase: ");
  Serial.println(p);
  phase = p;

  switch(p) {
    case 0:
      Serial.println("Starting up...");
      M1->run(FORWARD);
      M1s = 255;
      M1->setSpeed(M1s);
      break;
    case 1:
      Serial.println("Ramp down...");
      ramp = -1;
      break;
    case 2:
      Serial.println("Halting...");
      M1s = 0;
      M1->run(RELEASE);
      break;
    default:
      M1->run(RELEASE);
      Serial.println("Error: invalid phase");
      break;
  }
  
  for(i = 0; i < n; i++) {
    if( i == p) {
      digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
}
