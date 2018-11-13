#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo1;

int pos = 20;    // variable to store the servo position

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;
int dlynum = 2900; // for perfect circle at little bit of real pressure

int leftSpeed = 90;
int rightSpeed = 90;
int speedCap = 250;
int directions = LOW;
int l = 100;
int r = 100;

void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  myservo1.attach(7);
}

void loop() {
//  down(true, true);
//  up(true, true);
  artWave();
}

void roundWheel(int divisor, bool turnRight) {
  int left = 0;
  int right = 130;
  if (turnRight == true) {
    left = 130;
    right = 0;
  }
  analogWrite (speedPin_M2, left);
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, right);
  digitalWrite(directionPin_M2, HIGH);
  delay((dlynum * 2) / divisor);
  carStop();
}

void roundSelf(int divisor, bool turnRight) {
  int leftDir = HIGH;
  int rightDir = LOW;
  if (turnRight == true) {
    int leftDir = LOW;
    int rightDir = HIGH;
  }
  analogWrite (speedPin_M2, 100); //leftspeed
  digitalWrite(directionPin_M1, leftDir);
  analogWrite (speedPin_M1, 100); //right speed
  digitalWrite(directionPin_M2, rightDir);
  delay(dlynum / divisor);
  carStop();
}

void carStop() {                //  Motor Stop
  digitalWrite(speedPin_M2, 0);
  digitalWrite(directionPin_M1, LOW);
  digitalWrite(speedPin_M1, 0);
  digitalWrite(directionPin_M2, LOW);
}

void carAdvance(int leftSpeed, int rightSpeed) {       //Move forward
  analogWrite (speedPin_M2, leftSpeed);             //PWM Speed Control
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, HIGH);
}

void carBack(int leftSpeed, int rightSpeed) {     //Move backward
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, LOW);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, LOW);
}
void kernal() {
  analogWrite (speedPin_M2, 1500); //leftspeed
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, 150); //right speed
  digitalWrite(directionPin_M2, LOW);
  delay(2000);
  carBack(130, 90);
  delay(500);
  carStop();
}
void artWave() {
  carBack(l, r);
  delay(500);
  carStop();
  l += 50;
  carAdvance(l, r);
  delay(1000);
  carStop();
  r += 50;
  carAdvance(l, r);
  delay(500);
  carStop();
  r += 50;
  carAdvance(l, r);
  delay(1000);
  carStop();
  l += 50;
}

void flower() {
  down(true, true);
  roundSelf(2, true);
  up(true, true);
  carBack(100, 100);
  delay(500);
  carStop();
  delay(500);
}
void street() {
  down(true, true);
  delay(100);
  carBack(100, 100);
}

void circ() {
  down(true,true);
  delay(100);
  carAdvance(100, 100);
}
void waves() {
  while (leftSpeed < speedCap) {
    Serial.print("\n  going left from:");
    Serial.print(leftSpeed);
    Serial.print("against right:");
    Serial.print(rightSpeed);
    analogWrite (speedPin_M2, leftSpeed);             //PWM Speed Control
    digitalWrite(directionPin_M1, directions);
    analogWrite (speedPin_M1, rightSpeed);
    digitalWrite(directionPin_M2, directions);
    delay(500);
    carStop();
    leftSpeed += 10;
    rightSpeed -= 10;
  }
  while (rightSpeed < speedCap) {
    Serial.print("  \n going right from:");
    Serial.print(rightSpeed);
    Serial.print("against left:");
    Serial.print(leftSpeed);
    analogWrite (speedPin_M2, leftSpeed);             //PWM Speed Control
    digitalWrite(directionPin_M1, directions);
    analogWrite (speedPin_M1, rightSpeed);
    digitalWrite(directionPin_M2, directions);
    delay(500);
    carStop();
    leftSpeed -= 10;
    rightSpeed += 10;
  }
}

void down(bool left, bool right) {
  for (pos = 50; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree
    if (right) {
      myservo.write(pos);
    }// tell servo to go to position in variable 'pos'
    if (left) {
      myservo1.write(pos);
    }
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void up(bool left, bool right) {
  for (pos = 100; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
   if (right) {
      myservo.write(pos);
    }// tell servo to go to position in variable 'pos'
    if (left) {
      myservo1.write(pos);
    }
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
