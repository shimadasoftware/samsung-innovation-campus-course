/*******************************************************************************
 * LEDS IN SEQUENCE.
 *
 * Program that turns on sequentially (one by one) a row of five LEDs. 
 * The time they remain on is 1 second. When the first button is pressed, 
 * the current speed is halved, but when the second button is pressed, 
 * the current speed is doubled.
 *
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, Frebruary 2021.
 ******************************************************************************/
int speed = 1000;
int button1;
int button2;
int i = 4;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  button1 = digitalRead(13);
  button2 = digitalRead(12);

  if (button1 == 0) {
    speed *= 2;
  } 
  if (button2 == 0) {
    speed /= 2;
  }
  digitalWrite(i, HIGH);
  delay(speed);
  digitalWrite(i, LOW);
  i--;
  if (i < 0) {
    i = 4;
  }
}
