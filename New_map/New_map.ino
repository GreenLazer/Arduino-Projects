#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 20;    // variable to store the servo position


int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;
int dlynum = 2900; // for perfect circle at little bit of real pressure
int compensate = 0;

int sensorValue = 0;  // variable to store the value coming from the sensor

//coordinates
int x = 0;
int y = 0;
int xadd = 1;

//bit & pieces for fucntions
bool distneg = false;

int place = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  roundWheel(1, true);
}

void loop() {
  //  sensorValue = analogRead(A5);
  //  Serial.print(sensorValue);
  //  if (sensorValue > 500) {
  //  }
  //  else {
  //    carStop();
  //  }
  delay(2);
}

void xmove(int desiredx, bool draw) {
  int distx = desiredx - x;
  x += distx;
  if (draw == true) {
    down();
    compensate = -5;
  }
  if (distx < 0) {
    distx = distx * -1;
    carBack(100, 100 + compensate);
  }
  else {
    carAdvance(100, 100 + compensate);
  }
  delay(distx * 25);
  carStop();
  if (draw == true) {
    up();
    compensate = 0;
  }
}


void ymove(int desiredy, bool draw) {
  int disty = desiredy - y;
  y += disty;
  //align pen
  carBack(100, 100);
  delay(450);
  carStop();
  //turn right dir
  if (disty < 0) {
    distneg = true;
    roundWheel(4, false); 
    disty *= -1;
  }
  else {
    roundWheel(4, true); //right
  }
  //align pen
  carBack(100, 100);
  delay(750);
  carStop();
  delay(100);
  //pen
  if (draw == true) {
    down();
    compensate = -5;
  }
  // move
  carAdvance(100, 100 + compensate);
  delay(disty * 25);
  carStop();
  //pen
  if (draw == true) {
    up();
    compensate = 0;
  }
  //reset
  if (distneg == true) {
    roundWheel(4, true);
    distneg = false;
  }
  else {
    roundWheel(4, false);
  }
}


void roundWheel(int divisor, bool turnRight) {
  int leftSpeed = 0;
  int rightSpeed = 100;
  if (turnRight == true) {
    int leftSpeed = 100;
    int rightSpeed = 0;
  }
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, HIGH);
  delay(dlynum / divisor);
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


void up() {
  for (pos = 50; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void down() {
  for (pos = 100; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
