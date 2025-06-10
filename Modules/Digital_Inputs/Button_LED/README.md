## Overview

This project demonstrates how to use a push button to control an LED using an Arduino microcontroller.

## Components Used

- Keyestudio Mega 2560
    
- Small push button (4-legged)
    
- 2-leg LED
    
- 220-ohm resistor
    
- 10k-ohm pull-down resistor
    
- Breadboard
    
- Jumper wires
    

## Circuit Connections

### Push Button:

- Place the button on the breadboard so that it crosses the central gap.
    
- Connect one leg of the button to **pin 2** on the Keyestudio Mega 2560.
    
- Connect the opposite leg to **5V**.
    
- Connect a **10k-ohm resistor** between pin **2** and **GND** (pull-down resistor).
    

### LED:

- Connect the short leg of the LED to the ground (GND) rail on the breadboard.
    
- Connect the long leg of the LED to a **220-ohm resistor**.
    
- Connect the other end of the resistor to **pin 12** on the Keyestudio Mega 2560.
    

## Code

```c
const int buttonPin = 2;  // Button connected to Pin 2
const int ledPin = 12;    // LED connected to Pin 12

void setup() {
    pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
    pinMode(ledPin, OUTPUT);          // Set LED as output
}

void loop() {
    if (digitalRead(buttonPin) == LOW) { // Button is pressed (connected to GND)
        digitalWrite(ledPin, HIGH);  // Turn LED ON
    } else {
        digitalWrite(ledPin, LOW);   // Turn LED OFF
    }
}
```

## Explanation

- The `setup()` function initializes the button pin as an input with an internal pull-up resistor and the LED pin as an output.
    
- The `loop()` function continuously checks the state of the button:
    
    - If the button is **pressed** (LOW state), the LED turns on.
        
    - If the button is **not pressed** (HIGH state), the LED turns off.
        
- The **internal pull-up resistor** keeps the button pin HIGH when not pressed, avoiding floating input values.
    

## Lessons Learned

- How to read digital input from a button.
    
- How to use pull-up resistors to ensure stable input values.
    
- How to use conditional statements (`if` statements) for hardware control.
