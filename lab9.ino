/*      Chia-Ying Ho
        Title: 321Maker Experiment #009 - Humidity
        Description: This program will monitior the humidity and temperature from the DHT11 sensor and display it in the serial monitor.
        Tutorial:  http://321maker.com/e/humidity
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        DHT sensor library: https://github.com/adafruit/DHT-sensor-library/archive/master.zip
*/

#include "DHT.h"
#include "Adafruit_Sensor.h"
int DHT11Pin = 4;        //The DHT11 sensor  is connected to pin 4 of the Arduino.
int waitTime = 5000;     //The amount of time to wait between sensor reads.
DHT dht(DHT11Pin, DHT11);//Initialize the sensor.

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.


int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.

int redLED = 12;
int blueLED = 13;


int data = 0;             //This will store the data from the sensor.
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.



void setup() {
  dht.begin();  //Start the sensor.

  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.

  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);


  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
}

void loop()
{
  delay(waitTime);
  float humidity = dht.readHumidity();  //Read the humidity value from the sensor.
  float celsius = dht.readTemperature(); //Read the temperature (c) value from the sensor.
  float fahrenheit = dht.readTemperature(true); //Read the temperature (f) value from the sensor.
  float heatIndexF = dht.computeHeatIndex(fahrenheit, humidity); //Calculate the heat index (f).
  float heatIndexC = dht.computeHeatIndex(celsius, humidity, false); //Calculate the heat index (c).

  Serial.print("Humidity   (%): ");
  Serial.println(humidity );        //Display the humidity precentage.
  Serial.print("Temperature(c): ");
  Serial.println(celsius);          //Display the temperature in celsius.
  Serial.print("Heat index (c): ");
  Serial.println(heatIndexC);       //Display the heat index in celsius.
  Serial.print("Temperature(f): ");
  Serial.println(fahrenheit);       //Display the temperature in fahrenheit.
  Serial.print("Heat index (f): ");
  Serial.println(heatIndexF);       //Display the heat index in fahrenheit.



  level3a(celsius);
  level3b(humidity);
  level4(A0, humidity);




}

double dewPoint(double celsius, double humidity) {
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity * 0.01);
  double dP = (b * temp) / (a - temp);
  return dP;
}

void level3a(double celsius) {

  if (celsius >= 25.0) {
    digitalWrite(redLED, HIGH); //Turn on RED
    digitalWrite(blueLED, LOW); //Turn on RED

  }
  else {
    digitalWrite(blueLED, HIGH); //Turn on RED
    digitalWrite(redLED, LOW); //Turn on RED

  }
}

void level3b(double humidity) {
  if (humidity < 50.0) {
    digitalWrite(RGBGreenPin, HIGH); //Turn on RED
    digitalWrite(RGBBluePin, LOW); //Turn on RED
  }
  else {
    digitalWrite(RGBBluePin, HIGH); //Turn on RED
    digitalWrite(RGBGreenPin, LOW); //Turn on RED
  }
}

void level4(int rotationPin, double humidity) {
  int data = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
  data = map(data, 0, 1023, 0, 255);
  if (humidity >= data) {
    tone(5, 2000, 50);          //Play a tone of 2000Hz for 50 milliseconds.
  }
  Serial.println("data: ");
  Serial.println(data);
}
