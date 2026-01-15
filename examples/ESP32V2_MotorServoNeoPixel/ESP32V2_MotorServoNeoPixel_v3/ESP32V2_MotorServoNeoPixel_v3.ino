/* Test code for TDF 2025
 */

#include <ESP32Servo.h>  //ESP32 Servo library
#include <L298N.h>  	// L298N Hbridge library
#include <Adafruit_NeoPixel.h>  // NeoPixel library

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int servoPin = 14; // Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 

// L298 Pin definitions
const unsigned int IN1 = 15;
const unsigned int IN2 = 33;
const unsigned int EN = 32;

// Create one motor instance
L298N motor(EN, IN1, IN2);

// Neopixel Pin definitions
#define PIN        12 // Data IN pin
#define NUMPIXELS 8 // NeoPixel stick size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define pixelDelay 500 // Time (in milliseconds) to pause between pixels
#define servoDelay 50 // Time (in milliseconds) to pause between pixels
#define midpoint 86  // servo middle point

void setup() {
	  Serial.begin(9600);   // Used to display information
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 500, 2500); // attaches the servo pin to the servo object
																				// default = min/max of 1000us and 2000us 
																				// different servos may require different min/max settings for an accurate 0 to 180 sweep

  motor.setSpeed(160); 	// Set initial motor speed
	
	pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
	pixels.setBrightness(100); // set neopixel brightness 0-255
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
		pixels.show();
		delay(2000);

	//motor forward
	motor.forward(); 	// Tell the motor to go forward (may depend by your wiring)

		//Servo sweep
	for (pos = 20; pos <= midpoint; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(servoDelay);             // waits 15ms for the servo to reach the position
	}
		motor.stop(); 	

	// //more pink
	for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(150, 0, 50)); // 127 = 50% of max brightness >> also 50% current draw
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(pixelDelay); // Pause before next pass through loop
  }

	//Servo sweep
	for (pos = midpoint; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(servoDelay);             // waits 15ms for the servo to reach the position
	}

	pixels.clear(); // Set all pixel colors to 'off'
		pixels.show();
		delay(2000);

	// motor reverse
	motor.backward(); // Tell the motor to go backward (may depend by your wiring)

		//Servo reverse sweep
	for (pos = 150; pos >= midpoint; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(servoDelay);             // waits 15ms for the servo to reach the position
	}

	motor.stop();

	//more Blue
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  pixels.setPixelColor(i, pixels.Color(50, 0, 150));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(pixelDelay); // Pause before next pass through loop
  }

	//Servo reverse sweep
	for (pos = midpoint; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(servoDelay);             // waits 15ms for the servo to reach the position
	}


}
