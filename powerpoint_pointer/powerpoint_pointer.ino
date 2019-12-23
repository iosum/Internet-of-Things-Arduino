/* 200428479
 *  Chia-Ying Ho
 *  code retrived from
* https://create.arduino.cc/projecthub/Tiobel/arduino-powerpoint-pointer-f499f8
*
* 
*/
// import the remote library
#include <IRremote.h>
#include "Keyboard.h"
// pin of ir reciever to arduino pin 2
int RECV_PIN = 2;
// Create the receiver object to recieve the signal from the sensor
IRrecv irrecv(RECV_PIN);
// create a variable name called results, which data type is decode_result
decode_results results;
int key_pressed;
int last_key_pressed;

void setup()
{
  Serial.begin(9600);
  // Start the receiver
  irrecv.enableIRIn(); 
  Keyboard.begin();
}

void loop() {
    // set up keyboard values
    // call a function called decode, which needs to be given an address of the results variable
    // have we received an ir signal?
    if (irrecv.decode(&results)) {
    // get the value from my keyboard
    key_pressed = results.value;
    Serial.println(key_pressed);
    // Receive the next value
    irrecv.resume(); 
  }
  //I only want to check one time, what key was pressed
  if (key_pressed == last_key_pressed) key_pressed = 0; 
  // my right arrow button is 23205
  if (key_pressed == 23205) { 
    // let arduino to use my keyboard command
    Keyboard.press(KEY_RIGHT_ARROW);
    // Let go of all keys currently pressed
    Keyboard.releaseAll();
  }
  if (key_pressed == 4335) {
    Keyboard.press(KEY_LEFT_ARROW );
    Keyboard.releaseAll();
  }
  last_key_pressed = key_pressed;
}

// left: 4335
// right: 23205
// top: 6375
// down: 19125
