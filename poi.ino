#include "FastLED.h"

#define NUM_LEDS 36
#define DATA_PIN 0
#define CLOCK_PIN 2

CRGB leds[NUM_LEDS];
byte c, c1, c2;
bool o;

void setup() { 
      FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);
     c1 = 128;
     o = false;
}

void loop() { 
  // Run each programme for 5 seconds

  int p = millis(); // programme counter
  while ((millis() - p) < 5000) {
    patternOne();
  }
  
  p = millis(); 
  while ((millis() - p) < 5000) {
    patternTwo();
  }
  
  p = millis(); 
  while ((millis() - p) < 5000) {
    patternThree();
  }
}


// Randomly flash some of the LEDs white
void patternOne() {
  FastLED.clear();
  for (int i = 0; i < 9; ++i) {
    leds[random8(NUM_LEDS)] = CHSV(0, 0, 255); 
  }
  FastLED.show();
  delay(50);
}

// Slowly fade through all colours
void patternTwo() {
  c++;
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CHSV(c, 255, 100); 
  }
  FastLED.show();
  delay(50);
}

// Alternate between inner and outer LEDs
void patternThree() {
  FastLED.clear();
  c1++;
  c2++;
  if (o) {
    for (int i = 0; i < 9; ++i) {
      leds[i] = CHSV(c1, 255, 255);
      leds[NUM_LEDS - 1 - i] = CHSV(c1, 255, 255);
    }
    delay(100);
  }
  else {
    for (int i = 9; i < (NUM_LEDS - 9); ++i) {
      leds[i] = CHSV(c2, 255, 255);
    }
    delay(200);
  }
  FastLED.show();
  o = !o;
}




