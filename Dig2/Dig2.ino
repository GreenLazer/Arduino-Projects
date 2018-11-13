/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:       // value read from the pot
int potValue = 0;        // value output to the PWM (analog out)
int backValue = 0;
int frontValue = 0;

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

bool honing = false;
bool detect = false;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(A5);
//  Serial.print(" pot output = ");
//  Serial.println(potValue);

  backValue = analogRead(A2);
  Serial.print("\t back = ");
  Serial.println(backValue);

  frontValue = analogRead(A6);
    Serial.print("front = ");
    Serial.println(frontValue);

  if (potValue > 500) {

    if (backValue < 100) {
      carAdvance(100, 0); //spin
      
    }
    
    if (backValue > 110 and backValue < 400) {
      carBack(100, 100);
      //      Serial.print("moving forward");
    }
//    else if (frontValue > 100 and frontValue < 400) {
//      carAdvance(200, 200);
//    }
    if(backValue > 400){
      carStop();
      }


  }
  else {
    carStop();
  }
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(200);

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

void carBack(int right, int left) {  //Move backward
  analogWrite (speedPin_M2, left); //leftspeed
  digitalWrite(directionPin_M1, LOW);
  analogWrite (speedPin_M1, right); //rightspeed
  digitalWrite(directionPin_M2, LOW);
}

void carTurn(int leftSpeed, int rightSpeed) {        //Turn Left
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, LOW);
}
