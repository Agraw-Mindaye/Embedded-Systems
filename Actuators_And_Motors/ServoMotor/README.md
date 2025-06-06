# 🧭 Servo Angle Control with Potentiometer – ESP32

This mini project uses an ESP32 and a potentiometer to control the angle of a servo motor in real-time. As the user turns the knob, the servo rotates proportionally between 0° and 180°.

## Components Used

- ESP32 Dev Kit
- 9G-V1 Servo Motor (SG90-compatible)
- Potentiometer
- Breadboard & Jumper Wires
- USB cable for power


## Visuals

[Circuit Visual](./test/ServoMotor_Visual.jpg)

## Code Sample

``` c
int potValue = analogRead(potPin); // Read analog value (0–4095)
int angle = map(potValue, 0, 4095, 0, 180); // Convert to 0–180°

myServo.write(angle); // Set servo angle
```


## 📈 Sample Serial Output

- Pot: 215  | Angle: 9
- Pot: 1254 | Angle: 55
- Pot: 4095 | Angle: 180

## 🧠 Lessons Learned
- How to map analog input (0–4095) to a physical output range (0–180°)
- How to use the ESP32Servo library
- PWM output with microsecond precision on the ESP32
