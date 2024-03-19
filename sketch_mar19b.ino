#include <LiquidCrystal.h>

constexpr uint8_t PIN_RS = 6;
constexpr uint8_t PIN_EN = 7;
constexpr uint8_t PIN_DB4 = 8;
constexpr uint8_t PIN_DB5 = 9;
constexpr uint8_t PIN_DB6 = 10;
constexpr uint8_t PIN_DB7 = 11;

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);

const int photoresistorPin = 2; // Пин для фоторезистора
const int threshold = 500; // Пороговое значение для определения попадания света

void setup() {
  Serial.begin(9600); // Инициализация последовательной связи
  // Устанавливаем размер экрана
  // Количество столбцов и строк
  lcd.begin(16, 2);
  // Устанавливаем курсор в колонку 0 и строку 0
  lcd.setCursor(0, 0);
  // Печатаем первую строку
  lcd.print("Hello, world!");
  // Устанавливаем курсор в колонку 0 и строку 1
  lcd.setCursor(0, 1);
  // Печатаем вторую строку
}

void loop() {
  int lightValue = analogRead(photoresistorPin); // Считываем значение с фоторезистора
  Serial.println(lightValue);
  if (lightValue > threshold) { // Если значение больше порогового значения
    lcd.print("8642"); // Выводим сообщение на текстовый экран
    delay(1000); // Ждем 1 секунду
  }
}
