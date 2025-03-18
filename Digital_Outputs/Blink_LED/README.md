# Blink LED Project

## Overview

This project demonstrates how to control an LED by making it blink at a set interval using an Arduino microcontroller.

## Components Used

- Keyestudio Mega 2560
- 2-leg LED
- 220-ohm resistor
- Breadboard
- Jumper wires

## Circuit Connections

- Connect the short leg of the LED to the ground (GND) rail on the breadboard.
- Connect the long leg of the LED to a 220-ohm resistor.
- Connect the other end of the resistor to pin **12** on the Keyestudio Mega 2560.

## Code Sample

```c
const int ledPin = 12; // Define LED pin

void setup() {
    pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
    digitalWrite(ledPin, HIGH); // Turn LED on
    delay(1000); // Wait for 1 second
    digitalWrite(ledPin, LOW); // Turn LED off
    delay(1000); // Wait for 1 second
}
```

## Explanation

- The `setup()` function initializes the LED pin as an output.
- The `loop()` function continuously turns the LED on and off, creating a blinking effect.
- The `delay(1000)` function pauses execution for 1 second between each toggle.

## Lessons Learned

- How to control an LED using a digital output pin.
- How to use the `setup()` and `loop()` functions in an Arduino sketch.
- How to use `digitalWrite()` and `delay()` functions.