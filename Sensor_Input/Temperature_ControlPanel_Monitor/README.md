# DHT11 Temperature Alert Panel

This project uses a **DHT11 sensor** to read temperature/humidity, a **potentiometer** to set a warning threshold, and a **button** to toggle an alert mode. The output is displayed in the **Serial Monitor**, showing live temperature data and alert status in real-time.

---

## 📦 Components Used

| Component     | Function                                 |
|---------------|------------------------------------------|
| DHT11 (3-pin) | Reads ambient temperature (°F)           |
| Potentiometer | Sets temperature threshold (60–95°F)     |
| Push Button   | Toggles alert mode ON/OFF                |
| ATmega2560 (Keyestudio) | Microcontroller          |
| Jumper Wires  | Wiring between components                |
| Breadboard    | Prototyping board                        |

---

## Circuit Connections

### 🟦 DHT11 (3-pin Module)

| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| DATA      | 3           |
| GND       | GND         |

### 🎚️ Potentiometer

| Pot Pin | Arduino Pin |
|---------|-------------|
| Left    | 5V          |
| Middle  | A1          |
| Right   | GND         |

### 🔘 4-Leg Push Button

| Button Leg | Arduino Pin |
|------------|-------------|
| One side   | GND         |
| Other side | 2           |


## 📝 Code Sample

```cpp
    float tempF = dht.readTemperature(true); // true = Fahrenheit
    if (isnan(tempF)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
```

## 📝 Serial Monitor Output Sample

```cpp
    Temperature: 36.3°F | Threshold: 60.0°F | Alert: OFF
```
---

## How It Works

- Reads **temperature in Fahrenheit** using the DHT11
- Sets a **custom alert threshold** with the potentiometer (60–95°F)
- Button toggles an `alertMode` (ON/OFF)
- Sends all data to the Serial Monitor
- Uses `millis()` to read sensor every 2 seconds (DHT11 limit)
- Debounced button logic to prevent multiple toggles

## Lessons Learned

- How to interface with the **DHT11 sensor** using a digital pin
- How to implement a **software-debounced toggle button**
- How to **map analog values to real-world ranges** (like °F)

---
