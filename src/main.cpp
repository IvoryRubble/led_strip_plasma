#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 29

const uint32_t period = 7000;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();          
  strip.show();           
  strip.setBrightness(255);
}

void loop() {
  uint32_t currentTime = millis() % period;

  strip.clear();
  strip.setPixelColor(currentTime * LED_COUNT / period, strip.Color(0, 0, 0, 20));
  strip.show();
  delay(1); 
}

