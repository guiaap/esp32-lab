const int LED_PIN = 2;
const int BUTTON_PIN = 4;

bool ledState = LOW;
bool lastButtonState = HIGH;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {

  bool buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == LOW && lastButtonState == HIGH) {

    ledState = !ledState;
   
  }

  lastButtonState = buttonState;

  digitalWrite(LED_PIN, ledState);

}
