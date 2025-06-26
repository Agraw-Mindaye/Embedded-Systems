# LCD 16x2 Display
--- 
- Displays 2 lines of 16 characters each.
- Character-based (not graphical).
- Operates in **4-bit or 8-bit parallel** mode.
- Common pins: `RS`, `RW`, `EN`, `D4–D7` (4-bit), `VSS`, `VDD`, `V0`, `A`, `K`.

#### Pinout Summary:

|Pin|Function|
|---|---|
|VSS|Ground|
|VDD|+5V|
|V0|Contrast control (via potentiometer)|
|RS|Register Select (0 = command, 1 = data)|
|RW|Read/Write (0 = write)|
|EN|Enable (triggers read/write)|
|D4–D7|Data lines (4-bit mode)|
|A/K|LED backlight (Anode/Cathode)|

#### Setup:

- Use `LiquidCrystal` library (Arduino).
- 4-bit mode is preferred to save GPIOs.

#### Initialization Code :

```c
#include <LiquidCrystal.h> 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // RS, EN, D4, D5, D6, D7  

void setup() {   
	lcd.begin(16, 2);   
	lcd.print("Hello, LCD!"); 
}
```


# UI with Buttons

- Combine buttons with an LCD/OLED to create menus or controls.
- Use state machines or button debouncing.

#### Menu Navigation Example

- Use buttons for navigation.
- Keep an index to track current selection.
- Update display accordingly.
