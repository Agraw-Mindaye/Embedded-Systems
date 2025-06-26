const int leds[] = {9,10,11}; // LED pins

int size = sizeof(leds) / sizeof(leds[0]);

void setup() {
    for (int i = 0; i < size; i++) {
        pinMode(leds[i], OUTPUT);
    }

    Serial.begin(9600);
    Serial.println("Enter commands like 1, 1, 2, 2off, etc. to turn on/off the LEDs");
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n'); // read input until enter key

        input.trim();

         if (input == "1") {
            digitalWrite(leds[0], HIGH);
            Serial.println("LED 1 ON");
        } else if (input == "1off") {
            digitalWrite(leds[0], LOW);
            Serial.println("LED 1 OFF");
        } else if (input == "2") {
            digitalWrite(leds[1], HIGH);
            Serial.println("LED 2 ON");
        } else if (input == "2off") {
            digitalWrite(leds[1], LOW);
            Serial.println("LED 2 OFF");
        } else if (input == "3") {
            digitalWrite(leds[2], HIGH);
            Serial.println("LED 3 ON");
        } else if (input == "3off") {
            digitalWrite(leds[2], LOW);
            Serial.println("LED 3 OFF");
        } else {
            Serial.println("Invalid command. Try: 1, 1off, 2, 2off, 3, 3off");
        }
    }
}