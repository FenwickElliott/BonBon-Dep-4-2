int i;
int state;
int n = 3;

int SW[] = {2,3,4};
int LED[] = {10, 11, 12};

void setup() {
  Serial.begin(9600);
  for(i = 0; i < n; i++) {
    pinMode(SW[i], INPUT);
  }
  for(i = 0; i < n; i++) {
    pinMode(LED[i], OUTPUT);
  }
  setState(2);
  Serial.println("Set up complete!");
}

void loop() {
  for (i = 0; i < n; i++) {
    if(digitalRead(SW[i]) == HIGH && i != state) {
      setState(i);
    }
  }
}

void setState(int s) {
  state = s;
  Serial.print("State: ");
  Serial.println(state);
  for(i = 0; i < 3; i++) {
    if(i == s) {
      digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
}

