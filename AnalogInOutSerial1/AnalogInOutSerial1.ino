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

// These constants won't change. They're used to give names to the pins used: // Analog output pin that the LED is attached to

int sens1 = 0;  // value read from the pot
int sens2 = 0;
int sens3 = 0;
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sens1 = analogRead(A6);
  sens2 = analogRead(A7);
  sens3 = analogRead(A8);
  // map it to the range of the analog out:
  outputValue = map(sens1, 0, 1023, 0, 255);
  // change the analog out value:
  if(sens1 > 500  && sens1 > 500 && sens2 > 500 && sens3 > 500){
    analogWrite(5, HIGH);
    }else{
      analogWrite(5, LOW);
      }

  // print the results to the Serial Monitor:
  Serial.print("sens1 = ");
  Serial.print(sens1);
  Serial.print("\t sens2 = ");
  Serial.println(sens2);
  Serial.print("\t sens3 = ");
  Serial.println(sens3);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
