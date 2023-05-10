/********************************************************************************************************************
 * Final Proyect - Lamp.
 *
 * When a lamp detects that a baby is crying (a noise) using the microphone sensor,
 * the 3 lights (3 LEDs) of the lamp should turn on automatically in a sequence accompanied by sounds of the buzzer.
 * 
 * When the baby stops crying, wait a second and turn off the lamp.
 * 
 * Samsung Innovation Campus
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, March 2022.
 *******************************************************************************************************************/

#define PIN_LEFT_LED 13
#define PIN_CENTER_LED 11
#define PIN_RIGHT_LED 9
#define PIN_MELODY 2

int sound = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MELODY, OUTPUT);            // Initialize the melody sensor on pin 2.
  pinMode(PIN_RIGHT_LED, OUTPUT);         // Initialize the LED on pin 09.
  pinMode(PIN_CENTER_LED, OUTPUT);        // Initialize the LED on pin 11.
  pinMode(PIN_LEFT_LED, OUTPUT);          // Initialize the LED on pin 13.
}

void loop() {
  sound = analogRead(A5);       
  Serial.println(sound);     
  
  if (sound > 40) {
    for (int i = PIN_LEFT_LED; i >= PIN_RIGHT_LED; i -= 2) {
      delay(500);
      tone(PIN_MELODY, 262, 500);         // pin, frequency, duration.
      digitalWrite(i, HIGH);  
    } 
  } 
  
  else if (sound < 40) {
    delay(1000);
    for (int i = PIN_LEFT_LED; i >= PIN_RIGHT_LED; i -= 2) {
      digitalWrite(i, LOW); 
      noTone(PIN_MELODY); 
    } 
  }
}
