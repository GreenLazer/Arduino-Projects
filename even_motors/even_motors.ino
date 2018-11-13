int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(speedPin_M2, 100);
  digitalWrite(directionPin_M1, HIGH);
  digitalWrite(speedPin_M1, 100);
  digitalWrite(directionPin_M2, HIGH);
  delay(2000);
   digitalWrite(speedPin_M2, 0);
  digitalWrite(directionPin_M1, LOW);
  digitalWrite(speedPin_M1, 0);
  digitalWrite(directionPin_M2, LOW);

}
