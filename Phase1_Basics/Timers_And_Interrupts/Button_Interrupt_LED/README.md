# Button-Interrupt LED Project

## Overview
This project demonstrates how to use external interrupts to toggle an LED when a button is pressed. 
The LED responds instantly using an interrupt service routine (ISR), not by polling in the loop().

## Components Used
- Arduino Mega 2560
- 1x LED
- 1x push button (4-legged)
- 1x 220Ω Resistor
- Breadboard & Jumper Wires

## Circuit Connections
- Connect the short leg (cathode) of LED to GND rail on the breadboard.
- Connect the long leg (anode) of LED to a 220Ω resistor.
- Connect the other end of the resistor to a digital pin (eg, 9)

- Connect one leg of the button to digital pin 2 on the Mega.
- Connect the opposite leg to GND.

Connect the opposite leg to GND.

## 📝 Code Sample
```cpp
    attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
```

## How It Works
- The interrupt handler tells Arduino to run the 'toggleLed' function if the button is pressed
- 'toggleLED' toggles a volatile flah to update the LED pin
- the 'loop' function simulates other tasks, but the LED toffles immediately when the button is pressed

## Lessons Learned
- How to use attachInterrupt() to respond to button presses.
- What an ISR (Interrupt Service Routine) is and how it works.
- Why volatile is necessary for variables shared with an ISR.
