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
