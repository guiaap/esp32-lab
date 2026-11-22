const int LED_PIN = 18;
const int POT_PIN = 34;
const int FREQUENCY = 5000;
const int RESOLUTION = 8;

void setup() {

  ledcAttach(LED_PIN, FREQUENCY, RESOLUTION);

}

void loop() {

  int reading = analogRead(POT_PIN);

  int dutyCycle = map(reading, 0, 4095, 0, 255);

  ledcWrite(LED_PIN, dutyCycle);

  delay(10);
  
}
