void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

//int SW[] = {3,4,5,6}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(13, HIGH);
    Serial.println("XXXX");
  } else {
    digitalWrite(13, LOW);
    Serial.println("----");
  }

}
