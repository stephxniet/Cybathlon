#include <Servo.h>

Servo prostheticServo;

const int grabButtonPin = 2;   // Grab button input pin
const int releaseButtonPin = 3; // Release button input pin
const int servoPin = 9;        // Servo control pin

const int openPos = 0;         // Servo position for open hand
const int closedPos = 90;      // Servo position for closed hand

void setup() {
  prostheticServo.attach(servoPin);
  prostheticServo.write(openPos);  // Start with hand open

  pinMode(grabButtonPin, INPUT_PULLUP);    // Assuming button connected to ground
  pinMode(releaseButtonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  bool grabPressed = digitalRead(grabButtonPin) == LOW;     // Active low button
  bool releasePressed = digitalRead(releaseButtonPin) == LOW;

  if (grabPressed) {
    prostheticServo.write(closedPos);  // Grab command
    Serial.println("Grab pressed: closing hand");
  } else if (releasePressed) {
    prostheticServo.write(openPos);    // Release command
    Serial.println("Release pressed: opening hand");
  }

  delay(50);  // Debounce delay
}
