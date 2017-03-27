char A = 11;
char B = 12;
char C = 13;
int matrix[3][2][2] = {
  {{A, B}, {A, C}},
  {{B, A}, {B, C}},
  {{C, A}, {C, B}}
};

int i = 0, j = 0;

void lightOn(int pins[2]) {
  pinMode(pins[0], OUTPUT);
  pinMode(pins[1], OUTPUT);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
}

void lightOn2(int pins[][2]) {
  pinMode(pins[0][0], OUTPUT);
  pinMode(pins[0][1], OUTPUT);
  pinMode(pins[1][1], OUTPUT);
  digitalWrite(pins[1][0], HIGH);
  digitalWrite(pins[1][1], LOW);
  digitalWrite(pins[1][1], HIGH);
}

void setup() {
  Serial.begin(9600);
}

void refresh() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
}

void loop() {

  int LDR = analogRead(A0);
  //  Serial.println(LDR);
  if (LDR < 300) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 2; j++) {
        lightOn(matrix[i][j]);
        delay(3);
        refresh();
      }
    }
  } else if (LDR < 500) {
    lightOn(matrix[0][0]);
    delay(3);
    refresh();
    lightOn(matrix[2][1]);
    delay(3);
    refresh();
  }
}
