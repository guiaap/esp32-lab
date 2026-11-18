const int LED_PIN = 2;
const int BUTTON_PIN = 4;

const unsigned long DEBOUNCE_MS = 30;

bool lastButtonState = HIGH;
bool stableButtonState = HIGH;

unsigned long lastButtonTime = 0;

bool ledState = false;


 void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {

  unsigned long currentTime = millis();

  bool buttonState = digitalRead(BUTTON_PIN);

  if(buttonState != lastButtonState) {
    lastButtonTime = currentTime;
  }

  if(currentTime - lastButtonTime >= DEBOUNCE_MS) {

    if(buttonState != stableButtonState) {

      stableButtonState = buttonState;

      if(stableButtonState == LOW) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }

  lastButtonState = buttonState;

}
