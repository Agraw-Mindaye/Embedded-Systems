# Serial Communication
---

- Allows a microcontroller unit (MCU) to send and receive data via USB connection
- Used for debugging, sensor data logging, and communicating with external systems (computers, displays, etc.)
- Uses **Universal Asynchronous Receiver/Transmitter (UART)** which operates via the **TX (Transmit**) and **RX (Receive)** pins

## Start Serial Communication

```c
	Serial.begin(9600);
```
- 9600 is the **baud rate** (speed of communication, bits per second)

## Sending Data

```c
	Serial.print("Value: );         // prints text without new line
	Serial.println(analogRead(A0)); // prints value with newline
```
