#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

// map() macro but for floats
#define mapf(val, in_min, in_max, out_min, out_max) \
  (float)(val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#define LED_PIN 6
#define LED_COUNT 29

const uint32_t period0 = 3000;
const uint32_t period1 = 7000;
const int brightness0 = 255;
const int brightness1 = 255;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

float periodicFuncHSV(float);
float periodicFuncLinear(float, float, float);
float periodicFuncPow1(float);
float periodicFuncPow2(float);
float periodicFuncPow3(float);
float periodicFuncPow4(float);
float periodicFuncPow5(float);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {
  uint32_t currentTime0 = millis() % period0;
  uint32_t currentTime1 = millis() % period1;

  float t0 = mapf(currentTime0, 0, period0, 100, 102);
  float t1 = mapf(currentTime1, 0, period1, 100, 102);

  strip.clear();
  for (int i = 0; i < LED_COUNT; i++) {
    float pixelI0 = periodicFuncPow5(t0 + 1.6 * (float)(i * 2) / LED_COUNT);
    float pixelIInt0 = mapf(pixelI0, 0, 1, 0, brightness0); 
    float pixelI1 = periodicFuncPow5(t1 - 4 * (float)(i * 2) / LED_COUNT);
    float pixelIInt1 = mapf(pixelI1, 0, 1, 0, brightness1); 
    strip.setPixelColor(i, strip.ColorHSV(65535 / 2, 255, (int)((pixelIInt0 + pixelIInt1) / 2)));
  }
  strip.show();
  delay(10);
}

float periodicFuncHSV(float input) {
  float x = input - ((int)input / 2 * 2);
  float y = x / 2;
  return y;
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

float periodicFuncPow5(float input) {
  float x = input - ((int)input / 2 * 2);
  float y;
  if (x < 1) {
    y = x * x * x * x * x;
  } else {
    y = - (x - 2) * (x - 2) * (x - 2) * (x - 2) * (x - 2);
  }
  return y;
}