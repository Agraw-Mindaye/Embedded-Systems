int buttonPin = 2;     // Pin connected to the push button
int ledPin = 12;       // Pin connected to the LED
int buttonState = 0;    // Variable to hold the button state

void setup() {
  pinMode(buttonPin, INPUT);    // Set the button pin as input
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the state of the push button

  if (buttonState == HIGH) {    // If button is pressed
    digitalWrite(ledPin, HIGH); // Turn the LED ON
  } else {                      // If button is not pressed
    digitalWrite(ledPin, LOW);  // Turn the LED OFF
  }
}
