- Embedded systems use sensors to collect real-world data. These sensors are either:
  - **Analog** (variable voltage, e.g. 0-5V)
  - **Digital** (binary HIGH/LOW, 1/0 )

- Microcontrollers use **ADC** **(Analog-to-Digital Converter)** and **digital input pins** to interpret these signals
---

# Analog Input
---
- Analog sensors produce **continuous voltage** that represents a physical quantity (for example, light, temperature)
- A microcontroller reads this using an ADC and returns a value **0 to ((2^n) - 1)** on an **n-bit** board

### **Example (10-bit Arduino board):**
```c
int sensorValue = analogRead(A0); // reads voltage from A0 (0–5V → 0–1023)
float voltage = sensorValue * (5.0 / 1023.0); // convert to volts
```
## Common Analog Sensors
 - **Photoresistor (LDR)** - light intensity
 - **TMP36** - temperature
 - **Potentiometer** - variable resistance
---

# Digital Input
---
- Digital sensors output only 2 possible states
	- HIGH: true/triggered
	- LOW: false/inactive
## Common Digital Sensors
 - **PIR motion sensor
 - **Hall effect switches**
 - **Button-based sensors**
 - **Reed switches (magnetic)**
---

# Debouncing (digital inputs)
--- 
- Mechanical sensors such as buttons can '**bounce**', meaning their signal rapidly flips between HIGH and LOW when pressed or released due to physical vibrations
- This can cause **false triggers** or multiple detections from a single press

## Software Debouncing

#### **1. millis**()
```c
const int buttonPin = 2;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
int lastButtonState = HIGH;

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // reset timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Stable input after 50ms → accept reading
    if (reading == LOW) {
      Serial.println("Button pressed!");
    }
  }

  lastButtonState = reading;
}
```
#### **2. delay()**
```c
if (digitalRead(buttonPin) == LOW) {
  delay(50); // crude debounce
  if (digitalRead(buttonPin) == LOW) {
    // button really pressed
  }
}
```

- **delay()** is best sued for testing or low-speed inputs, while **millis()** should be used for production logic
---

# Analog SIgnal Filtering
---
- Analog signals can fluctuate due to 
	- Noise
	- Power instability
	- Sensor imperfections

- Filtering is used to produce **smoother, more accurate readings**. Without it, small changes can result in noisy/unstable values

## Software Filtering

#### **1. Simple Averaging (Rolling Average)**
```c
int averageAnalog(int pin, int samples = 10) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(5); // short delay between reads
  }
  return total / samples;
}
```
#### **2. Low-Pass Filter (Exponential Moving Average)**
```c
float filteredValue = 0;
float alpha = 0.1; // smoothing factor (0.0 – 1.0)

void loop() {
  int raw = analogRead(A0);
  filteredValue = (alpha * raw) + (1 - alpha) * filteredValue;
}

```
- a smaller *alpha* results in smoother output, but a slower response
---
