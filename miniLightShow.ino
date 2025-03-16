#include <Adafruit_NeoPixel.h>

#define PIN 13
#define N_LEDS 40

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  strip.setBrightness(127);
  
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
  
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue
  
  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  chase(strip.Color(random(0, 256), 0, 0)); // Random red
  chase(strip.Color(0, random(0, 256), 0)); // Random green
  chase(strip.Color(0, 0, random(0, 256))); // Random blue
  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  
  breathe(strip.Color(255, 0, 0));
  cycle_red();
  breathe(strip.Color(255, 0, 0));

  breathe(strip.Color(0, 255, 0));
  cycle_green();
  breathe(strip.Color(0, 255, 0));

  breathe(strip.Color(0, 0, 255));
  cycle_blue();
  breathe(strip.Color(0, 0, 255));

  breathe(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(255, 0, 0)); // Red
  breathe(strip.Color(255, 0, 0)); // Red
  
  breathe(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 255, 0)); // Green
  breathe(strip.Color(0, 255, 0)); // Green
  
  breathe(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 0, 255)); // Blue
  breathe(strip.Color(0, 0, 255)); // Blue

  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(0, 255, 0)); // Green

  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  chase(strip.Color(random(0, 256), 0, 0)); // Random red
  chase(strip.Color(0, random(0, 256), 0)); // Random green
  chase(strip.Color(0, 0, random(0, 256))); // Random blue
  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));

  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(255, 0, 0)); // Red
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
    strip.setPixelColor(i , c); // Draw new pixel
    strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
    strip.show();
    delay(25);
  }
}

static void breathe(uint32_t c) {
  for(uint16_t l=0; l<3; l++) {
    for(uint16_t b=127; b>10; b--) {
      strip.setBrightness(b);
      for(uint16_t i=0; i<40; i++) {
        strip.setPixelColor(i , c);
      }
      strip.show();
      delay(25);
    }
    for(uint16_t b=10; b<128; b++) {
      strip.setBrightness(b);
      for(uint16_t i=0; i<40; i++) {
        strip.setPixelColor(i , c);
      }
      strip.show();
      delay(10);
    }
  }
  strip.setBrightness(127);
}

static void cycle() {
  for(uint16_t r=0; r<256; r+=32) {
    // RED
    for(uint16_t g=0; g<256; g+=32) {
      // GREEN
      for(uint16_t b=0; b<256; b+=32) {
        // BLUE
        for(uint16_t i=0; i<40; i++) {
          strip.setPixelColor(i, strip.Color(r, g, b));
          Serial.println("R: " + (String)r + " - G: " + (String)g + " - B: " + (String)b);
        }
        strip.show();
        delay(25);
      }
    }
  }
}

static void cycle_red() {
  for(uint16_t r=0; r<256; r+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(r, 0, 0));
    }
    strip.show();
    delay(100);
  }
}

static void cycle_green() {
  for(uint16_t g=0; g<256; g+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(0, g, 0));
    }
    strip.show();
    delay(100);
  }
}

static void cycle_blue() {
  for(uint16_t b=0; b<256; b+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, b));
    }
    strip.show();
    delay(100);
  }
}
