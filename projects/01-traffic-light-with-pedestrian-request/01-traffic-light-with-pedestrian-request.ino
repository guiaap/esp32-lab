const int CAR_RED = 2;
const int CAR_YLW = 4;
const int CAR_GRN = 16;

const int PED_RED = 17;
const int PED_GRN = 5;

const int BUTTON = 18;

const int CAR_RED_NUM = 1;
const int CAR_YLW_NUM = 2;
const int CAR_GRN_NUM = 3;

const unsigned long CAR_RED_DUR = 5000;
const unsigned long CAR_YLW_DUR = 2000;

const unsigned long BUTTON_DISABLED_DUR = 7000;

unsigned long prevTime = 0;

int currentCarLedNum = 3;

unsigned long prevButtonTime = 0;
bool isButtonActive = true;
bool prevButtonState = HIGH;

bool isCrossingActive = false;

void setup() {

  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YLW, OUTPUT);
  pinMode(CAR_GRN, OUTPUT);

  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GRN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(CAR_RED, LOW);
  digitalWrite(CAR_YLW, LOW);
  digitalWrite(CAR_GRN, HIGH);

  digitalWrite(PED_RED, HIGH);
  digitalWrite(PED_GRN, LOW);

}

void loop() {
  
  unsigned long currentTime = millis();

  bool buttonState = digitalRead(BUTTON);

  if(!isButtonActive) {
    if(currentTime - prevButtonTime >= BUTTON_DISABLED_DUR) {
      isButtonActive = true;
    }
  }

  if(buttonState == LOW && prevButtonState == HIGH) {

    if(currentCarLedNum == CAR_GRN_NUM && isButtonActive) {

      isCrossingActive = true;

      digitalWrite(CAR_GRN, LOW);
      digitalWrite(CAR_YLW, HIGH);

      currentCarLedNum = 2;

      isButtonActive = false;

      prevTime = currentTime;
      prevButtonTime = currentTime;
    }
  }

  prevButtonState = buttonState;

  if(isCrossingActive) {

    if(currentTime - prevTime >= CAR_YLW_DUR && currentCarLedNum == CAR_YLW_NUM) {

        digitalWrite(CAR_YLW, LOW);
        digitalWrite(CAR_RED, HIGH);

        digitalWrite(PED_RED, LOW);
        digitalWrite(PED_GRN, HIGH);

        currentCarLedNum = 1;

        prevTime = currentTime;
    }

    if(currentTime - prevTime >= CAR_RED_DUR && currentCarLedNum == CAR_RED_NUM) {

      digitalWrite(CAR_RED, LOW);
      digitalWrite(CAR_GRN, HIGH);

      digitalWrite(PED_GRN, LOW);
      digitalWrite(PED_RED, HIGH);

      currentCarLedNum = 3;

      isCrossingActive = false;
    }
  }
}
