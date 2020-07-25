/**************************************************************************
 'Stay Safe' LED display (created in response to Covid-19)
 https://github.com/alicraigmile/fish

 Written by Ali Craigmile with contributions from the open source community.
 BSD license.
 **************************************************************************/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buzzerPin = 6;     // the current mode will be signalled on the buzzer
const int stayPin =  8;      // the number of the LED pin
const int safePin =  9;      // the number of the LED pin

int mode = 3; // there are 2 operating mode. pushing button toggles between them
int counter = 0; // to keep track of where in the pattern we are

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long buttonMillis = 0;        // will store last time button was pushed

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long volatile lastDebounceTime = 0;  // the last time the output pin was toggled
const unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

const unsigned long buzzerDuration = 50;    // the debounce time; increase if the output flickers
const unsigned long buzzerDelay = 100;    // the debounce time; increase if the output flickers

const bool pattern1[][2] = {  
  {HIGH, LOW},
  {LOW, LOW},
  {HIGH, LOW},
  {LOW, LOW},
  {LOW, HIGH},
  {LOW, LOW},
  {LOW, HIGH},
  {LOW, LOW},
  {HIGH, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
  {HIGH, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
  {HIGH, HIGH},
  {LOW, LOW},
};

const bool pattern2[][2] = {  
  {HIGH,LOW},
  {LOW,HIGH}
};

const bool pattern3[][2] = {  
  {HIGH,LOW},
  {HIGH,HIGH},
  {LOW,LOW}
};

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  pinMode(buttonPin, INPUT);
  pinMode(stayPin, OUTPUT);
  pinMode(safePin, OUTPUT);
  attachInterrupt(0, pin_ISR, RISING);
}

void loop() {
 // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (lastDebounceTime) {
    if ((currentMillis - lastDebounceTime) > debounceDelay) {
      lastDebounceTime = 0;
      counter = 1;
      mode++;
      if (mode > 3) {
        mode = 1;
      }
      for (int i=0; i<mode; i++) {
        tone(6,440);
        delay(buzzerDuration);
        noTone(6);      
        delay(buzzerDelay);
      }
      Serial.print("changing to pattern ");
      Serial.println(mode);
    }
  }


  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (mode == 1) {
        int pattern1Size = sizeof(pattern1) / sizeof(pattern1[0]);
        Serial.print("pattern1Size = ");
        Serial.println(pattern1Size);
        counter++;
        if (counter > pattern1Size) {
          counter = 1;
        }
        Serial.print("pattern ");
        Serial.print(mode);
        Serial.print(" - ");
        Serial.print(counter);
        Serial.print('/');
        Serial.println(pattern1Size);
        digitalWrite(stayPin, pattern1[counter-1][0]);
        digitalWrite(safePin, pattern1[counter-1][1]);
    } else if (mode == 2) {
        int pattern2Size = sizeof(pattern2) / sizeof(pattern2[0]);
        counter++;
        if (counter > pattern2Size) {
          counter = 1;
        }
        Serial.print("pattern ");
        Serial.print(mode);
        Serial.print(" - ");
        Serial.print(counter);
        Serial.print('/');
        Serial.println(pattern2Size);
        digitalWrite(stayPin, pattern2[counter-1][0]);
        digitalWrite(safePin, pattern2[counter-1][1]);
    } else if (mode == 3) {
        int pattern3Size = sizeof(pattern3) / sizeof(pattern3[0]);
        counter++;
        if (counter > pattern3Size) {
          counter = 1;
        }
        Serial.print("pattern ");
        Serial.print(mode);
        Serial.print(" - ");
        Serial.print(counter);
        Serial.print('/');
        Serial.println(pattern3Size);
        digitalWrite(stayPin, pattern3[counter-1][0]);
        digitalWrite(safePin, pattern3[counter-1][1]);
    }   

   

  }

}

void pin_ISR() {
  lastDebounceTime = millis();
}
