
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

char tiltDirection;
int motorInput1 = 5;
int motorInput2 = 6;
int motorInput3 = 3;
int motorInput4 = 9;

void setup() {
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

  Serial.begin(38400);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    tiltDirection = BTSerial.read();

    if (tiltDirection == 'F') {
      reverse();
    } else if (tiltDirection == 'B') {
      forward();
    } else if (tiltDirection == 'R') {
      left();
    } else if (tiltDirection == 'L') {
      right();
    } else if (tiltDirection == 'S') {
      stopCar();
    }
  }
}

void forward() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

void reverse() {
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}

void right() {
  digitalWrite(motorInput1, LOW);
  analogWrite(motorInput2, 150);
  analogWrite(motorInput3, 150);
  digitalWrite(motorInput4, LOW);
}

void left() {
  analogWrite(motorInput1, 150);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  analogWrite(motorInput4, 150);
}

void stopCar() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
