#include <DHT.h>

// pin definitions
#define DHTPIN 3
#define DHTTYPE DHT11
const int potPin = A1;
const int buttonPin = 2;

// DHT sensor and timer
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastDHTReadTime = 0;
const unsigned long dhtInterval = 2000; // read every 2 seconds

// button devounce
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool alertMode = true;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  dht.begin();
}

void loop() {

  // read button input with debounce
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState == LOW && lastButtonState == HIGH) {
      alertMode = !alertMode;
    }
  }
  lastButtonState = buttonState;


  // read potentiometer input
  int potValue = analogRead(potPin);
  float threshold = map(potValue, 0, 1023, 600, 950) / 10.0;


  // read DHT11 temperature and humiduty
  if (millis() - lastDHTReadTime >= dhtInterval) {
    lastDHTReadTime = millis();

    float tempF = dht.readTemperature(true); // true = Fahrenheit
    if (isnan(tempF)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }


    // serial Output 
    Serial.print("Temperature: ");
    Serial.print(tempF, 1);
    Serial.print("°F | Threshold: ");
    Serial.print(threshold, 1);
    Serial.print("°F | Alert: ");

    if (alertMode && tempF > threshold) {
      Serial.println("ON ⚠️");
    } else {
      Serial.println("OFF");
    }

    Serial.println("---");
  }
}
