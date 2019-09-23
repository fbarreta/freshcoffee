#include <LiquidCrystal.h>

byte upLeft0[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01111,
  B01111,
  B01111,
};

byte upLeft1[8] = {
  B00010,
  B00100,
  B00010,
  B00001,
  B00000,
  B01111,
  B01111,
  B01111,
};

byte upRight0[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11100,
  B11110,
  B11101,
};

byte upRight1[8] = {
  B01000,
  B00100,
  B01000,
  B10000,
  B00000,
  B11100,
  B11110,
  B11101,
};

byte lowLeft[8] = {
  B01111,
  B01111,
  B01111,
  B00111,
  B00011,
  B00000,
  B00000,
  B00000,
};

byte lowRight[8] = {
  B11101,
  B11101,
  B11101,
  B11110,
  B11000,
  B00000,
  B00000,
  B00000,
};

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int PUSHBTN = 9;

int state = 0;
int reading;
int previous = 1;

bool fresh = false;

String coffeMsg = " No Coffee :(";

void setup() {
//  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(7, upLeft0);
  lcd.createChar(8, upRight0);
  lcd.createChar(9, lowLeft);
  lcd.createChar(10, lowRight);
  lcd.createChar(11, upRight1);
  lcd.createChar(12, upLeft1);
  pinMode(PUSHBTN, INPUT);
}

void loop() {
  reading = digitalRead(PUSHBTN);
//  Serial.println(reading);
  lcd.setCursor(2, 0);
  lcd.print(coffeMsg);
  lcd.setCursor(3, 1);
  lcd.print("12:00 Wed");
  printCoffee();
  if (reading == 1) {
    toggleCoffeMsg();
  }
  previous = reading;
}

void toggleCoffeMsg() {
  lcd.setCursor(2, 0);
  coffeMsg = "              ";
  if(fresh) {
    coffeMsg = "Fresh Coffee !";
  } else {
    coffeMsg = " No Coffee :( ";
  }
  fresh = !fresh;
}

void printCoffee() {
  lcd.setCursor(0, 0);
  lcd.write(7);
  lcd.setCursor(1, 0);
  lcd.write(11);
  lcd.setCursor(0, 1);
  lcd.write(9);
  lcd.setCursor(1, 1);
  lcd.write(10);
//  delay(500);
//  lcd.setCursor(1, 0);
//  lcd.write(8);
//  lcd.setCursor(0, 0);
//  lcd.write(12);
//  delay(500);
}
