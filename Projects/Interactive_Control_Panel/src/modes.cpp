#include "config.h"
#include <Arduino.h>


extern unsigned long lastBlinkTime;
extern bool ledState;

// led blinking mode
void blinkMode(int potValue) {
  int interval = map(potValue, 0, 1023, 100, 1000);

  if (millis() - lastBlinkTime >= interval) {
    ledState = !ledState;
    digitalWrite(redPin, ledState);
    lastBlinkTime = millis();

    Serial.print("[Mode 0: Blink] Pot: ");
    Serial.print(potValue);
    Serial.print(" | Interval: ");
    Serial.print(interval);
    Serial.print("ms | LED: ");
    Serial.println(ledState ? "ON" : "OFF");
  }
}

// led brightness mode
void brightnessMode(int potValue) {
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(redPin, brightness);

  Serial.print("[Mode 1: Brightness] Pot: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);
}

// led color mode
void colorMode(int potValue) {
  int redIntensity = map(potValue, 0, 1023, 0, 255);
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  Serial.print("[Mode 2: Color Red] Pot: ");
  Serial.print(potValue);
  Serial.print(" | Red Intensity: ");
  Serial.println(redIntensity);
}
