#define LED 10
#define BUT 2

boolean buttonWasUp = true;
boolean ledEnabled = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUT, INPUT_PULLUP);
}
 
void loop() {
  boolean buttonIsUp = digitalRead(BUT);
  if (buttonWasUp && !buttonIsUp) {
     delay(10);
     buttonIsUp = digitalRead(BUT);
     if (!buttonIsUp) {
        ledEnabled = !ledEnabled;
        digitalWrite(LED, ledEnabled);
     }
  }
   buttonWasUp = buttonIsUp;
}
