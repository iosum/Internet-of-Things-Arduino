/*      Chia-Ying Ho
        Title: 321Maker Experiment #011 - LCD
        Description: This program will display 321Maker on the serial LCD.
        Tutorial:  http://321maker.com/e/011-lcd
        Revision Date: October 12, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield, 1602 Serial LCD
        Serial LCD library: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/NewliquidCrystal_1.3.4.zip
*/
//Load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "Adafruit_Sensor.h"


//Define address for the Serial LCD display.
#define I2C_ADDR  0x27  //If 0x3f doesn't work change this to 0x27
#define BACKLIGHT_PIN  3


int DHT11Pin = 4;        //The DHT11 sensor  is connected to pin 4 of the Arduino.
DHT dht(DHT11Pin, DHT11);//Initialize the sensor.
int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int waitTime = 5000;     //The amount of time to wait between sensor reads.
int button1 = 2;

int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0;      //This will store the data from the sensor.
int count = 0;
int old_count = 99;

char my_name[8] = {'C', 'H', 'I', 'A', 'Y', 'I', 'N', 'G'};

//Initialise the Serial LCD.
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7); //These pin numbers are hard coded in on the serial backpack board.

void setup()
{
  lcd.begin (16, 2);    //Initalize the LCD.
  lcd.setBacklightPin(3, POSITIVE); //Setup the backlight.
  lcd.setBacklight(HIGH); //Switch on the backlight.
  lcd.clear();


  dht.begin();  //Start the sensor.


  delay(1000);

}

void loop() {

  delay(waitTime);
  //  float humidity = dht.readHumidity();  //Read the humidity value from the sensor.
  //  float celsius = dht.readTemperature(); //Read the temperature (c) value from the sensor.
  //  data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
  //  data = map(data, 0, 1023, 0, 100);
  //
  //
  //
  //  lcd.clear();
  //  //Choosing the first line and row
  //  lcd.setCursor(0, 0);
  //  //Typing Temp: to the first line starting from the first row
  //  lcd.print("Temp: ");
  //  //Typing the temperature readings after "Temp: "
  //  lcd.print((int)celsius);
  //  lcd.setCursor(10, 0);
  //  lcd.print("l: ");
  //  lcd.print(data);
  //  //Choosing the second line and first row
  //  lcd.setCursor(0, 1);
  //  //Typing Humidity(%): to the second line starting from the first row
  //  lcd.print("Humidity(%): ");
  //  //Typing the humidity readings after "Humidity(%): "
  //  lcd.print((int)humidity);

  //
  //  for(int i=0; i<8; i++){
  //    lcd.clear();
  //    lcd.setCursor(i,0);
  //    lcd.print("chiaying");
  //    delay(500);
  //  }
  //
  //  for(int i=8; i>=0; i--){
  //    lcd.clear();
  //    lcd.setCursor(i,0);
  //    lcd.print("chiaying");
  //    delay(500);
  //  }
  //

  //demo lab 10 levcel 3a

  //check the button
  if (digitalRead(button1) == LOW) {
    //increment a variable
    count = count + 1;
    delay(300);
    if (count > 2) {
      count = 0;
    }
  }
  //check if new count value
  if (count != old_count) {
    //use variable to determine what to print out
    if (count == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("chiaying");
      delay(300);
    }
    else if (count == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("sports");
      delay(300);
    }
    else if (count == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("pizza");
      delay(300);
    }
    // we;ve "used" the count variable make it old
    old_count = count;
  }
}
