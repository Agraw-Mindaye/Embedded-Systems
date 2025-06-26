#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 13;   // PWM-capable pin for servo signal
const int potPin = 4;     // Analog pin connected to pot

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  int potValue = analogRead(potPin); // Read analog value (0–4095)
  int angle = map(potValue, 0, 4095, 0, 180); // Convert to 0–180°

  myServo.write(angle); // Set servo angle
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(angle);

  delay(20);
}
