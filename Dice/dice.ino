int ledPin[] = {10, 11, 12, 13};
int ledCnt = 4;
int btnPin = 0;
int buttonStage = 0;
int lastButtonStage = 0;
void setup() {

  for (int i = 0; i < ledCnt; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(btnPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonStage = digitalRead(btnPin);
  if (buttonStage != lastButtonStage) {
    if (buttonStage == LOW) {
      showValue(8);
      delay(300);
      showValue(random(1, 7));
    }
    delay(100);
  }

  lastButtonStage = buttonStage;
}

void showValue(int number) {
  switch (number) {
    case 1 : digitalWrite(ledPin[3], HIGH); break;
    case 2 : digitalWrite(ledPin[2], HIGH); break;
    case 3 : digitalWrite(ledPin[3], HIGH); digitalWrite(ledPin[2], HIGH); break;
    case 4 : digitalWrite(ledPin[2], HIGH); digitalWrite(ledPin[1], HIGH); break;
    case 5 : digitalWrite(ledPin[3], HIGH); digitalWrite(ledPin[2], HIGH); digitalWrite(ledPin[1], HIGH); break;
    case 6 : digitalWrite(ledPin[2], HIGH); digitalWrite(ledPin[1], HIGH); digitalWrite(ledPin[0], HIGH); break;
    default : digitalWrite(ledPin[3], LOW); digitalWrite(ledPin[2], LOW); digitalWrite(ledPin[1], LOW); digitalWrite(ledPin[0], LOW); break;
  }
}

