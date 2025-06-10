# Serial-Controlled LED Project

## Overview
This project allows you to control multiple LEDs using commands sent from the **Serial Monitor**

## Components Used
- Arduino Mega 2560
- 3x LEDs
- 3x 220Ω Resistors
- Breadboard & Jumper Wires

## Circuit Connections
- Connect the short leg (cathode) of each LED to the GND rail on the breadboard.
- Connect the long leg (anode) of each LED to a 220Ω resistor.
- Connect the other end of each resistor to digital pins 9, 10, and 11 on the Mega 2560.

## 📝 Code Sample
```cpp

    if (input == "1") {
        digitalWrite(leds[0], HIGH);
        Serial.println("LED 1 ON");
    } else if (input == "1off") {
        digitalWrite(leds[0], LOW);
        Serial.println("LED 1 OFF");
    }
```


## How to Use
- Open the Serial Monitor in VS Code (PlatformIO) or Arduino IDE.
- Set the baud rate to 9600.
- Enter commands like:
    * 1 → Turn on LED 1
    * 1off → Turn off LED 1
    * 2, 2off, 3, 3off → Control LEDs 2 and 3
- The LED state will change and a confirmation message will be printed to the Serial Monitor.

## Lessons Learned
- How to communicate with Arduino via the Serial Monitor.
- How to use Serial.begin(), Serial.readStringUntil(), and Serial.println() for input/output.
- How to parse and respond to user commands to control multiple components.
