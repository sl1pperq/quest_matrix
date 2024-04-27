
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
boolean false_kod = false;
boolean ledPin_state;
int counter = 0;

void setup(){
    
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
   // digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
    servo.attach(9); //подключаем серву к порту 9
    servo.write(45);
    
    
}

void loop(){
  if (counter == 4) {
       
            tone(11, 400, 250); // Издаем звуковой сигнал длиной 300 миллисекунд 
            delay(2000);
            tone(11, 350, 1000);
            counter = 0;
            pinMode(11, INPUT);
            
    }
    else{
      noTone(11);
    }
    if (false_kod){
      servo.write(45);
      digitalWrite(ledPin,HIGH);
      blink = true;
      delay(500);
      digitalWrite(ledPin,LOW);
      blink = false;
      false_kod = false;
      counter = 0;
    }
  
    char key = keypad.getKey();

    
    
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
    if (key == '9'){
            if (counter == 0){
            Serial.println(1);
             servo.write(67); //ставим серву на 150
             counter+=1;
            }
            else{
              false_kod = true;
            }
          }
       
          if (key == '6'){
            if (counter == 1){
            Serial.println(1);
             servo.write(89); //ставим серву на 150
             
           counter +=1;
            }
           else{
            false_kod = true;
          }
          }
          
       
          if (key == '2'){
            if (counter == 2){
            Serial.println(1);
             servo.write(101); //ставим серву на 150
          counter +=1;
            }
            else{
            false_kod = true;
          }
          }
          
       
          if (key == '3' ){
          if (counter == 3){
            Serial.println(1);
             servo.write(135); //ставим серву на 150
             
           counter +=1;
            blink = false;
          }
            else{
            false_kod = true;
          }
          }
          
          ///////////////////////////////////////////////////////////

          if (key == '7') {
            false_kod = true;
            
       
        }
        
       
          if (key == '1'){
            Serial.println(1);
             false_kod = true;
             
           

        }
         
         
         if (key == '4') {
             false_kod = true;
          
        }
        if (key == '5') {
             false_kod = true;
          
        }
        if (key == '8') {
             false_kod = true;
          
            blink = true;
        }
        if (key == '0') {
             false_kod = true;
          
        }
        if (key == '#') {
             false_kod = true;
          
        }
        

                  if (key == '*') {
             false_kod = true;
          
        }
        
       
          
    Serial.println(key);
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
