const int LED_01 = 2;
const int LED_02 = 4;
const int LED_03 = 16;

unsigned long prevTime01 = 0;
unsigned long prevTime02 = 0;
unsigned long prevTime03 = 0;

bool ledState01 = LOW;
bool ledState02 = LOW;
bool ledState03 = LOW;

void setup() {

  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);

  digitalWrite(LED_01, LOW);
  digitalWrite(LED_02, LOW);
  digitalWrite(LED_03, LOW);

}

void loop() {

  unsigned long currentTime = millis();

  if(currentTime - prevTime01 >= 1000) {
    prevTime01 = currentTime;
    ledState01 = !ledState01;
    digitalWrite(LED_01, !ledState01);
  }

  if(currentTime - prevTime02 >= 500) {
    prevTime02 = currentTime;
    ledState02 = !ledState02;
    digitalWrite(LED_02, !ledState02);
  }

  if(currentTime - prevTime03 >= 200) {
    prevTime03 = currentTime;
    ledState03 = !ledState03;
    digitalWrite(LED_03, !ledState03);
  }
  
}
