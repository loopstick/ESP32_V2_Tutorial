/* Test code for TDF 2025
 */

#include <ESP32Servo.h>  //ESP32 Servo library
#include <L298N.h>  	// L298N Hbridge library

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int servoPin = 14; // Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 

// L298 Pin definitions
const unsigned int IN1 = 15;
const unsigned int IN2 = 33;
const unsigned int EN = 32;

// Create one motor instance
L298N motor(EN, IN1, IN2);

void setup() {
	  Serial.begin(9600);   // Used to display information
	// Allow allocation of all timers
	// ESP32PWM::allocateTimer(0);
	// ESP32PWM::allocateTimer(1);
	// ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 500, 2500); // attaches the servo pin to the servo object
																				// default = min/max of 1000us and 2000us 
																				// different servos may require different min/max settings for an accurate 0 to 180 sweep

	// Set initial motor speed
  motor.setSpeed(150);
}

void loop() {

  //motor forward
	motor.forward(); 	// Tell the motor to go forward (may depend by your wiring)

	//Servo sweep
	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(15);             // waits 15ms for the servo to reach the position
	}

	// motor reverse
	motor.backward(); // Tell the motor to go backward (may depend by your wiring)

	//Servo reverse sweep
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(15);             // waits 15ms for the servo to reach the position
	}

}

