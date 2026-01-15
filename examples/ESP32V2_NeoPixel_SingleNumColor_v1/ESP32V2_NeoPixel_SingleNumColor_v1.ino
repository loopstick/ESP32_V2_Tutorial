// modified from NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// 
// 2021 Sudhu Tewari for Robots and Humans 
// 2026 Sudhu Tewari for Prototyping

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        0 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

int pos = 10;

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 50; // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(9600);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50); // INITIALIZE NeoPixel strip object (REQUIRED)
    pixels.clear(); // Set all pixel colors to 'off'
  }

void loop() {
    //pixels.setPixelColor(i, pixels.Color(0, 150, 0));  // set pixel color most simple
    //pixels.setPixelColor(i, Wheel(150));    // set pixel color using wheel to define color with a single value 0-255
    pixels.setPixelColor(0, Wheel(pos));      // set pixel color using wheel to define color with a variable (myBPM)
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(delayVal); // Pause before next pass through loop

    pos++;    // increment my BPM (add 1 to myBPM)
    Serial.print("pos: ");
    Serial.println(pos);

    if(pos>255){
      pos = 0;
    }
}

  // Input a value 0 to 255 to get a color value.
    // The colours are a transition r - g - b - back to r.
    uint32_t Wheel(byte WheelPos){
        WheelPos = 255 - WheelPos;
        if(WheelPos < 85){
            return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
        }
        else if(WheelPos < 170){
            WheelPos -= 85;
            return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else{
            WheelPos -= 170;
            return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
      }
