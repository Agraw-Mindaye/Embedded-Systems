const int potentioPin = A0; // Potentiometer 

const int leds[] = {9,10,11,12,13}; // LED pins

void setup() {
    for (int i = 0; i < 5; i++) pinMode(leds[i], OUTPUT);
    Serial.begin(9600);
    
}

void loop() {
    int potentioValue = analogRead(potentioPin);
    Serial.println(potentioValue);

    int numLEDsOn = map(potentioValue, 0, 1023, 0, 5);

    for (int i = 0; i < 5; i++) {
        if (i < numLEDsOn) {
            digitalWrite(leds[i], HIGH);  // Turn on LED
        } else {
            digitalWrite(leds[i], LOW);   // Turn off LED
        }
    }

    delay(10);
}

