/*
 Sudhu Tewari 31 Jan 2026 - code for MDes Prototyping Spring 2026

 modified from AdafruitLSM9DS1 library - Simple Magnetometer example code created 10 Jul 2019 by Riccardo Rizzo 

  This example reads the magnetic field values from the LSM9DS1
  sensor and continuously prints them to the Serial.
  Uses x and y values to find compass heading and lights 
  onboard NeoPixel green when in range of due north.

*/

#include <Arduino_LSM9DS1.h>
#include <Adafruit_NeoPixel.h>

// Define the NeoPixel pin and number of pixels
#define PIN_NEO_PIXEL 0      // Pin 0 for the onboard NeoPixel on many Adafruit ESP32 boards
#define PIXEL_COUNT 1        // There is one onboard NeoPixel

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most boards use 0)
// Parameter 3 = pixel type flags, add NEO_KHZ800 (800 KHz) or NEO_KHZ400 (400 KHz) as appropriate
Adafruit_NeoPixel pixels(PIXEL_COUNT, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

    // Initialize the NeoPixel strip object
  pixels.begin(); 
  // Set the brightness (optional, 0-255)
  //pixels.setBrightness(50); // Set brightness to ~20% (50/255)
  pixels.setBrightness(20); // Set brightness to very not bright
  // Turn off all pixels initially
  pixels.show(); 

  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.print(z);

    // code copied from chatGPT: 
      float heading = atan2(y, x);  //gives you the heading in radians:   
      /*    0 = east
            π/2 = north
            π = west
           -π/2 = south
      */
      int headingDegrees = heading * 180.0 / PI;
      if (headingDegrees < 0) headingDegrees += 360;
      /*
            0° = East
            90° = North
            180° = West
            270° = South
      */
    // end - code copied from chatGPT:  

        Serial.print('\t'); 
        Serial.print(heading); 
        Serial.print('\t'); 
        Serial.print(headingDegrees);

  //   //Test code - make green brightness proportional to NORTH
  //   int brightness = map(north, 0, 24, 255, 0);
  //    pixels.setPixelColor(0, pixels.Color(255-brightness, brightness, 0)); // 
  //    pixels.show();   // Update the NeoPixel to show the color

    int range = 5;  // set range of activation for North -> +- 5 degrees
    if(headingDegrees>90-range && headingDegrees<90+range){
     pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // set NeoPixel color to GREEN
     pixels.show();   // Update the NeoPixel to show the color
     Serial.println("\t NORTH ========================="); // print to serial monitor
    } else {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // set NeoPixel color to RED
     pixels.show();   // Update the NeoPixel to show the color
     Serial.println("\t NOT NORTH"); // print to serial monitor
    }

  }

}
