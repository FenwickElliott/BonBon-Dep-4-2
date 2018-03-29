/* Utilizing internal pull-up resistor
 * LED will illuminate when connection IS NOT made
 */

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(2);
  digitalWrite(13, buttonState);
}
