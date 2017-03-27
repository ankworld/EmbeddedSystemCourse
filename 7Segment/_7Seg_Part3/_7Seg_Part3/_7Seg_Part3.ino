#include <Arduino.h>

// Create by Anukul

const int interval = 1000;
unsigned long previousMillis = 0;

// Pin declearation
byte SEG_A = 2;
byte SEG_B = 3;
byte SEG_C = 4;
byte SEG_D = 5;
byte SEG_E = 6;
byte SEG_F = 7;
byte SEG_G = 8;
byte SEG_DP = 9;
byte COM_D1 = 10;
byte COM_D2 = 11;
byte COM_D3 = 12;
byte COM_D4 = 13;

// Display Value
unsigned int number = 0;
byte screen[] = {0, 0, 0, 0};
byte digit = 0;

// Lookup table
// Encode in a b c d e f g dp
byte _7SEG_TABLE[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010,
                      0b01100110, 0b10110110, 0b10111110, 0b11100000,
                      0b11111110, 0b11110110, 0b11101110, 0b00111110,
                      0b10011100, 0b01111010, 0b10011110, 0b10001110};


void setup() {
  // Segment
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
  unsigned long currentMillis = millis();

  // scan digit
  if (digit > 3) {
    // reset digit
    digit = 0;

    // ElapsedMillis
    if ((unsigned long)(currentMillis - previousMillis) >= interval) {
      // coding event here
      number++;
      screen[0] = (number / 1) % 10;
      screen[1] = (number / 10) % 10;
      screen[2] = (number / 100) % 10;
      screen[3] = (number / 1000) % 10;
      previousMillis = currentMillis;
    }
  }

  // blank for remove shadows
  displayBlank(digit);
  displaySeg(screen[digit], digit);

  // increase digit for next display
  digit++;
  delay(3);
}

void displayBlank(byte digit) {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_DP, LOW);
  digitalWrite(COM_D1, 1 & 1 << digit);
  digitalWrite(COM_D2, 2 & 1 << digit);
  digitalWrite(COM_D3, 4 & 1 << digit);
  digitalWrite(COM_D4, 8 & 1 << digit);
}

void displaySeg(byte number, byte digit) {
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
