const int LED_PIN = 2;

// bool ledState = false;

unsigned long lastTime = 0;

void setup() {

  pinMode(LED_PIN, OUTPUT);

}

void loop() {

  /* 
  
  First Form 

  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);

  */

  /*
  
  Second Form
  
  digitalWrite(LED_PIN, ledState);
  ledState = !ledState;
  delay(1000);

  */

  /*

  Third Form

  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(1000);

  */

  // Fourth Form

  unsigned long currentTime = millis();

  if(currentTime - lastTime >= 1000) {

    lastTime = currentTime;
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));

  }
}
