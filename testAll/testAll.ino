void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

int SW[] = {3,4,5,6};
int n = 4;

void loop() {
  int on = 0;
  int i;
  for (i = 0; i < n; i++) {
     if (digitalRead(SW[i]) == HIGH) {
      on = 1;
     }
  }

  if (on == 1) {
    digitalWrite(13, HIGH);
    Serial.println("XXXX");
  } else {
    digitalWrite(13, LOW);
    Serial.println("----");
//  }
  }
}
