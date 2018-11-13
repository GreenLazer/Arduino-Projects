/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

 // analog pin used to connect the potentiometer
int val1;  
int val2;// variable to read the value from the analog pin
int pos = 0;
void setup() {
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val1 = analogRead(A5);            // reads the value of the potentiometer (value between 0 and 1023)
//  val2 = analogRead(A8);  
  if(val1 > 100){
    pos = 180;
    }
//   if(val2 >100){
//      pos = 0;
//    }
    // scale it to use it with the servo (value between 0 and 180)
                  // sets the servo position according to the scaled value
      myservo.write(pos);                     // waits for the servo to get there
}

