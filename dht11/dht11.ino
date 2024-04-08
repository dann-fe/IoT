/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 11: Temperature and humidity measurement and display
* Through the DHT11 measurement module to obtain the temperature and humidity, and display on the digital tube. 
*
* The following functions are available:
* dht.begin();//DHT11 initialization
* dht.readTemperature(); // get the temperature value, and return float-point number 
* dht.readHumidity(); // get the Humidity value, and return float-point number 

* displayTemperature(int8_t temperature); // display temperature, at the end of the value of the word added "C" is the degree of Celsius
* displayHumidity(int8_t humi); // display humidity, at the end of the value of the word added "H"

* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
************************************************** ************************************************** *****/

#include <Wire.h>

#include "RichShieldDHT.h"
#include "RichShieldTM1637.h"
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

DHT dht;

void setup() {
	disp.init();  
	dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    disp.display(h);
    delay(2000);
    disp.display(t);
    delay(2000);
  
}
