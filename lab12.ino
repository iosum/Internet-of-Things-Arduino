/* Chia-Ying Ho
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int angle;    // variable to read the value from the analog pin
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int counter = 0;

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(button2Pin, INPUT);  //Setup button2 pin as an input pin.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() {
  b1();
}

void b1() {

  if (digitalRead(button1Pin) == LOW) {
    counter++;
  }

  if (digitalRead(button2Pin) == LOW) {
    counter--;
  }

  if (counter == -1) {
    //go back to 5
    myservo.write(20);  // zero degrees
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
    myservo.write(65);
    delay(100);
    digitalWrite(RGBGreenPin, HIGH); //Turn on Green
    delay(500);               //Wait for 2 seconds
    digitalWrite(RGBGreenPin, LOW);  //Turn off Green
    delay(500);
    myservo.write(110);
    delay(100);
    digitalWrite(RGBBluePin, HIGH); //Turn on RED
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBBluePin, LOW);  //Turn off Red
    delay(500);
    myservo.write(155);
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
    delay(500);
    counter = 4;
  }


  if (counter == 0) {
    myservo.write(20);  // zero degrees
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
  }



  if (counter == 1) {
    myservo.write(65);
    delay(100);
    digitalWrite(RGBGreenPin, HIGH); //Turn on Green
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBGreenPin, LOW);  //Turn off Green
  }


  if (counter == 2) {
    myservo.write(110);
    delay(100);
    digitalWrite(RGBBluePin, HIGH); //Turn on RED
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBBluePin, LOW);  //Turn off Red
  }


  if (counter == 3) {
    myservo.write(155);
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
  }


  if (counter == 4) {
    myservo.write(200);
    digitalWrite(RGBGreenPin, HIGH); //Turn on Green
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBGreenPin, LOW);  //Turn off Green
    delay(1000);
  }


  if (counter == 5) {
    myservo.write(155);
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
    delay(500);
    myservo.write(110);
    delay(100);
    digitalWrite(RGBBluePin, HIGH); //Turn on RED
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBBluePin, LOW);  //Turn off Red
    delay(500);
    myservo.write(65);
    delay(100);
    digitalWrite(RGBGreenPin, HIGH); //Turn on Green
    delay(500);               //Wait for 2 seconds
    digitalWrite(RGBGreenPin, LOW);  //Turn off Green
    delay(500);
    myservo.write(20);  // zero degrees
    delay(100);
    digitalWrite(RGBRedPin, HIGH); //Turn on Blue
    delay(1000);               //Wait for 2 seconds
    digitalWrite(RGBRedPin, LOW);  //Turn off Blue
    counter = 0;
  }

}
