/*      Chia-Ying Ho
        Title: 321Maker Experiment #007 - RGB Fade
        Description: This program will fade the Red, Green, Blue(RGB) LED on the 321Maker shield.
        Tutorial:  http://321maker.com/tutorials/rgb-fade
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: The RGB LED is connected to a Pulse Width Modulation(PWM) pin.
        You can use analogWrite to control brightness.
*/
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5;    //This is the number of milliseconds that it will take between steps during fading.
int outputValue = 0;
int counter = 0;
int rotationPin = A0;
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.


void setup() { //The Setup function runs once.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.

  if (digitalRead(button1Pin) == LOW) {
    counter++;
    delay(300);


    while (counter != 0) {

      int data = analogRead(rotationPin);
      data = map(data, 0, 1023, 0, 255);



      if (counter == 1) {

        analogWrite(RGBRedPin, data);
        //analogWrite(RGBBluePin, 0);
       // analogWrite(RGBGreenPin, 0);
        delay(fadeDelay);
        
        if (digitalRead(button1Pin) == LOW) {
              counter = 2;
        delay(300);
        }

      }

      else if (counter == 2) {
        analogWrite(RGBBluePin, data);
       // analogWrite(RGBRedPin, 0);
       // analogWrite(RGBGreenPin, 0);
        delay(fadeDelay);
        if (digitalRead(button1Pin) == LOW) {
          counter = 3;
          delay(300);
        }
      }

      else if (counter == 3) {
        analogWrite(RGBGreenPin, data);
      //  analogWrite(RGBRedPin, 0);
      //  analogWrite(RGBBluePin, 0);
        delay(fadeDelay);
        if (digitalRead(button1Pin) == LOW) {
          counter = 1;
          delay(300);

        }
      }
    }
  }
}
 
