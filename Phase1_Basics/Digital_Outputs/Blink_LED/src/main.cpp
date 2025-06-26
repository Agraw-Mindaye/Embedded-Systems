const int PIN_RED   = 9;
const int PIN_GREEN = 10;
const int PIN_BLUE  = 11;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED, 255 - R);   // Invert values for Common Anode
  analogWrite(PIN_GREEN, 255 - G);
  analogWrite(PIN_BLUE, 255 - B);
}

void loop() {
  setColor(255, 0, 0); // Red
  delay(500);
  setColor(0, 255, 0); // Green
  delay(500);
  setColor(0, 0, 255); // Blue
  delay(500);
}

