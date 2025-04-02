# Interactive LED Control Panel

## Overview

This project wraps up **Phase 1** of my Embedded Systems learning roadmap. 
It demonstrates basic microcontroller skills using an Arduino Mega 2560: digital 
and analog I/O, PWM, interrupts, and serial communication.

## Hardware Used

| Component        | Description                      |
|------------------|----------------------------------|
| Arduino Mega 2560 | Main microcontroller board       |
| Push button       | Mode switch |
| Potentiometer     | Analog input control             |
| RGB LED           | Output device (red was used in this project) |
| Resistors (220Ω)  | For LED current limiting         |
| Breadboard + jumpers | Standard prototyping setup     |

## Circuit Connections

| Component    | Arduino Pin |
|--------------|-------------|
| Button       | 2 (interrupt-capable) |
| Potentiometer | A0          |
| RGB Red      | 9 (PWM)      |
| RGB Green    | 10 (PWM, unused) |
| RGB Blue     | 11 (PWM, unused) |

## 📝 Code Sample

```cpp
    switch (mode) {
    case 0: blinkMode(potValue); break;
    case 1: brightnessMode(potValue); break;
    case 2: colorMode(potValue); break;
  }
```

## 📝 Serial Monitor Output Sample

```cpp
    [Mode 0: Blink] Pot: 142 | Interval: 224ms | LED: ON
        Switched to Mode 1
    [Mode 1: Brightness] Pot: 0 | Brightness: 0
        Switched to Mode 2
    [Mode 2: Color Red] Pot: 826 | Red Intensity: 205
```     

## How It Works

1. Pressing the button triggers an interrupt to switch modes.
2. In each mode, the potentiometer value is read and mapped:
   - **Mode 0**: Blinks the LED at speeds between 100ms–1000ms
   - **Mode 1**: Adjusts LED brightness via PWM
   - **Mode 2**: Sets red intensity for RGB LED
3. All states are printed over Serial for easy monitoring.

## Lessons Learned

- How to use attachInterrupt() to respond to button presses.
- What an ISR (Interrupt Service Routine) is and how it works.
- Why volatile is necessary for variables shared with an ISR.
- How to debounce a button manually using millis().
- How to use millis() instead of delay() for non-blocking timing.
- How to map analog values with map() to control timing, brightness, or color.
- How to use the serial monitor (arduino-cli monitor) to debug behavior in real time.
