/* Chia-Ying Ho
   IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
   An IR detector/demodulator must be connected to the input RECV_PIN.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>

int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;
int key_pressed;
int last_key_pressed;


int RGBRedPin = 12;    //The red RGB LED is connected pin 12 of the Arduino.
int RGBBluePin = 13;  //The blue RGB LED is connected pin 13 of the Arduino.
int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.


void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");

  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.

}

void loop() {
  if (irrecv.decode(&results)) {

    Serial.println(results.value, DEC);
    key_pressed = results.value;
    irrecv.resume(); // Receive the next value
  }
  if (key_pressed == last_key_pressed) key_pressed = 0;


  if (key_pressed == 2060) { //Change this number according to the keys that you want to use in your remote
    digitalWrite(RGBRedPin, HIGH); //Turn on RED
  }
  if (key_pressed == 32) { //Change this number according to the keys that you want to use in your remote
    digitalWrite(RGBRedPin, LOW); //Turn on RED
  }
  if (key_pressed == 2081) { //Change this number according to the keys that you want to use in your remote
    digitalWrite(RGBBluePin, HIGH); //Turn on RED
  }
  if (key_pressed == 17) { //Change this number according to the keys that you want to use in your remote
    digitalWrite(RGBBluePin, LOW); //Turn on RED
  }
  if (key_pressed == 2064) { //Change this number according to the keys that you want to use in your remote
    tone(5, 2000, 100);
    delay(100);
    tone(5, 2000, 100);
  }


  last_key_pressed = key_pressed;

  delay(100);
}
