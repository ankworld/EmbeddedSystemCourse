int SEG_A = 2;
int SEG_B = 3;
int SEG_C = 4;
int SEG_D = 5;
int SEG_E = 6;
int SEG_F = 7;
int SEG_G = 8;
int SEG_DP = 9;
int COM_D4 = 10;
int COM_D3 = 11;
int COM_D2 = 12;
int COM_D1 = 13;

int number = 8;
int digit = 0;

char _7SEG_TABLE[] = {0b11111100,
                      0b01100000,
                      0b11011010,
                      0b11110010,
                      0b01100110,
                      0b10110110,
                      0b10111110,
                      0b11100000,
                      0b11111110,
                      0b11110110,
                      0b11101110,
                      0b00111110,
                      0b10011100,
                      0b01111010,
                      0b10011110,
                      0b10001110,
                      0b00000000
                     };

void setup() {
  // Segment:
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
  // Digit Common
  pinMode(COM_D1, OUTPUT);
  pinMode(COM_D2, OUTPUT);
  pinMode(COM_D3, OUTPUT);
  pinMode(COM_D4, OUTPUT);
}

void loop() {

  displaySeg(number, digit);
  digit++;
  delay(3);
  if (digit > 4) digit = 0;

}

void displaySeg(int number, int digit) {
  digitalWrite(SEG_A, _7SEG_TABLE[number] & 1 << 7);
  digitalWrite(SEG_B, _7SEG_TABLE[number] & 1 << 6);
  digitalWrite(SEG_C, _7SEG_TABLE[number] & 1 << 5);
  digitalWrite(SEG_D, _7SEG_TABLE[number] & 1 << 4);
  digitalWrite(SEG_E, _7SEG_TABLE[number] & 1 << 3);
  digitalWrite(SEG_F, _7SEG_TABLE[number] & 1 << 2);
  digitalWrite(SEG_G, _7SEG_TABLE[number] & 1 << 1);
  digitalWrite(SEG_DP, _7SEG_TABLE[number] & 1 << 0);
  digitalWrite(COM_D1, 1 & 1 << digit);
  digitalWrite(COM_D2, 2 & 1 << digit);
  digitalWrite(COM_D3, 4 & 1 << digit);
  digitalWrite(COM_D4, 8 & 1 << digit);
}

