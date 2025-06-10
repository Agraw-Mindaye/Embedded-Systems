# Actuators
---
- **Actuators** are devices that convert energy into motion
- In embedded systems, the most common actuators are motors, which are used in:
	- Robots
	- Fans
	- Wheels

# Type of Motors
---
 - ## DC Motor
	- Spins continuously in one direction
	- Speed is controlled be **PWM (Pulse Width Modulation)** 
	- Direction is controlled using an **H-Bridge motor driver**
- ## Servo Motor
	- Rotates to a single angle (**0° to 180°**) based on PWM
	- Has a built-in motor + feedback circuit
	- Often used for precise movement (arms, dials, levers)
- ## Stepper Motor
	- Moves in steps (fixed increments)
	- Great for accurate and repeatable positioning (3D printer, CNC)

# Controlling Motors: H-Bridge
---
- An **H-Bridge** is a circuit that allows you to reverse the direction of a DC motor
- Lets you connect a motor's **(+) and  (-)**  terminals to either power or ground
- Common integrated circuits are **L293D, L298N**

### ***Why Not Directly Drive a Motor?***
- Motors draw **too much current** for Arduino pins
- Most drivers protect boards and allow for **direction and speed control**

# Power Considerations
--- 
- Motors need power supplies (often 5V or 12V), not just Arduino pins
- Use common ground between Arduino and motor power supply
- Use **diodes** for back-EMF protection

# Code Control
---
## DC Motor
```c
analogWrite(motorPin, speed) // 0-255
```
## Servo Motor
```c
#include <Servo.h>
Servo myServo;
myServo.attach(9);
myServo.write(90); // Move to 90°
```
## Stepper Motor
```c
#include <Stepper.h>
Stepper stepper(stepsPerRev, pin1, pin2, pin3, pin4);
stepper.step(200); // Steps forward
```