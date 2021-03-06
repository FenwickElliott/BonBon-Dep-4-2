#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *M1 = AFMS.getMotor(1);
int M1s; // Motor_1_speed

int phase; // 0 := at begining, 1 := ramping up, 2:= full speed forward, 3:= ramping down, 4 := at end,
// 5:= ramping up, 6:= full speed back, 7 := ramping down, 
int i; // all perpuse iterator

unsigned long t; // time since commencment
unsigned long last; // time since last count
int interval = 50; // count interval

int SW[] = {3, 4, 5, 6};
int n = 4;
int ramp;

void setup() {
  Serial.begin(9600);
  Serial.println("Begining setup");
  AFMS.begin();

  for(i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
  }
  phase = 0;
  Serial.println("Setup complete");
  
  for(i = 3; i > 0; i--) {
    Serial.println(i);
    delay(1000);
  }
  buttonZero();
}

void loop() {
 for(i = 0; i< n; i++) {
    if(digitalRead(SW[i]) == HIGH) {
      depressed(i);
    }
  }

  t = millis();
  if(t - last > interval) {
    last = t;
    M1s = M1s + ramp;
    M1->setSpeed(M1s);
    if(M1s < 100 || M1s >= 255) {
      ramp = 0;
    }
  }
}

void depressed(int sw) {
   Serial.println(sw);
   switch(sw){
     case 0:
      buttonZero();
      break;
     case 1:
      buttonOne();
      break;
     case 2:
      buttonTwo();
      break;
     case 3:
      buttonThree();
      break;
     case 4:
      buttonFour();
      break;
     case 5:
      buttonFive();
      break;
     default:
      M1->run(RELEASE);
      M1s = 0;
      ramp = 0;
      Serial.println("Error: invalid phase");
      break;
   }
}

void buttonZero() {
  if (phase == 0) {
    phase = 1;
    Serial.println("Phase 1: Ramping up, forward");
    M1->run(FORWARD);
    M1s = 100;
    ramp = 1;
  }
}

void buttonOne() {
  Serial.println(1);
  if (phase == 7) {
    phase = 0;
    Serial.println("Phase 0; Full stop, near end");
    M1->run(RELEASE);
    M1s = 0;
    ramp = 0;
  }
}

void buttonTwo() {
  Serial.println(2);
  if (phase == 1) {
    phase = 2;
    Serial.println("Phase 2: Full speed, forward");
    M1s = 255;
    ramp = 0;
  } else if (phase == 6) {
    phase = 7;
    Serial.println("Phase 7: Ramping down, backward");
    ramp = -1;
  }
}

void buttonThree() {
  if (phase == 2) {
    phase = 3;
    Serial.println("Phase 3: Ramping down, forward");
    ramp = -1;
  } else if (phase == 5) {
    phase = 6;
    Serial.println("Phase 6: Full speed, backward");
    M1s = 255;
    ramp = 0;
  }
}

void buttonFour() {
  if (phase == 3) {
    phase = 4;
    Serial.println("Phase 4: Full Stop, far end");
    M1->run(RELEASE);
    M1s = 0;
    ramp = 0;
  }
}

void buttonFive() {
  if (phase == 4) {
    phase = 5;
    Serial.println("Phase 5: Ramping up, backward");
    M1->run(BACKWARD);
    M1s = 100;
    ramp = 1;
  }
}

