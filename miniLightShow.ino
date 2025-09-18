#include <Adafruit_NeoPixel.h>

#define PIN 13
#define N_LEDS 40

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  strip.setBrightness(127);
}

void loop() {
  twinkle(strip.Color(8, 8, 8), strip.Color(255, 255, 255), 60, 40);

  twinkle(strip.Color(8, 0, 0), strip.Color(255, 0, 0), 60, 40);
  twinkle(strip.Color(0, 8, 0), strip.Color(0, 255, 0), 60, 40);
  twinkle(strip.Color(0, 0, 8), strip.Color(0, 0, 255), 60, 40);

  twinkle(strip.Color(32, 0, 0), strip.Color(random(0, 256), random(0, 256), random(0, 256)), 60, 40);
  twinkle(strip.Color(0, 32, 0), strip.Color(random(0, 256), random(0, 256), random(0, 256)), 60, 40);
  twinkle(strip.Color(0, 0, 32), strip.Color(random(0, 256), random(0, 256), random(0, 256)), 60, 40);
  
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue

  breathe(strip.Color(255, 0, 0)); // Red
  breathe(strip.Color(0, 255, 0)); // Green
  breathe(strip.Color(0, 0, 255)); // Blue

  cycle_red();
  cycle_green();
  cycle_blue();

  twinkle(strip.Color(64, 0, 0), strip.Color(255, 0, 0), 60, 40);
  twinkle(strip.Color(0, 64, 0), strip.Color(0, 255, 0), 60, 40);
  twinkle(strip.Color(0, 0, 64), strip.Color(0, 0, 255), 60, 40);

  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  chase(strip.Color(random(0, 256), 0, 0)); // Random red
  chase(strip.Color(0, random(0, 256), 0)); // Random green
  chase(strip.Color(0, 0, random(0, 256))); // Random blue
  breathe(strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 0, 255)); // Blue

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

  chase(strip.Color(255, 0, 0)); // Red
  cycle_red();
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  cycle_green();
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
  cycle_blue();
  chase(strip.Color(0, 0, 255)); // Blue

  twinkle(strip.Color(8, 8, 8), strip.Color(255, 255, 255), 60, 40);
}

static void chase(uint32_t c) {
  strip.setBrightness(127);
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
    strip.setPixelColor(i , c); // Draw new pixel
    strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
    strip.show();
    delay(25);
  }
}

static void breathe(uint32_t c) {
  for(uint16_t l=0; l<3; l++) {
    for(uint16_t b=10; b<128; b++) {
      strip.setBrightness(b);
      for(uint16_t i=0; i<40; i++) {
        strip.setPixelColor(i , c);
      }
      strip.show();
      delay(10);
    }
    for(uint16_t b=127; b>10; b--) {
      strip.setBrightness(b);
      for(uint16_t i=0; i<40; i++) {
        strip.setPixelColor(i , c);
      }
      strip.show();
      delay(25);
    }
  }
}

static void cycle() {
  strip.setBrightness(127);
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
  strip.setBrightness(127);
  for(uint16_t r=0; r<256; r+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(r, 0, 0));
    }
    strip.show();
    delay(100);
  }
}

static void cycle_green() {
  strip.setBrightness(127);
  for(uint16_t g=0; g<256; g+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(0, g, 0));
    }
    strip.show();
    delay(100);
  }
}

static void cycle_blue() {
  strip.setBrightness(127);
  for(uint16_t b=0; b<256; b+=32) {
    for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, b));
    }
    strip.show();
    delay(100);
  }
}

static void twinkle(uint32_t backgroundColor, uint32_t sparkleColor, uint16_t sparkleCount, uint16_t sparkleDuration) {
  strip.setBrightness(127);

  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, backgroundColor);
  }
  strip.show();

  uint16_t resetDelay = sparkleDuration / 2;
  if(resetDelay == 0) {
    resetDelay = 1;
  }

  for(uint16_t sparkle=0; sparkle<sparkleCount; sparkle++) {
    uint16_t pixel = random(strip.numPixels());

    strip.setPixelColor(pixel, sparkleColor);
    strip.show();
    delay(sparkleDuration);

    strip.setPixelColor(pixel, backgroundColor);
    strip.show();
    delay(resetDelay);
  }
}
