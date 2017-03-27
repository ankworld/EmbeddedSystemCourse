int LED = 13;

int interval = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  S();
  charBreak();
  O();
  charBreak();
  S();
  wordBreak();
}

void S() {
  digitalWrite(LED, HIGH);
  delay(interval);
  off();
  digitalWrite(LED, HIGH);
  delay(interval);
  off();
  digitalWrite(LED, HIGH);
  delay(interval);
}

void O() {
  digitalWrite(LED, HIGH);
  delay(interval * 3);
  off();
  digitalWrite(LED, HIGH);
  delay(interval * 3);
  off();
  digitalWrite(LED, HIGH);
  delay(interval * 3);
}

void off() {
  digitalWrite(LED, LOW);
  delay(interval);
}

void charBreak() {
  digitalWrite(LED, LOW);
  delay(interval * 3);
}

void wordBreak() {
  digitalWrite(LED, LOW);
  delay(interval * 5);
}

