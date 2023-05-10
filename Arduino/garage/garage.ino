/****************************************************************************************************
 * Final Proyect - Garage.
 *
 * When a car approaches the garage (detected with the piezoelectric sensor), 
 * the door must be opened by turning the door servomotor to 90º and turning on the garage light.
 * 
 * When it is detected, with another sensor of your choice, that the car has entered, 
 * you must close the garage door by setting the servo to 0° and turn off the light.
 * 
 * When the door is closing, a warning sound should be activated by the buzzer.
 * 
 * Samsung Innovation Campus
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, March 2022.
 ***************************************************************************************************/

#define PIN_LED 13
#define PIN_MELODY 2

int angle = 0;
int melody = 0;
int external_piezo;
int internal_piezo;
int garbage;

void setup() {
  myServo.attach(6);                      // Initialize the servo motor on pin 6 (must have tilde mark).
  pinMode(PIN_LED, OUTPUT);               // Initialize the LED on pin 13.
  pinMode(PIN_MELODY, OUTPUT);            // Initialize the melody sensor on pin 2.
}

void loop() {
  external_piezo = analogRead(A1); 
  internal_piezo = analogRead(A0);
  myServo.write(angle); 
  
  if (Serial.available()) {
    angle = Serial.parseInt();            // Take from the serial port the value of the angle for the motor.
    garbage = Serial.read();              // Eliminate garbage from the port.
  }
  
  if (external_piezo > 200) {
    for (int i = 10; i <= 90; i += 10) {  // The effect of the door opening slowly.
      myServo.write(i); 
      delay(200);
    }
    angle = 90;
    digitalWrite(PIN_LED, HIGH); 
  }
  
  else if (internal_piezo > 200) {
    myServo.write(0);
    angle = 0;
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_MELODY, ~melody);
    delay(1000);
  }
  digitalWrite(PIN_MELODY, melody);
}
