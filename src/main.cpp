#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

// map() macro but for floats
#define mapf(val, in_min, in_max, out_min, out_max) \
  (float)(val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#define LED_PIN 6
#define LED_COUNT 29

const uint32_t period = 5000;
const int brightness0 = 254;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

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
  uint32_t currentTime = millis() % period;

  float t = mapf(currentTime, 0, period, 0, 2);

  strip.clear();
  for (int i = 0; i < LED_COUNT; i++) {
    float pixelI = periodicFuncPow5(t + 4 * (float)(i * 2) / LED_COUNT);
    int pixelIInt = pixelI * brightness0 + 1; 
    strip.setPixelColor(i, strip.Color(pixelIInt, 0, 0, 0));
  }
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