const int potentioPin = A0; // Potentiometer 
const int ledPin = 9;       // LED

void setup()
{
    pinMode(ledPin, OUTPUT); // set LED as ouput
    Serial.begin(9600);      
}   

void loop()
{
    int potentioValue = analogRead(potentioPin);            // read potentiometer value (0 - 1023)
    int brightness = map(potentioValue, 0, 1023, 0, 255);   // convert potentiometer value to PWM range (0 - 255) 

    analogWrite(ledPin, brightness); // adjust LED brightness
    Serial.println(potentioValue);   // print value for debugging
    delay(10);
}
