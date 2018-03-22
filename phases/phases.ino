int SW[] = {3,4,5,6};
int i;
int n = 4;
int phase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setting up: phases");
  for (i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
  }
  Serial.println("Set up complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < n; i++) {
    if (digitalRead(SW[i]) == HIGH) {
//      Serial.print(i);
      if (phase != i) {
        Serial.println(" ");
        Serial.print("Phase: ");
        Serial.print(i);
        Serial.println(" ");
        phase = i;
      }
    }
  }
}
