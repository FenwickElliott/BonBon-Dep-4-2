#include <Wire.h>
#include <Adafruit_MotorShield.h>

int i;

int SW[] = {2,3,4};
int LED[] = {10,12,12};

void setup() {
    for (i = 0; i < len(SW); i++) {
        pinMode(SW[i], INPUT);
    }
    for (i = 0; i < len(LED); i++) {
        pinMode(LED[i], OUTPUT);
    }

}

void loop() {
    for (i = 0; i < len(LED); i++) {
         if (digitalRead(SW[i]) == HIGH) {
            digitalWrite(LED[i], HIGH);
         }
//       digitalWrite(LED[i], digitalRead(SW[i]));
    }
}

int len(int ar[]) {
    return sizeof(ar) / sizeof(int);
}
