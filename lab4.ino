/*      ChiaYing Ho
        Title: 321Maker Experiment #004 - Light Sensor
        Description: This program will read the data from the light sensor and display the result to the serial monitor.
        Tutorial:  http://321maker.com/e/light-sensor
        Revision Date: March 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: Click Tools, Serial Montior (Ctrl + Shift + M) to view the output.
*/
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0;      //This will store the data from the sensor.
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.

void setup() { //The Setup function runs once.
  Serial.begin(9600);

  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.
  data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
  Serial.print("Light value =");
  //convert the sensor value to a percentage and store it inside a variable called data.
  data = map(data,0,1023,0,100);
  Serial.println(data);  //Print the data to the serial port.
  //when the percentage of light is less than 20, turn on red
  if(data <=20) {
    //Display Red
    digitalWrite(RGBRedPin, HIGH); //Turn on RED
    digitalWrite(RGBBluePin, LOW);  //Turn off blue
    digitalWrite(RGBGreenPin, LOW);  //Turn off green
//    delay(data);              
//    digitalWrite(RGBRedPin, LOW);  //Turn off Red
  }
  //when the percentage of light is less than 60, turn on blue
  else if(data < 60) {
    //Display Blue
    digitalWrite(RGBBluePin, HIGH); //Turn on blue
    digitalWrite(RGBRedPin, LOW);  //Turn off Red
    digitalWrite(RGBGreenPin, LOW);  //Turn off green
//    delay(data);               
//    digitalWrite(RGBBluePin, LOW);  //Turn off blue
  
  }
  //when the percentage of light is greater than 60, turn on green
  else {
    //Display Green
    digitalWrite(RGBGreenPin, HIGH); //Turn on green
    digitalWrite(RGBBluePin, LOW);  //Turn off blue
    digitalWrite(RGBRedPin, LOW);  //Turn off Red
//    delay(data);               
//    digitalWrite(RGBGreenPin, LOW);  //Turn off green
  }
  delay(1000);           //Wait 1 second (1000mS) before running again.
}
