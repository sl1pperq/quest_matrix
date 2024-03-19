/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 // Обратите внимание, я немного поправил скетч, который есть в примере к библиотеке
 */
#include <Keypad.h> // Библиотека для работы с матрицей
#include <Servo.h> // Библиотека для работы с сервоприводом

Servo servo; //объявляем переменную servo типа Servo
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 12; 

boolean blink = false;
boolean ledPin_state;

void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
   // digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
    servo.attach(9); //подключаем серву к порту 9
}

void loop(){
  
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
            tone(11, (int)key*10, 300); // Издаем звуковой сигнал длиной 300 миллисекунд 
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
          if (key == '6') {
            digitalWrite(ledPin,HIGH);
                  
            blink = false;
        }

          if (key == '7') {
            digitalWrite(ledPin,LOW);
         
            blink = false;
        }

        
          if (key == '1'){
             servo.write(150); //ставим серву на 150
          
            blink = false;
        }


                  if (key == '*') {
             servo.write(30); //ставим серву на 150
          
            blink = false;
        }
    
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    }
}
