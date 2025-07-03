#include <Servo.h>

Servo prostheticServo;

const int grabButtonPin = 2;
const int releaseButtonPin = 3;
const int servoPin = 9;

const int openPos = 0;
const int closedPos = 180;

void setup() {
  prostheticServo.attach(servoPin);
  prostheticServo.write(openPos);

  pinMode(grabButtonPin, INPUT_PULLUP);
  pinMode(releaseButtonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  bool grabPressed = digitalRead(grabButtonPin) == LOW;
  bool releasePressed = digitalRead(releaseButtonPin) == LOW;

  if (grabPressed) {
    prostheticServo.write(closedPos);
    Serial.println("Grab pressed: closing hand");
  } else if (releasePressed) {
    prostheticServo.write(openPos);
    Serial.println("Release pressed: opening hand");
  }

  delay(50);
}
