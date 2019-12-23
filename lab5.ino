/*      Chia-Ying Ho
        Title: 321Maker Experiment #005 - Temperature Sensor
        Description: This program will read the data from the temperature sensor. Convert the data to a temperature and display the temperature to the serial monitor in both Celsius and Fahrenheight
        Tutorial:  http://321maker.com/e/temperature-sensor
        Revision Date: March 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: Click Tools, Serial Montior (Ctrl + Shift + M) to view the output.
*/

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 1000;  //Wait

int RGBRedPin = 12;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBBluePin = 13;  //The blue RGB LED is connected pin 11 of the Arduino.



void setup(void) {    //The Setup function runs once.
  Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.

  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
  
}

void loop(void) { //The loop function runs forever.
  data = analogRead(tempPin);        //Read from the temperature sensor
  Serial.print("Sensor reading = "); //Serial.print displays to the Serial Monitor.
 // Serial.println(data);                //This is the raw analog reading

  // Calculate and display temperature.
  float temperatureC = (5.0 * data * 100.0) / 1024;
  Serial.print(temperatureC); Serial.println(" degrees C");

  // Convert temperature to Fahrenheight and display.
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");


  if(temperatureC < 23.5) {
      digitalWrite(RGBRedPin, HIGH); //Turn on RED
      digitalWrite(RGBBluePin, LOW);//TURN OFF BLUE
  }
  else {
      digitalWrite(RGBBluePin, HIGH);//Turn on Blue if the temperature is below 25 degree.  
      digitalWrite(RGBRedPin, LOW); //Turn on RED
  }

  
  delay(waitTime); //Wait waitTime before running again.
}

//alvira.narshidani@georgiancollege.ca
