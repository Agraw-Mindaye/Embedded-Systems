const int ledPin = 9;
const long interval = 1000; // interval (ms) for LED to blink
unsigned long prevMillis = 0; // stores 

bool ledState = LOW; // initially off

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    unsigned long currMillis = millis(); 

    if (currMillis - prevMillis >= interval) {
        prevMillis = currMillis;

        ledState = !ledState; //toggle LED
        digitalWrite(ledPin, ledState);
    }

    /* 
        other tasks can be done here since millis() is non-blovking
    */
}
