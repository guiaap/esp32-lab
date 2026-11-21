const int LED_PIN = 2;
const int POT_PIN = 34;

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

}

void loop() {
  
  int reading = analogRead(POT_PIN);

  float percentage = (reading / 4095.0) * 100.0;

  Serial.printf("ADC value: %d | Position:  %.2f%%\n", reading, percentage);

  delay(200);

  if(percentage >= 50.0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

}
