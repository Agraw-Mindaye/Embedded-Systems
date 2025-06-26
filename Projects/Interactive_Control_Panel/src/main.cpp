#include "config.h"
#include "modes.h"

volatile bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
unsigned long lastBlinkTime = 0;
bool ledState = LOW;
int mode = 0;

void handleButtonPress() {
  buttonPressed = true;
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
  Serial.begin(9600);
}

void loop() {
  if (buttonPressed && (millis() - lastDebounceTime) > debounceDelay) {
    mode = (mode + 1) % totalModes; // go to next mode when button pressed
    Serial.print("Switched to Mode ");
    Serial.println(mode);
    buttonPressed = false;
    lastDebounceTime = millis();
  }

  int potValue = analogRead(potPin); // read potentiometer value

  switch (mode) {
    case 0: blinkMode(potValue); break;
    case 1: brightnessMode(potValue); break;
    case 2: colorMode(potValue); break;
  }

  delay(50);
}
