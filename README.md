### Hands-on ESP32v2 Tutorial

**This tutorial created by Sudhu Tewari 2025, revised 2026**
 - building on materials originally created by: Michael Shiloh and Judy Castro for *Teach Me To Make*

#### Tutorial overview
The tutorial will focus on getting you up and running quickly, so that you will understand the basic procedures for working with your ESP32 (specifically the [Adafruit ESP32 Feather v2](https://www.adafruit.com/product/5400)) and the Arduino IDE and can explore further on your own.

We will cover how to install Arduino on your laptop; how to understand, modify, and write Arduino programs; how to connect input devices and sensors to your ESP32 and read them from a program; and how to connect actuators (LEDs, motors, speakers) and control them from a program. Other topics will be covered as interest dictates and time permits.

#### Additional Resources
What is Arduino anyway?
 - Read about Arduino: https://www.arduino.cc/en/Guide/Introduction

What is ESP32?
 - read up on [ESP32 on Wikipedia](https://en.wikipedia.org/wiki/ESP32)
 - Check out the [ESP32 datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
	from [espressif](https://www.espressif.com/en/products/hardware/esp32/overview)

### Start Here
- Read: Adafruit's ESP32 Feather V2 [Overview and Get Started Tutorial](https://learn.adafruit.com/adafruit-esp32-feather-v2)
  - download as [PDF](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-esp32-feather-v2.pdf)
- Install Arduino IDE
  - Arduino software (IDE) runs on Windows, Mac OSX, and Linux.
  - Please download and install the (free) Arduino software prior to the workshop from http://arduino.cc/en/Main/Software.  
- [Install ESP32 drivers and Add ESP32 to Arduino IDE Boards Manager](https://learn.adafruit.com/adafruit-esp32-feather-v2/arduino-ide-setup)
  - if you are not sure which USB-to-serial driver chip you have, install both!!
- [Add ESP32 to Arduino IDE Boards Manager](https://learn.adafruit.com/adafruit-esp32-feather-v2/arduino-ide-setup#install-esp32-board-support-package-3112219)

  <!-- - https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers -->

  <!-- - Use one of the following (whichever suits you best):
    - Random Nerd Tutorials [Installing the ESP32 Board in Arduino IDE](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
    - Espressif's github [arduino-esp32 install instructions](https://github.com/espressif/arduino-esp32#installation-instructions)
    - ESP32 URL: https://dl.espressif.com/dl/package_esp32_index.json - for Boards Manager install
      - Board Manager: Tools > Board > Boards Manager
      - search for ESP32 - install ESP32 by Espressif Systems
      -->


#### First steps: Verifying correct installation

1. Connect ESP32 via USB cable
   - Windows? Might see “New Hardware Discovered” and later might see “New Hardware Ready for Use”.
   - Mac OS X? Might see “New Network Interface Found”. Click “Network Preferences…”,  click “Apply”, and when it finishes, click “Close”. It doesn’t matter if the configuration fails.
   - Linux? Nothing to do here

2. Open Arduino software (IDE)

3. Select _Tools -> Board_
   - You have a Adafruit ESP32 Feather.

4. Select _Tools -> Serial Port_
   - Windows? Chose the largest COM number
     - No COMs? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Mac OS X? Choose dev/cu.usbserial******* or /dev/cu.SLAB_USDtoUART
     - No dev/cu? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Linux? There is only one choice

5. Open _File->Examples->Basics->Blink_
   - Click “Upload”
   - Look for errors in the bottom window of the program
     - Errors? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Look for an amber LED blinking rapidly and a red LED blinking slowly on the other side of the USB connector
     - No blinking? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)



### Is this thing really on?
Copy the code below into a new Arduino sketch or download and open this example sketch: [HelloWorld.ino](/examples/HelloWorld/HelloWorld.ino)


```cpp
/*
  Hello World
  A "Hello, World!" program generally is a computer program that
	outputs or displays the message "Hello, World!".
	Such a program is very simple in most programming languages,
	and is often used to illustrate the basic syntax of a programming language.
	It is often the first program written by people learning to code
*/

void setup() {
//initialize serial communications at 9600 baud rate
Serial.begin(9600);
}

void loop(){
//send 'Hello, world!' over the serial port
Serial.println("Hello, world!");
//wait 100 milliseconds so we don't drive ourselves crazy
delay(1000);
}
```
The _Serial_ commands allow Arduino to send a message to your laptop. In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner.

a little code anatomy:
- the [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function is called when a sketch starts.
  - Use it to initialize variables, pin modes, start using libraries, etc.
  - The setup() function will only run once, after each powerup or reset of the Arduino board.

- the [loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) function does precisely what its name suggests, and _loops_ consecutively through your list of instructions to control the Arduino.
  - Arduino only executes one instruction at a time


More on specific functions and variables soon! Let's make something happen in the real world first.


### How to use Arduino to turn something ON and OFF
How does the program (sketch) do this? (all described in the [Blink tutorial](http://arduino.cc/en/Tutorial/Blink))
some more code anatomy - info about Arduino [Sketches](https://docs.arduino.cc/learn/programming/sketches/)

```cpp
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduino boards have an on-board LED you can control.
  On the ESP32 Feather V2 it is attached to digital pin 13

  This example code is modified from.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int led = 13;  // define a variable to hold the pin number of the internal LED

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin "led" as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```
Where is the LED that we're turning on and off???
![feather v2 builtin LED](/images/ESP32V2_internalLED.png)

##### Exercise:
- combine HelloWorld and Blink to make a program that shows it's working with physical and digital output.

### using the onboard NeoPixel -
The ESP32v2 Feather has a built-in neopixel, an addressable RGB LED. This can be very useful as a status indicator or debug tool.

Where is the neoPixel?
![feather v2 builtin LED](/images/ESP32V2_neoPixel.jpg)

- more information about neoPixels: [Adafruit NeoPixel Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)

Let's blink the neoPixel!!
- download sketch here: [ESP32V2_Blink_NeoPixel_simple](/examples/ESP32V2_Blink_NeoPixel_simple/ESP32V2_Blink_NeoPixel_simple.ino)

or copy below:
```cpp
#include <Adafruit_NeoPixel.h>

// Define the NeoPixel pin and number of pixels
#define PIN_NEO_PIXEL 0      // Pin 0 for the onboard NeoPixel on many Adafruit ESP32 boards
#define PIXEL_COUNT 1        // There is one onboard NeoPixel

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most boards use 0)
// Parameter 3 = pixel type flags, add NEO_KHZ800 (800 KHz) or NEO_KHZ400 (400 KHz) as appropriate
Adafruit_NeoPixel pixels(PIXEL_COUNT, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  // Initialize the NeoPixel strip object
  pixels.begin();
  // Set the brightness (optional, 0-255)
  //pixels.setBrightness(50); // Set brightness to ~20% (50/255)
  // Turn off all pixels initially
  pixels.show();
}

void loop() {
  // Set the first pixel (index 0) to red (R, G, B)
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();   // Update the NeoPixel to show the color
  delay(500);      // Wait for 500 milliseconds

  // Turn the pixel off
  pixels.clear();  // Set all pixel colors to off
  pixels.show();   // Update the NeoPixel
  delay(500);      // Wait for 500 milliseconds
}
```

##### Exercises:
- Blink red, green, blue
  - [ESP32V2_Blink_NeoPixel_RGB](/examples/ESP32V2_Blink_NeoPixel_RGB/ESP32V2_Blink_NeoPixel_RGB.ino)
- cycle through ALL the colors
  - [ESP32V2_NeoPixel_SingleNumColor_v1](/examples/ESP32V2_NeoPixel_SingleNumColor_v1/ESP32V2_NeoPixel_SingleNumColor_v1.ino)

*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

## Mdes Prototyping - Human Augmentation project diverges here!!
- [Prototyping with Stemma QT modules](https://github.com/loopstick/ESP32_V2_Tutorial/blob/master/StemmaQT/README.md)

*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=

### Connecting to your Microcontroller - Pinouts
In order to connect inputs or outputs to your microcontroller you need to know where the GPIO (general-purpose input/output) pins are!

 - [ESP32 V2 pinouts](https://learn.adafruit.com/adafruit-esp32-feather-v2/pinouts)

![feather v2 pinout](/images/adafruit_products_FV2_pinouts_guide.jpg)

![feather v2 pinout](/images/adafruit_products_Adafruit_ESP32_Feather_V2_Pinout.png)

<!--
![feather_pinouttop](/images/feather_pinouttop.jpg)
![feather_pinoutbot](/images/feather_pinoutbot.jpg)
![adafruithuzzah32pin](/images/adafruithuzzah32pin.jpg)
![adafruithuzzah32pin](/images/adafruithuzzah32_bigger.jpg)
-->



### Using a Solderless Breadboard to connect your microcontroller to other things (LEDs, motors, speakers, sensors, etc.)

The Solderless Breadboard
- [Breadboards for Beginners](https://learn.adafruit.com/breadboards-for-beginners/breadboards)
- [How to use a Breadboard tutorial](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard)
- [Breadboard connections](http://wiring.org.co/learning/tutorials/breadboard/)

![Breadboard](/images/Breadboard_st.jpg)

![Breadboard underside](/images/BreadboardUnderside_st.jpg)

<!-- ![Breadboard top and bottom](/images/breadboardTopBottom.mp4) -->

![Breadboard top and bottom](https://cdn-learn.adafruit.com/assets/assets/000/035/419/original/components_halfbb.gif?1472966532)


Use the breadboard to add an external LED.
- LEDs must always be used with resistors so they don’t burn out.
  - The resistor value can be anywhere from 100 ohm to 1k ohm.
    - The lower the resistance, the brighter the light.
    - Evil Mad Scientist explains it well [here](https://www.evilmadscientist.com/2012/resistors-for-leds/)
  - Resistor Color Code!
    - [Learn the Resistor Color Code in in 5 minutes](http://www.resistorguide.com/resistor-color-code/)

    ![ResistorColorCode](/images/ResistorColorCode.png)

- LEDs are polarized
  - [identifying LED polarity](https://www.youtube.com/watch?v=SRDgNR_yCms)

  ![led_example](/images/led_example.png)


Here’s a picture showing how to connect the LED and resistor on the breadboard:

![LED_Breadboard2](/images/ESP32_LED.jpg)

Here is another view of this circuit:

![ESP32_LED_01](/images/ESP32_LED.png)


Use the Blink sketch: _File -> Examples -> Basics -> Blink_

Does the LED on the breadboard blink?
		(think about why)

##### Exercise:
Move LED to a different pin (e.g. pin 12).
	See if you can figure out how to do this on your own

Now the LED won’t blink until you change the program, since the program is only turning pin 13 on and off. Change the program to control pin 8.

##### Exercise:
If you changed the program to control only pin 8, then the built-in LED on pin 13 is no longer blinking. Can you change the program to make them both blink?

Are we limited to LEDs? No; we could replace the LED (and its resistor) with any other suitable device, with some considerations. We’ll learn more about this later.

### How to read a switch from a GPIO: digitalRead()
- Switches
  - [What is a Switch?](https://learn.sparkfun.com/tutorials/switch-basics/what-is-a-switch)
  - [Switch Types](https://www.allaboutcircuits.com/textbook/digital/chpt-4/switch-types/)
- digitalRead()
  - _Arduino->File->Examples->Basics->DigitalReadSerial_
  - [Digital Read Serial](http://arduino.cc/en/Tutorial/DigitalReadSerial) tutorial

  ![ESP32_BTN_LED](/images/ESP32_BTN_LED.png)

  ```cpp
  /*
  DigitalReadSerial
  Reads a digital input on pin A0, prints the result to the Serial Monitor
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
  */

	// A0 has the pushbutton attached to it. Give it a name:
	int pushButton = A0;

	// the setup routine runs once when you press reset:
	void setup() {
 	 // initialize serial communication at 9600 bits per second:
  	Serial.begin(9600);
 	 // make the pushbutton's pin an input:
  	pinMode(pushButton, INPUT);
	}

	// the loop routine runs over and over again forever:
	void loop() {
 	 // read the input pin:
  	int buttonState = digitalRead(pushButton);
 	 // print out the state of the button:
 	 Serial.println(buttonState);
 	 delay(1);        // delay in between reads for stability
	}
   ```

   - see [examples/DigitalRead/DigitalRead.ino](/examples/DigitalRead/DigitalRead.ino)


##### Exercises:
- Write an IF statement to turn the LED on when the button is pushed.
  - [DigitalRead_LED](/examples/DigitalRead_LED/DigitalRead_LED.ino)
- Write an IF statement to toggle the LED when the button is pushed a certain number of times.
  - [DigitalRead_Toggle](/examples/DigitalRead_Toggle/DigitalRead_Toggle.ino)






### How to use a sensor: analogRead()
So far we’ve only used Arduino as an output device, to control something in the physical world (the LED). The other way of interfacing to the physical world is as an input device, using a sensor to get information about the physical world. We’ll start with a photoresistor, also called a light dependent resistor or LDR. It’s a resistor whose resistance depends on the light: the more light, the lower the resistance. (The resistor we used above with the LED is a fixed resistor.)
The LDR indicates the amount of light by changing its resistance, but Arduino can not measure resistance. But, Arduino can measure voltage! Fortunately, we can easily convert a varying resistance to a varying voltage using a fixed resistor to create a [voltage divider](https://learn.sparkfun.com/tutorials/voltage-dividers/all). This time the fixed resistor needs a larger resistance, so select a 10k ohm resistor and build the circuit below. You don’t need to remove the LED circuit as there should be room on your breadboard for both, and we’ll use the LED again later.

![CircuitExample](/images/ESP32_LDR_LED.png)

Open and upload this sketch:
_File->Examples->Basics->AnalogReadSerial_

How do you know if anything is working? Arduino might be reading the sensor, but is it telling you anything?

Arduino is connected to your computer, so they can communicate - just like we did earlier with Hello World, but now your Ardunio is sending sensor DATA!
 - this line:	```cpp Serial.println(sensorValue);``` allows Arduino to send a message to your laptop.
In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner. Read the Arduino [AnalogRead tutorial](http://arduino.cc/en/Tutorial/AnalogReadSerial) to find out more. Also see _File->Examples->Communication_ for more examples of other types of Serial communication).

Now that we've got sensor data coming in (as a range of values) what can we do with the data?

- ESP32 can measure varying voltage levels between 0 V and 3.3 V.
  - The voltage measured is assigned to a value between 0 and 4095
    - 0V corresponds to 0, and 3.3V corresponds to 4095.
    - Any voltage between 0 V and 3.3 V will be given the corresponding value.
  - We could do some math to calculate the voltage we're measuring:
_File->Examples->Basics->AnalogReadVoltage_
    - _we'll need to do some different math to re-configure the stock Arduino example for ESP32_
      - Arduino inputs range from 0-1024

That's nice, but what if we want to use the sensor data to control some kind of physical reaction (light, heat, motion) to the data?

##### Exercise:
Use an IF statement to turn your LED on and off according to the data coming from the LDR.

  - see [examples/AnalogRead_If/AnalogRead_If.ino](/examples/AnalogRead_If/AnalogRead_If.ino)

What other kinds of sensors are there?
- [Sensor workshop at ITP](https://itp.nyu.edu/physcomp/lessons/sensors-the-basics/)

**IMPORTANT NOTE:**
- When looking for sensors to use
  - be aware that ESP32 is a 3.3V system.
  - Many microcontrollers and sensors are made to run on 5v
    - **5V WILL KILL YOUR ESP32!**
  - It is possible to convert 5V sensor outputs to 3.3v
    - [How to Level Shift 5V to 3.3V](https://randomnerdtutorials.com/how-to-level-shift-5v-to-3-3v/)
  - It is even easier to use 3.3V compatible sensors
    - Try searching on Adafruit for [“3.3v sensor”](https://www.adafruit.com/?q=3.3v%20sensor&p=5)


#### More on Sensors in the near future
Let's shift our focus, now, for a moment, to outputting a range of voltages. Then we'll put the input and output together to get real world input to control real world output.

- see some additional Sensor Resources here: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/using-a-pir-w-arduino

### Sensor ranges, calibration, and mapping
- useful Arduino functions
  - [map()](https://www.arduino.cc/reference/en/language/functions/math/map/)
  - [constrain()](https://www.arduino.cc/reference/en/language/functions/math/constrain/)


### analogWrite(): Controlling speed or brightness
- If digitalWrite() can turn an LED on and off, and analogRead() can read a range of values, what would you guess _analogWrite()_ might do?
  - You guessed it!
- analogWrite outputs [PWM](https://www.arduino.cc/en/tutorial/PWM)
  - PWM = pulse width modulation
  - this allows us, effectively, to output any voltage between minimum
    - minimum = 0 volts = 0 in code
    - maximum = 3.3 volts (ESP32) = 255 (@8bit resolution)

- Arduino: _analogWrite()_ only works on certain pins.
    - see the [Arduino Uno Board Pins reference](https://www.arduino.cc/en/Reference/Board) for more info

- **ESP32 can output PWM on ANY pin.**

### Analog Output - PWM - Major Difference between Arduino and ESP32

  - ESP32 uses different functions to call PWM output
    - ``` ledcAttachPin(GPIO, channel)```
    - ``` ledcWrite(channel, dutycycle)```

  - 16 PWM channels (0-15)
    - variable PWM frequency (5000 is plenty for LEDs)
    - variable duty cycle
      - 8 bits = 0-255
      - this is how you control the intensity of the output

```cpp
/*
 * PWM example code
 */

// the number of the LED pin
const int ledPin = 12;  // 12 corresponds to GPIO16

// setting PWM properties
// variable PWM frequency (5000 is plenty for LEDs)
const int freq = 5000;
// 16 PWM channels available (0-15)
const int ledChannel = 0;
// 8 bits = 0-255
const int resolution = 8;

void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}

void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}
```
  - see [examples/PWM/PWM.ino](/examples/PWM/PWM.ino)

##### Exercises:
- Fade your LED according to the data from an LDR.
  - [examples/AnalogRead_LDR_LED/AnalogRead_LDR_LED.ino](/examples/AnalogRead_LDR_LED/AnalogRead_LDR_LED.ino)


### ESP32_AnalogWrite
- This handy library allows us to use the analogWrite() function
  - ``` provides an analogWrite polyfill for ESP32 using the LEDC functions ```
- https://github.com/ERROPiX/ESP32_AnalogWrite
- How To:
  [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries)
  - download
    - locate .zip
  - Sketch > Include Library > Add .ZIP Library
  - Sketch > Include Library > ESP32 Analog Write

##### Exercises:
  - Fade an LED-
    - [examples/PWM_analogWrite/PWM_analogWrite.ino](/examples/PWM_analogWrite/PWM_analogWrite.ino)
  - Fade your LED with data from an LDR.
    - [examples/PWM_analogWrite_LED_LDR/PWM_analogWrite_LED_LDR.ino](/examples/PWM_analogWrite_LED_LDR/PWM_analogWrite_LED_LDR.ino)

#### RGB LEDs
RGB LEDs are really handy for non-text, non-serial debug and they make really pretty colors!

![ESP32_LED_RGB](/images/ESP32_LED_RGB.png)

- Generally we use a slightly larger resistor (150 ohm) for the RED component and the same slightly smaller resistor values (100 ohm) for the GREEN and BLUE components.
- for our circuit let's use:
  - 470 ohm for RED
    - color bands-> yellow, purple, black, black, brown
  - 430 ohm for GREEN and BLUE
    - color bands-> yellow, orange, black, black, brown
  - We're using common _CATHODE_ RGB LEDs

- [RGB LED Test Code](/examples/RGB_Test/RGB_Test.ino)
- [RGB LED code example](/examples/PWM_RGB_analogWrite/PWM_RGB_analogWrite.ino) using analogWrite()
  - [RGB LED code example](/examples/PWM_RGB/PWM_RGB.ino) using ledcWrite()

Some other online information about RGB LEDs
 - https://randomnerdtutorials.com/electronics-basics-how-do-rgb-leds-work/
 - https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/breadboard-layout
 - https://howtomechatronics.com/tutorials/arduino/how-to-use-a-rgb-led-with-arduino/

<!-- ## INTRODUCING - the ART 385 hardware platform !!!
![ESP32_Art385_Platform](/images/ESP32_Art385_Platform.png)

- Here's a layout that will allow you to use all of the components you have to write code and prototype functionality.
  - RGB LED
    - Red on pin 12
    - Green on pin 27
    - Blue on pin 33
    - common cathode to GND (ground) - the common pin is the _longest_ of all 4 legs
  - LDR (Light Dependent Resistor)
    - LDR on pin A0
      - pin 1 to 3v
      - pin 2 to A0 & 10Kohm pulldown to GND (ground)
  - Potentiometer (blue thing with knob)
      - potentiometer on pin A1
        - pin 1 to 3v
        - pin 2 to A1 (pin 2 is the middle pin)
        - pin 3 to GND (pin 1 and pin 3 are the outer pins (doesn't matter which is which))
  - Button (switch)
    - insert in parallel with LDR
      - or
    - use in place of LDR

- Art 385 Platform Test - [Color Flashing](/examples/Art385_Platform_Test/Art385_Platform_Test.ino) code
- Art 385 Platform Test - [Color Fading](/examples/Art385_Platform_Fade/Art385_Platform_Fade.ino) code
- Art 385 Platform Test - [Citrus Strawberry](/examples/Art385_Platform_CitrusStrawberry/Art385_Platform_CitrusStrawberry.ino)
-->



### Multi-Tasking - DITCH the DELAY!

 - Using delay() to control timing is probably one of the very first things you learned when experimenting with the Arduino.  Timing with delay() is simple and straightforward, but it does cause problems down the road when you want to add additional functionality.  The problem is that delay() is a "busy wait" that monopolizes the processor.

- During a delay() call, you can’t respond to inputs, you can't process any data and you can’t change any outputs.  Delay() ties up 100% of the processor.  So, if any part of your code uses a delay(), everything else is dead in the water for the duration.

  - **[Adafruit Multi-Tasking Tutorial](https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview)**

  - [Blink Without Delay Tutorial](https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay) on the official Arduino website
  - [Another](https://www.baldengineer.com/millis-tutorial.html) explanation of Blink Without Delay
  - In order to understand Blink Without Delay, it is helpful to first understand [millis()](https://www.arduino.cc/en/Reference/Millis)
  - Excellent Adafruit Multitasking [Tutorial](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all)
(highly recommended)
  - A detailed [explanation](https://programmingelectronics.com/tutorial-16-blink-an-led-without-using-the-delay-function-old-version/) of Blink Without Delay.
  - Very detailed line-by-line [explanation](https://www.baldengineer.com/blink-without-delay-explained.html)
of Blink Without Delay, with links to explanations of related concepts every step of the way.

### What else can PWM do?
- PWM also works well to control the speed of a motor.
  - However now we need to consider whether our motor is compatible with our GPIO output "levels".

### Interlude: Ohm's Law!
 - [MAKE presents: Ohm's Law](https://www.youtube.com/watch?v=-mHLvtGjum4)

### GPIO outputs: Voltage and current
- When used as outputs, two things must be considered: the voltage and the current. Our ESP32 can deliver 3.3v, and at most 12 or 28mA (250mA maximum for all channels - according to Adafruit).
- The voltage is determined by the source, but the current is determined by whatever we’re trying to control. In the case of  LEDs, they only need 20 mA or less. The motor we have might take more than 40 mA. In the worst case, when it’s stalled, it might want a 200 mA.
- The important thing to realize is that the microcontroller does not have the ability to limit this current. It will try to deliver whatever is asked of it, even if it overheats and damages itself.
- If we want to control a device that might take more than 40 mA, we have to use an intermediary.

****************************************************************************************
Can we hook it up like this, with the motor wired directly to the microcontroller??   
 - Yes!!

<img src="/examples/13_DCmotor_transistor/ESP32V2_Motor_NoTransistor.png" width="400">

- Will it probably damage the microcontroller?
  - YES! aka 爆炸!

- Should we use an intermediary to control the high current?
  - YES!!!!!
*************************************************

### Controlling large loads with a transistor
The transistor is like a bicycle gear: you control it with a small amount of current, and it in turn can control a lot more current. The transistor also allows us to use a higher voltage than the 3.3V the ESP32 can deliver.

Use a transistor to control a higher current for a motor.
 - There are hundreds of transisors that will work for this application.
   - here are a few that I commonly use:
	- [TIP120](https://cdn-shop.adafruit.com/datasheets/TIP120.pdf)
	- [IRF520](https://www.vishay.com/docs/91017/91017.pdf)
	- [IRF8721](https://cdn-shop.adafruit.com/datasheets/irlb8721pbf.pdf)
  - never assume the pinout of a transistor or IC.
    - ALWAYS look up the pinout before applying power.
      - or else 爆炸

Here's the pinout for a TIP 120 Darlington transistor, rated for up to 60V and 5A

<img src="/examples/13_DCmotor_transistor/Tip120.png" width="400">

<img src="/examples/13_DCmotor_transistor/ESP32V2_Motor_Transistor_bb.png" width="650">

You can test this with any of the code above for driving an LED:
 - just send an analogWrite to pin 12.

It's important to note that we are now using USB as the power source for the motor.
 - For small motors this is probably okay.
 - For larger motors that require more current (>500ma), your computer will probably complain about a device using too much power and will disconnect the USB.
 - It is a much better practice to get in the habit of using a separate power source for the motor.

<img src="/examples/13_DCmotor_transistor/ESP32V2_Motor_Transistor_PwrSply.png" width="750">


#### References:
- [Arduino Transistor Motor Control](https://www.arduino.cc/en/Tutorial/TransistorMotorControl)
- [Using a Transistor to Control High Current Loads](http://itp.nyu.edu/physcomp/labs/motors-and-transistors/using-a-transistor-to-control-high-current-loads-with-an-arduino/)

*******************************************************************************
### H-Bridge Motor Driver
- The H-Bridge is a circuit that allows us to control the direction of a motor as well as its speed.

![Hbridge GIF](/images/Hbridge/Hbridge.gif)

### L298N H-Bridge Motor Driver
- The L298N is a popular H-Bridge motor driver that can be used with the Arduino.
- The L298N has 2 H-Bridges, which means it can control 2 motors.
- The L298N can handle up to 2A per channel, and up to 35V.
<!-- - The L298N has a built-in 5V regulator, so it can be used to power the Arduino.
- The L298N has a built-in diode to protect against voltage spikes from the motor.
- The L298N has a built-in heat sink, so it can handle a lot of power without overheating.
- The L298N has a built-in current sense resistor, so it can detect when the motor is stalled. -->

  <img src="/examples/ESP32V2_DCmotor_Hbridge/dual-h-bridge-motor-driver-l298n-44325-750x750.jpg" width="450">

notes:
- on many L298N modules, the power input is labeled 12v
  - but it can handle up to 35v
  - and it can run as low as 4.5v

- since motors take a significant amount of current, we'll use a separate power source for the motor(s)
  - this external source can be a power supply or a battery pack (or USB for SMALL motors)
  - the microcontroller will send data to the Hbridge to switch on/off the larger voltage/current
- We can power the motor(s) with an external power supply      
  - match the power supply voltage to the motor voltage
  - you'll also need to consider the motor's current draw and provide sufficient amperage
  - the manufacturer's specification should provide this information

  <img src="/images/powerSupply.jpg" width="350">

### L298N H-Bridge Motor Driver with 5v
  When using 5V or less for motor voltage (muscles) or less we must also provide 5V to the L298 IC (brains).
  - we can get 5v from the USB pin on our ESP32V2
    - note: this only works if you have USB connected to a USB power source (computer or charging brick)

  <img src="/examples/ESP32V2_DCmotor_Hbridge/ESP32V2_Hbridge_1Motor_5V.png" width="750">

### L298N H-Bridge Motor Driver with 7-24V

- When using more than 7V the L298N can get the 5v it needs to operate from an onboard voltage regulator
    - most voltage regulators need about 2v more than their output voltage
        - in this special case we can --probably-- use the L298's onboard voltage regulator to provide 5V for our ESP32

<img src="/examples/ESP32V2_DCmotor_Hbridge/ESP32V2_Hbridge_1Motor_7V.png" width="750">

ESP32V2_L298N_Simple

Hbridge example code:
  - FIRST -> install the [L298N library](https://github.com/AndreaLombardo/L298N) by Andrea Lombardo
  - [ESP32V2_L298N_Simple.ino](/examples/ESP32V2_DCmotor_Hbridge/ESP32V2_L298N_Simple/ESP32V2_L298N_Simple.ino))

*******************************************************************************
### NeoPixels (low-current)

NeoPixels are individually addressable (WS2812B) RGB LEDs that can be chained together to create a string of lights. They are very bright and can be used to create a wide range of colors. They are available in a variety of form factors, including strips, rings, and matrices. They are typically controlled by a single data line and can be powered by 5V. That said, our Arduino can only supply a limited amount of current, so we need to be careful when powering neoPixels.  

If you want to understand addressable LEDs (aka neoPixels), read this guide!!
- [Adafruit NeoPixel Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide)

<img src="/images/neopixel_Stick_cropped.jpg" width="650">

We can start with a simple test to get familiar with the NeoPixel library. When we're ready to control larger numbers of NeoPixels, we'll need to consider power requirements and how to power them safely.

<img src="/examples/12_NeoPixel/ESP32V2_NeoPixel_stick_noBB.png" width="750">

NeoPixel example code:
  - FIRST -> install the Adafruit [NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library
  - [12a_NeoPixel_simpleTest.ino](/examples/12_NeoPixel/12a_NeoPixel_simpleTest/12a_NeoPixel_simpleTest.ino)
    - [12b_NeoPixel_strandtest.ino](/examples/12_NeoPixel/12b_NeoPixel_strandtest/12b_NeoPixel_strandtest.ino)
    <!-- CoPilot suggestions
    - [12c_NeoPixel_rainbowCycle.ino](/examples/12_NeoPixel/12c_NeoPixel_rainbowCycle/12c_NeoPixel_rainbowCycle.ino)
    - [12d_NeoPixel_Potentiometer.ino](/examples/12_NeoPixel/12d_NeoPixel_Potentiometer/12d_NeoPixel_Potentiometer.ino)  - potentiometer controls brightness
    - [12e_NeoPixel_PIR.ino](/examples/12_NeoPixel/12e_NeoPixel_PIR/12e_NeoPixel_PIR.ino) - PIR motion sensor triggers rainbow cycle
    - [12f_NeoPixel_Ultrasonic.ino](/examples/12_NeoPixel/12f_NeoPixel_Ultrasonic/12f_NeoPixel_Ultrasonic.ino) - ultrasonic distance sensor controls number of lit pixels
    - [12g_NeoPixel_SoundSensor.ino](/examples/12_NeoPixel/12g_NeoPixel_SoundSensor/12g_NeoPixel_SoundSensor.ino) - sound sensor controls brightness
    - [12h_NeoPixel_RGB.ino](/examples/12_NeoPixel/12h_NeoPixel_RGB/12h_NeoPixel_RGB.ino) - RGB LED controls NeoPixel color
    -->

If you are using more than 8 neopixels you must power them with an external power supply!
  - or else 爆炸

<img src="/examples/12_NeoPixel/ESP32V2_NeoPixel_strip2_bb.png" width="750">

Also, it is very worthwhile to follow the [Best Practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices) given in the [Adafruit NeoPixel Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide)


*******************************************************************************
### Servo

Servo motors are a simple and easy way to add motion to your Arduino project.
- They 'know' their own position which makes them easy to control
- they are not _that_ powerful (although larger, more power servos _do_ exist)

<img src="/images/Servo.jpg" width="350"> <img src="/images/Servo_diagram.jpg" width="450">

Servo motors have three wires: power, ground, and signal. The power wire is typically red, the ground wire is typically black or brown, and the signal wire is typically yellow, orange or white.

Since the ESP32 can supply limited current at only 3.3V, and servos draw considerable power, we will connect servo power to the USB pin of the ESP32 to use 5v from our computer.

We -could- connect servo power to the BAT (battery) pin of the ESP32, but this is ONLY appropriate for SMALL servos and will draw down the battery power quickly.

We can also connect servo power to a separate external power source (as long as we connect all of the grounds (ESP32, servo, and external power). In this example, we just connect ESP32 ground to servo ground.

The servo signal pin connects to any available GPIO pins on the ESP32 (in this example, we use pin 14).

![Servo_Potentiometer_v2_bb.png](/examples/ESP32V2_Servo/ESP32V2_Servo_v2_USB_bb.png)

The 'standard' Arduino servo library doesn't work with ESP32 so we'll need to install another library: https://docs.arduino.cc/libraries/esp32servo/
  - Use [library manager](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library/) in Arduino IDE
  - or download the library .zip file and unzip into your Arduino/libraries folder

Servo example code:
<!-- - [09a_Servo_Knob.ino](/examples/09_Servo/09a_Servo_Knob/09a_Servo_Knob.ino) - same as _Examples -> Servo -> Knob_  -->
- [ESP32_Servo_Sweep.ino](/examples/ESP32V2_Servo/ESP32_Servo_Sweep/ESP32_Servo_Sweep.ino) - same as _Examples -> Servo -> Sweep_

Note: Min and Max angles
 Different servos require different pulse widths to vary servo angle, but the range is
 an approximately 500-2500 microsecond pulse every 20ms (50Hz). In general, hobbyist servos
 sweep 180 degrees, so the lowest number in the published range for a particular servo
 represents an angle of 0 degrees, the middle of the range represents 90 degrees, and the top
 of the range represents 180 degrees. So for example, if the range is 1000us to 2000us,
 1000us would equal an angle of 0, 1500us would equal 90 degrees, and 2000us would equal 1800 degrees.
If you find that your servo does not move from 0 to 180 degrees, adjust the min and max values in the code to match your needs. In the example above this adjustment has been made to match the micro servos in your kits.

***

### Let's Go Crazy (Let's Get Nuts)[*](https://www.youtube.com/watch?v=aXJhDltzYVQ)

![ESP32V2_MotorServoNeoPixel_bb.png](/examples/ESP32V2_MotorServoNeoPixel/ESP32V2_MotorServoNeoPixel_bb.png)

Let's combine circuits and code for the DC motor, servo, and Neopixel!! In this example EVERYTHING is running on 5V from from power supply and we're using the L298 terminal block as a way to connect ALL the power and grounds leads to one another.

example code:
- [EESP32V2_MotorServoNeoPixel.ino](/examples/ESP32V2_MotorServoNeoPixel/ESP32V2_MotorServoNeoPixel/ESP32V2_MotorServoNeoPixel.ino)

***

### Roopa's excellent ESP32 V2 webAPI example (including how to connect to Berkeley IoT)

https://github.com/roopa-ramanujam/ESP32-web-api-example

***

***

### More to explore
- **Arduino Language Reference**
  - https://www.arduino.cc/reference/en/

<!--
- **Interfacing with Hardware**
 - [Interfacing with Hardware](http://playground.arduino.cc/Main/InterfacingWithHardware)
 - Joining inputs and outputs: switch controls speed, switch choses between two brightness levels, thermistor or other sensor changes behavior, etc.
 - Multiple output devices: play melody while controlling motor speed, etc.
 - Boolean logic, tests, and conditionals
-->
<!--
- **Making sounds** 
  - [Melody](https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/tone-output-using-an-arduino/) tutorial
-->

<!--
### Interfacing with Processing
  - [Arduino Virtual Color Mixer](https://www.arduino.cc/en/Tutorial/VirtualColorMixer) modified to work with the Art385 hardware platform:
    - ESP32 code - [Art385_ESP32toProcessing_ESP32.ino](/examples/Art385_ESP32toProcessing/Art385_ESP32toProcessing_ESP32/Art385_ESP32toProcessing_ESP32.ino)
    - Processing code - [Art385_ESP32toProcessing_Processing.pde](/examples/Art385_ESP32toProcessing/Art385_ESP32toProcessing_Processing/Art385_ESP32toProcessing_Processing.pde)
    - .zip of the entire bundle - [Art385_ESP32toProcessing_Processing.zip](/examples/Art385_ESP32toProcessing/Art385_ESP32toProcessing.zip)
-->

***

### Resources!!!
- [Dr Sudhu's resources page](https://github.com/loopstick/ResourcesForClasses)
