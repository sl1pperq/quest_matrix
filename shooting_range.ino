#include <LiquidCrystal.h>

constexpr uint8_t PIN_RS = 4;
constexpr uint8_t PIN_EN = 5;
constexpr uint8_t PIN_DB4 = 10;
constexpr uint8_t PIN_DB5 = 11;
constexpr uint8_t PIN_DB6 = 12;
constexpr uint8_t PIN_DB7 = 13;

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);

const int photoresistorPin = A0;
const int threshold = 65; // Пороговое значение для определения попадания света

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);
}

void loop() {
  int lightValue = analogRead(photoresistorPin);
  Serial.println(lightValue);
  if (lightValue < threshold) { 
    lcd.print("HEO 1998"); 
    delay(30000);
  }
}
