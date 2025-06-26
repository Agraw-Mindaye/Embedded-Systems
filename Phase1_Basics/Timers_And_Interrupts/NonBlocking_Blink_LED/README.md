# Non-Blocking Blink LED Project

## Overview
This project shows how to implement the millis() function to make a program non-blocking

## Components Used
- Arduino Mega 2560
- 1x LED
- 1x 220Ω Resistor
- Breadboard & Jumper Wires

## Circuit Connections
- Connect the short leg (cathode) of LED to GND rail on the breadboard.
- Connect the long leg (anode) of LED to a 220Ω resistor.
- Connect the other end of the resistor to a digital pin (eg, 9)

## 📝 Code Sample
```cpp
    if (currMillis - prevMillis >= interval);
```

## How It Works
- The LED state will change states based on the interval set.
- The code uses millis() instead of delay() to allow for multi-tasking 

## Lessons Learned
- How to make code non-blocking and allow for multi-tasking
