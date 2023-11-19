/***********************************************************************************************************
 * Final Proyect - Kitchen.
 *
 * In the kitchen there is a knob (potentiometer) to adjust the time of a timer between 1 and 10 seconds.
 * The user can see the selected value on the serial monitor.
 * 
 * When a power button is pressed, the timer is activated and; When the time is up,
 * a buzzer sounds and a flashing light is activated until an off button is pressed.
 * 
 * Samsung Innovation Campus
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, March 2022.
 **********************************************************************************************************/
 
#define PIN_MELODY 2
#define PIN_BUTTON_ON 7
#define PIN_BUTTON_OFF 13
#define PIN_LED 12

int potentiometer;
int button = 1;
int prev_button = 0;
int button_off = -1;
int timer = 0;
int melody = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MELODY, OUTPUT);            // Initialize the melody sensor on pin 2.
  pinMode(PIN_BUTTON_ON, INPUT);          // Initialize the putton on pin 7.
  pinMode(PIN_BUTTON_OFF, INPUT);         // Initialize the putton on pin 13.
  pinMode(PIN_LED, OUTPUT);               // Initialize the LED on pin 12.
}

void loop() {
  potentiometer = analogRead(A0);         // Returns a value between 0 (0v) and 1023 (5v).
  Serial.println(potentiometer);     
  
  prev_button = button;
  button = digitalRead(PIN_BUTTON_ON);

  if (prev_button == 0 && button == 1) {
    timer = potentiometer / 100;
  }
  
  while (timer != 0) {
    Serial.print("Timer:");
    Serial.println(timer);
    delay(1000);
    timer -= 1;
    button_off = 1;
  }

  while (button_off == 1) {
    digitalWrite(PIN_MELODY, ~melody);
    digitalWrite(PIN_LED, HIGH);
    delay(125);
    digitalWrite(PIN_LED, LOW);
    delay(125);
    button_off = digitalRead(PIN_BUTTON_OFF);
  }
  
  if (button_off == 0) {
    digitalWrite(PIN_MELODY, melody);
    digitalWrite(PIN_LED, LOW);
    button_off = -1;
  } 
}
