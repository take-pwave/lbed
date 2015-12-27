#include "SoftwareSerial.h"

#define trigPin 0
#define echoPin 1
SoftwareSerial pc(4, 3);

void setup() {
  pc.begin(4800);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    pc.println("Out of range");
  }
  else {
    pc.print(distance);
    pc.println(" cm");
  }
  delay(500);
}
