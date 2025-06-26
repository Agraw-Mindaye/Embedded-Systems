# UART (Universal Asynchronous Receiver Transmitter))
---
- Asynchronous (uses no shared clock)
- Usually uses 2 wires
	- TX (transmit)
	- RX (receive)
- Full-duplex (this means it can send and receive simultaneously)

### Common uses:
- USB (Serial Monitor for example)
- Communication with Bluetooth, GPS, etc.

### Example:
```c
Serial.begin(9600); // 9600 bps (bist per second)
Serial.print(message);
```

# I<sup>2</sup>C (Inter-Integrated Circuit)
---
- Synchronous (used a shared clock)
- Two wires
	- SDA (data)
	- SCL (clock)
	- Supports multiple devices (1 master device, multiple slave devices)
	- Each device has a 7 or 10 bit address

### Common Uses
- Sensors, LCDs with I<sup>2</sup>C backpack, OLEDs, RTC

### Example
```c
#include <Wire.h>

/* basic transmission: */

Wire.begin(); // join the I2C bus
Wire.beginTransmission(0x3C);
Wire.write(data);
Wire.endTransmission();


/* Address scanning: */

void setup() {
	Wire.begin();
	Serial.begin(115200);
	
	for (byte addr = 1; i < 127;){ // 7-bit addresses
		Wire.beginTransmission(addr); // start communication at current addr
		if (Wire.endTransmission() == 0){ // if a device ACKnowldeges the addr, it returns a 0
			Serial.print("Found I2C deviate at: 0x");
			Serial.println(addr, HEX);
		}
	}
}
```

# SPI (Serial Peripheral Interface)
---
- Synchronous (used a shared clock)
- 4 main lines
	- MOSI (Master Out Slave In)
	- MISO (Master In Slave Out)
	- SLCK (Clock)
	- SS (Slave Select / Chip Select)
- Fully-duplex (faster than I2C)

### Common Uses
- SD Cards, shift registers, displays, flash memory

### Example
```c
#include <SPI.h>

void setup() {
  SPI.begin();
  digitalWrite(SS, LOW); // pull the chip select line slow, telling the connected slave device to 'listen'
  SPI.transfer(0x42); //. send a single bute of data 
  digitalWrite(SS, HIGH); // pull chip select high, telling slave device that it's finished
}

```

