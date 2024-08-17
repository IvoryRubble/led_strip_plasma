#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 29

const uint32_t period = 50000;
const int brightness0 = 100;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();          
  strip.show();           
  strip.setBrightness(100);
}

void loop() {
  uint32_t currentTime = millis() % period;
  
  float pixelF = (float)(currentTime * LED_COUNT) / period;
  float pixelT = pixelF - (int)pixelF;
  float pixelF0 = (1 - pixelT) * (1 - pixelT) / 2;
  float pixelF2 = (pixelT) * (pixelT) / 2;
  float pixelF1 = 1 - pixelF0 - pixelF2;
  int pixel0 = pixelF0 * brightness0;
  int pixel1 = pixelF1 * brightness0;
  int pixel2 = pixelF2 * brightness0;

  strip.clear();
  strip.setPixelColor((int)pixelF + 0, strip.Color(pixel0, 0, 0, 0));
  strip.setPixelColor((int)pixelF + 1, strip.Color(pixel1, 0, 0, 0));
  strip.setPixelColor((int)pixelF + 2, strip.Color(pixel2, 0, 0, 0));
  strip.show();
  delay(1); 
}

