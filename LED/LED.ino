int LED[] = {10,11,12};
int nLED = sizeof(LED) / sizeof(int);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < nLED; i++) {
    pinMode(LED[i], OUTPUT);
  }
  digitalWrite(LED[0], HIGH);
  if (nLED == 3) {
    digitalWrite(LED[1], HIGH);
  } else {
    digitalWrite(LED[1], LOW);
  }
  digitalWrite(LED[2], LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
