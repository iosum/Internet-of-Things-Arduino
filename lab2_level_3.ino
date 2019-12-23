/*      ChiaYing Ho
        Title: 321Maker Experiment #002 - RGB Blink
        Description: This program will cycle different colors using the RGB LED on the 321Maker shield.
        Tutorial:  http://321maker.com/tutorial/e002-rgb-blink
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: The RGB LED is connected to a Pulse Width Modulation(PWM) pin. 
        You can use analogWrite to control brightness.
*/
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.


void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}


// Displaying a police lightbar
void loop() { //The loop function runs forever.
  
//Display Red
digitalWrite(RGBRedPin, HIGH); //Turn on RED
delay(900);              
digitalWrite(RGBRedPin, LOW);  //Turn off Red

//Display Green
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(300);               
digitalWrite(RGBGreenPin, LOW);  //Turn off Red

//Display Blue
digitalWrite(RGBBluePin, HIGH); //Turn on blue
delay(500);               
digitalWrite(RGBBluePin, LOW);  //Turn off blue


//Display  Magenta  (Red + Blue)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on RED
delay(1000);               
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBBluePin, LOW); //Turn on RED

//Display  Yellow  (Red + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(1500);               
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBGreenPin, LOW); //Turn of RED

//Display  Cyan  (Blue + Green) 
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(2500);               
digitalWrite(RGBBluePin, LOW); //Turn of BLUE
digitalWrite(RGBGreenPin, LOW);  //Turn off GREEN

//Display White  (Red + Blue + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(1000);               
digitalWrite(RGBRedPin, LOW);  //Turn off RED
digitalWrite(RGBBluePin, LOW); //Turn off BLUE
digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

//Display  Cyan  (Blue + Green) 
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(1500);               
digitalWrite(RGBBluePin, LOW); //Turn of BLUE
digitalWrite(RGBGreenPin, LOW);  //Turn off GREEN

//Display Green
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(1300);               
digitalWrite(RGBGreenPin, LOW);  //Turn off Red

//Display  Magenta  (Red + Blue)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on RED
delay(1000);             
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBBluePin, LOW); //Turn on RED

//Display Blue
digitalWrite(RGBBluePin, HIGH); //Turn on blue
delay(500);               
digitalWrite(RGBBluePin, LOW);  //Turn off blue

//Display Green
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(600);               
digitalWrite(RGBGreenPin, LOW);  //Turn off Red

//Display  Magenta  (Red + Blue)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on RED
delay(700);               
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBBluePin, LOW); //Turn on RED


//Display  Cyan  (Blue + Green) 
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(800);              
digitalWrite(RGBBluePin, LOW); //Turn of BLUE
digitalWrite(RGBGreenPin, LOW);  //Turn off GREEN

//Display White  (Red + Blue + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(900);               
digitalWrite(RGBRedPin, LOW);  //Turn off RED
digitalWrite(RGBBluePin, LOW); //Turn off BLUE
digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

}
