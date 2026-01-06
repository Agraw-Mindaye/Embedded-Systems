# Embedded Systems

This repository is a structured embedded systems engineering portfolio showcasing hands-on firmware development across microcontroller fundamentals, peripheral interfaces, and real-world hardware integration.

The projects in this repository emphasize deterministic behavior, modular firmware design, and reproducible hardware setups, using industry-relevant tools and workflows.

## Key Focus Areas

* Embedded firmwware fundamentals (GPIO, ADC, PWM, timers)
* Interrupt-driven input handling
* Peripheral communication (UART, I2C, SPI)
* Display interfaces and basic user interaction
* Sensor data acquisition and processing
* Actuator and motor control
* Persiistent data logging to external storage

## Technologies & Tools

### Languages

* C
* C++
  
## Hardware Platforms

* Arduino Mega 2560
* ESP32-WROVER
* LEDs, push buttons, potentiometers
* DHT11 temperature and humidity sensors
* LCD and OLED displays
* Servo motors and actuators

## Development Tools
* Arduino CLI
* PlatformIO
* Git for version controlk
* Markdown documentation for notes and reproducibility

## Repository Structure

### Phase 1: Core Embedded Fundamentals

Focuses on foundational concepts

* Digital I/O (LEDs, buttons)
* Analog Input & PWM (potentiometer, LED brightness)
* Serial communication (UART)
* Timers & Interrupts
* Non-blocking timing
* Safe interrupt handling and debouncing

### Phase 2: Peripherals & Interfaces

Builds on fundamentals to integrate real hardware peripherals and subsystems

* Display modules (LCD, OLED)
* Communication protocols (I2C, SPI)
* Sensor integration & data acquisition
* Actuator & motor control
* Data logging (SD card, file storage)
* Embedded user interfaces (menus, navigation_

## Completed Mini Projects
* [**Blinking LED**](Phase1_Basics/Digital_Outputs/Blink_LED) - Digital output control using GPIO
* [**Button-Activated LED**](Phase1_Basics/Digital_Inputs/Button_LED) – Interrupt-driven digital input handling
* [**Potentiometer-Controlled LED**](Phase1_Basics/Analog_Inputs/Potentiometer_LED_Bar_Graph) – Analog input processing and PWM output
* [**Serial Communication**](Phase1_Basics/Serial_Communication/Serial_Control_LED) – UART-based debugging and control
* [**Timer & Interrupts**](Phase1_Basics/Timers_And_Interrupts/Button_Interrupt_LED) – Non-blocking timing and ISR-based logic
* [**Sensor Input**](Phase2_Peripherals/Sensor_Input/Temperature_ControlPanel_Monitor) – Sensor data acquisition with LCD output and menu navigation
* [**Actuators And Motors**](Phase2_Peripherals/Actuators_And_Motors/ServoMotor) – Servo motor control driven by analog input
* [**Display Modules**](Phase2_Peripherals/Displays/LCD_Button_And_Potentiometer) – LCD-based UI with button and potentiometer navigation
