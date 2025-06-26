# Analog Inputs
---

- Digital signals only have two states
	- High (1)
	- Low (0)
- Analog signals allow for a range of values
	- Example: A **potentiometer** (variable resistor) 

- The MEGA 2560 has 16 analog inputs pins
	- A0 - A15
- Arduino reads analog values using a 10 bit analog to digital converter (ADC)
	- This allows for a wider range of values (0-1023) instead of (0-255) like PWM

# Pulse Width Modulation (PWM)
---

- PWM is used to simulate analog output by rapidly switching **ON/OFF** at high speed
- The ratio of **ON** and **OFF** is called **duty cycle**
	- 0% duty cycle = Always **OFF**
	- 50% = Half **ON**, half **OFF**
	- 100% = Always **ON**

- MEGA 2560 shas PWM on **pins 2-13 & 44-46**
- PWM is controlled using:
```cpp 
	analogWrite(pin, value)
```
- 0 = 0% duty cycle
- 255 = 100% duty cycle

