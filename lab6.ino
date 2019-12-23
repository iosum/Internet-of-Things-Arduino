/*      Chia-Ying Ho
        Title: 321Maker Experiment #006 - Button
        Description: This program will turn on the blue LED when SW1 is pressed and the red LED when SW2 button is pressed.
        Tutorial:  http://321maker.com/e/button
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/

int redLedPin  = 12 ;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin = 13 ;  //The blue LED is connected pin 13 of the Arduino.
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.

int flag = 0;


void setup() { //The Setup function runs once.
  //Serial.println("in setup");
  //pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
  //pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(button2Pin, INPUT);  //Setup button2 pin as an input pin.

  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.
  //Serial.println("in loop");
  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
    Serial.println("pin 1 pressed");

    flag = 1;

    while (flag != 0) {

      digitalWrite(RGBRedPin, HIGH);//Turn on the blue LED.
      delay(1000);
      digitalWrite(RGBRedPin, LOW);//Turn on the blue LED.
      if (flag != 0 && digitalRead(button2Pin) == LOW)
      {
        Serial.println("inside if");
        flag = 0;
        break;
      }
      digitalWrite(RGBGreenPin, HIGH); // Turn on the Green LED.
      delay(1000);
      digitalWrite(RGBGreenPin, LOW); // Turn on the Green LED.
      if (flag != 0 && digitalRead(button2Pin) == LOW)
      {
        Serial.println("inside if");
        flag = 0;
        break;
      }
      digitalWrite(RGBBluePin, HIGH); // Turn on the Blue LED.
      delay(1000);
      digitalWrite(RGBBluePin, LOW); // Turn on the Blue LED.
      if (flag != 0 && digitalRead(button2Pin) == LOW)
      {
        Serial.println("inside if");
        flag = 0;
        break;
      }
    }
  }
}
