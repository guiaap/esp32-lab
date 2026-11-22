const int LED_PIN = 18;

const int FREQUENCY = 5000;
const int RESOLUTION = 8;

const unsigned long INTERVAL = 15;

unsigned long prevTime = 0;

int brightness = 0;
int direction = 1;

void setup() {

  ledcAttach(LED_PIN, FREQUENCY, RESOLUTION);

}

void loop() {

  unsigned long currentTime = millis();

  if(currentTime - prevTime >= INTERVAL) {

    prevTime = currentTime;

    ledcWrite(LED_PIN, brightness);

    brightness += direction;

    if(brightness >= 255) {
      direction = -1;
    }
    else if(brightness <= 0) {
      direction = 1;
    }
  }
}
