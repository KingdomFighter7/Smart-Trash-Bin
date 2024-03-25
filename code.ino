#include <Servo.h>
#include "ultrasonic.h"

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 5;

long duration;
int distance;

Servo myservo;
UltrasonicSensor sesul(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  myservo.attach(servoPin);
}

void loop() {
  sesul.trigger();
  delayMicroseconds(2);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 10) {
    myservo.write(90);
    delay(5000);
    myservo.write(0);
    delay(500);
  } else {
    myservo.write(0);
    delay(500);
  }
}
