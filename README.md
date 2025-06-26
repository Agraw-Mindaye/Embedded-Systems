# Embedded Systems

Welcome to my Embedded Systems repository!

This repository contains a showcase of my journey in embedded systems engineering. 
It combines self-chosen projects along with advanced coursework from the **PyjamaBrah Library** course.

## Features  
- Hands-on embedded systems projects 
- Compatible with **Keyestudio Mega 2560** and **ESP32-WROVER**
- Clean and well-documented code with explanations

## Technologies & Tools  
- **Languages:** C, C++
- **Hardware:** Keyestudio Mega 2560, ESP32, LEDs, push buttons, potentiometers, DHT11 sensors, displays
- **Development Tools:** Arduino CLI, PlatformIO, QEMU, GDB, Git, markdown for notes

## Structure

### Phase 1: Basics
- Digital I/O handling
- Serial communication
- Analog inputs, PWM, basic timers
- Breadboard wiring and LED/button logic

### Phase 2: Peripherals
- LCD and OLED displays
- I2C and SPI device communication
- SD card data logging
- Sensor integrations

### PyjamaBrah *'Library'* Coursework
- Content soon to added ...

## Completed Mini Projects

- [**Blinking LED**](Phase1_Basics/Digital_Outputs/Blink_LED) - Simple digital output using GPIO
- [**Button-Activated LED**](Phase1_Basics/Digital_Inputs/Button_LED) – Digital input with push-button and LED
- [**Potentiometer-Controlled LED**](Phase1_Basics/Analog_Inputs/Potentiometer_LED_Bar_Graph) – Analog input and PWM  
- [**Serial Communication**](Phase1_Basics/Serial_Communication/Serial_Control_LED) – Debugging via UART  
- [**Timer & Interrupts**](Phase1_Basics/Timers_And_Interrupts/Button_Interrupt_LED) – Non-blocking logic and ISRs
- [**Sensor Input**](Phase2_Peripherals/Sensor_Input/Temperature_ControlPanel_Monitor) – Writing to LCD and menu navigation 
- [**Actuators And Motors**](Phase2_Peripherals/Actuators_And_Motors/ServoMotor) – Temperature and humidity reading with DHT11
- [**Display Modules**](Phase2_Peripherals/Displays/LCD_Button_And_Potentiometer) – Writing to LCD and menu navigation 

## Projects

### [Smart Environment Dashboard](Projects/Smart_Environment_Dashboard/) 
- DHT11 reads temperature and humidity
- SD card stores readings into log file
- 16x2 I2C LCD displays logs
- Buttons navigate through entries 

### [Interactive LED Control Panel](Projects/Interactive_Control_Panel/) 
- Button switches modes  
- Potentiometer adjusts values  
- Serial output reflects current state  
