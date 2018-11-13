
int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;

int del = 1300;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  carTurnRight(100,100);
  delay(1600);
  carStop();
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  Serial.print("\n");
//  Serial.print(del);
//  delay(del);
//  carStop();
//  carTurnLeft(100,100);
//  delay(del);
//  del+=10;
}

void carStop() {                //  Motor Stop
  digitalWrite(speedPin_M2, 0);
  digitalWrite(directionPin_M1, LOW);
  digitalWrite(speedPin_M1, 0);
  digitalWrite(directionPin_M2, LOW);
}

void carTurnRight(int leftSpeed, int rightSpeed) {         //Turn Right
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, LOW);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, HIGH);
}
void carTurnLeft(int leftSpeed, int rightSpeed) {        //Turn Left
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, LOW);
}
