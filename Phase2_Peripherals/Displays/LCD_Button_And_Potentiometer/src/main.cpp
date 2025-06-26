#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA 21 // SDA pin
#define SCK 22 // SCK pin

LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns, 2 rows (16x2 LCD display)

const int BTN_UP = 32; // Up button
const int BTN_DOWN = 33; // Down button
const int BTN_SELECT = 25; // Select button
const int POT_PIN = 34; // Potentiomete

const int numItems = 5;
String menuItems[numItems] = {"Start", "Login", "Logout", "Profile", "Settings", };

int menuIndex = 0;
int lastMenuIndex = -1;
int lastPotIndex = -1;

void displayMenu(); // function to display menu
void handleButtons(); // function to ahndle button clicks
void handlePotentiometer(); // function to handle potentiometer 

void setup() {

    // init buttons
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_SELECT, INPUT_PULLUP);

    // init LCD
    Wire.begin(21, 22);  // SDA, SCL for ESP32
    lcd.init();
    lcd.backlight();

    // write hello message on first row
    lcd.setCursor(0, 0);
    lcd.print("Hello!");
    delay(1000);
    displayMenu();
}

void loop() {
    handleButtons();
    handlePotentiometer();
}

void handleButtons() {

    // move to option above
    if (digitalRead(BTN_UP) == LOW) {
        menuIndex--;
        if (menuIndex < 0) menuIndex = numItems - 1;
    }

    // move to option below
    if (digitalRead(BTN_DOWN) == LOW) {
        menuIndex++;
        if (menuIndex >= numItems) menuIndex = 0;
    }

    // update display with either the above or below menu option
    if (menuIndex != lastMenuIndex) {
        displayMenu();
        lastMenuIndex = menuIndex; // update most recent selection
        delay(500);
    }

    // show selected option on second row
    if (digitalRead(BTN_SELECT) == LOW) {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Selected: ");
       lcd.setCursor(0,1);
       lcd.print(menuItems[menuIndex]);
       delay(1000);
       displayMenu();
    }
}

void displayMenu() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> " + menuItems[menuIndex]);
    lcd.setCursor(0, 1);
    lcd.print("  " + menuItems[(menuIndex + 1) % numItems]);
}

void handlePotentiometer() {

    int potVal = analogRead(POT_PIN);
    int potIndex = map(potVal, 4095, 0, 0, numItems - 1); // convert reading to menu options 

    // update displau only if pot position has changed and different from current menuIndex
    if (potIndex != lastPotIndex && potIndex != menuIndex) {
        menuIndex = potIndex;
        lastMenuIndex = menuIndex;
        lastPotIndex = potIndex;
        displayMenu();
    }
}