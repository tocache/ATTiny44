
//Declaración de variables
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int modeFlash = 0;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  int reading = digitalRead(3);

  if (reading != lastButtonState){
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonState){
      buttonState = reading;
      if(buttonState == HIGH){
        modeFlash = modeFlash + 1;
        if (modeFlash == 5){
          modeFlash = 0;
        }
      }
    }
  }
  switch (modeFlash){
    case 0:
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);               // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);               // wait for a second
      break;
    case 1:
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);              // wait for a second
      digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);              // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(1500);              // wait for a second
      break;
    case 2:
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(1500);              // wait for a second
      break;
    case 3:
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(200);              // wait for a second
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(1500);              // wait for a second
      break;
    case 4:
      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(200);              // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(2000);              // wait for a second
      break;
  }
  lastButtonState = reading;
}
