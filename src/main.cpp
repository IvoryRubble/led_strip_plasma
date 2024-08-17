#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

// map() macro but for floats
#define mapf(val, in_min, in_max, out_min, out_max) \
  (float)(val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#define LED_PIN 6
#define LED_COUNT 29

const uint32_t period = 5000;
const int brightness0 = 255;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

float periodicFuncLinear(float, float, float);
float periodicFuncPow1(float);
float periodicFuncPow2(float);
float periodicFuncPow3(float);
float periodicFuncPow4(float);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {
  uint32_t currentTime = millis() % period;

  float t = mapf(currentTime, 0, period, 0, 2);
  float pixel0 = periodicFuncLinear(t, 0.75, 0.25);
  float pixel1 = periodicFuncPow1(t);
  float pixel2 = periodicFuncPow2(t);
  float pixel3 = periodicFuncPow3(t);
  float pixel4 = periodicFuncPow4(t);
  int pixel0Int = pixel0 * brightness0;
  int pixel1Int = pixel1 * brightness0;
  int pixel2Int = pixel2 * brightness0;
  int pixel3Int = pixel3 * brightness0;
  int pixel4Int = pixel4 * brightness0;

  strip.clear();
  strip.setPixelColor(6, strip.Color(pixel0Int, 0, 0, 0));
  strip.setPixelColor(10, strip.Color(pixel1Int, 0, 0, 0));
  strip.setPixelColor(14, strip.Color(pixel2Int, 0, 0, 0));
  strip.setPixelColor(18, strip.Color(pixel3Int, 0, 0, 0));
  strip.setPixelColor(22, strip.Color(pixel4Int, 0, 0, 0));
  strip.show();
  delay(1);
}

float periodicFuncLinear(float input, float bendX, float bendY) {
  float x = input - ((int)input / 2 * 2);
  if (x > 1) {
    x = 2 - x;
  }

  float y;
  if (x < bendX) {
    y = mapf(x, 0, bendX, 0, bendY);
  } else {
    y = mapf(x, bendX, 1, bendY, 1);
  }

  return y;
}

float periodicFuncPow1(float input) {
  float x = input - ((int)input / 2 * 2);
  float y;
  if (x < 1) {
    y = x;
  } else {
    y = 2 - x;
  }
  return y;
}

float periodicFuncPow2(float input) {
  float x = input - ((int)input / 2 * 2);
  float y;
  if (x < 1) {
    y = x * x;
  } else {
    y = (x - 2) * (x - 2);
  }
  return y;
}

float periodicFuncPow3(float input) {
  float x = input - ((int)input / 2 * 2);
  float y;
  if (x < 1) {
    y = x * x * x;
  } else {
    y = - (x - 2) * (x - 2) * (x - 2);
  }
  return y;
}

float periodicFuncPow4(float input) {
  float x = input - ((int)input / 2 * 2);
  float y;
  if (x < 1) {
    y = x * x * x * x;
  } else {
    y = (x - 2) * (x - 2) * (x - 2) * (x - 2);
  }
  return y;
}