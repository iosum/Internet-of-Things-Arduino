/*      Chia-Ying Ho
        Title: 321Maker Experiment #008 - Buzzer
        Description: This program will turn on the buzzer when the SW1 button is pressed.
        Tutorial:  http://321maker.com/e/buzzer
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/


#include "pitches.h";

int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 2;   //The SW1 button is connect to pin 2 of the Arduino.
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.

int notes[] = {NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4};




void setup() { //The Setup function runs once.
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin
}

void loop() { //The loop function runs forever.
  if (digitalRead(button1Pin) == LOW) {

    for (int i = 0; i < 7; i++) {
      tone(buzzerPin, notes[i], 408);
      if (i % 2 == 0) {
        setRedColor();
      }
      else if ( i % 3 == 0) {
        setGreenColor();
      }
      else setBlueColor();
      delay(300);
    }
  }
}


void setRedColor() {
  digitalWrite(RGBRedPin, HIGH);//Turn on the blue LED.
  delay(300);
  digitalWrite(RGBRedPin, LOW);//Turn on the blue LED.
}

void setGreenColor() {
  digitalWrite(RGBGreenPin, HIGH);//Turn on the blue LED.
  delay(300);
  digitalWrite(RGBGreenPin, LOW);//Turn on the blue LED.
}

void setBlueColor() {
  digitalWrite(RGBBluePin, HIGH);//Turn on the blue LED.
  delay(300);
  digitalWrite(RGBBluePin, LOW);//Turn on the blue LED.
}
