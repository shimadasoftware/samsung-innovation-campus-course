// Clase Jueves 24 de Febrero
// Sensor de melodia  

// Programa para activar y desactivar el sensor de melodia FTB6
// usando un pulsador.

#define PIN_PULSADOR 7

int pulsador = 1;
int pulsador_ant = 0;
int melodia = 0;

void setup() {
  pinMode(PIN_PULSADOR, INPUT); // pin pulsador
  pinMode(13, OUTPUT);          // pin melodia
}

void loop() {
  pulsador_ant = pulsador;
  pulsador = digitalRead(PIN_PULSADOR);

  if (pulsador_ant == 0 && pulsador == 1) {
    melodia =~ melodia;
    digitalWrite(13, melodia);
  }
} 
