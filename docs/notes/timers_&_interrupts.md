# Timers
---

- delay(ms)
	- Blocks entire program for a given time
	- While Arduino is waiting, it cannot do anything else (no input, multitasking, etc.)

- millis()
	- Returns number of milliseconds since Arduino started running
	- Doesn't block program, so time checking is allowed without pausing everything
	- Enables multitasking
		- Ex: blinking LEDs while reading inputs


# Interrupts
--- 

- Allow microcontroller to instantly respond to external events
- No need to constantly check (also called 'polling')
- Hardware notifies the processor when the event occurs