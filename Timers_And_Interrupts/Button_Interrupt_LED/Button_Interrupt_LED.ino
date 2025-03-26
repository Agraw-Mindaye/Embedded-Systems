#include <Arduino.h>

const int ledPin = 9;
const int buttonPin = 2;

volatile bool ledState = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);

    Serial.begin(9600);
    Serial.println("Press button to toggle LED with an interrupt");
}

void loop() {
    delay(100);
}

void toggleLED() {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
}
