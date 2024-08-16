#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 35

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();          
  strip.show();           
  strip.setBrightness(255);
}

void loop() {
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
  }
  strip.show();  
    //delay(1); 
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, 0));
    
  }
  strip.show();  
    delay(1000); 

  return;

  strip.clear();
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(150, 0, 0, 0));
    strip.show();  
    delay(10); 
  }
  strip.clear();
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 150, 0, 0));
    strip.show();  
    delay(10); 
  }
  strip.clear();
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 150, 0));
    strip.show();  
    delay(10); 
  }
  strip.clear();
  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, 150));
    strip.show();  
    delay(10); 
  }
}

