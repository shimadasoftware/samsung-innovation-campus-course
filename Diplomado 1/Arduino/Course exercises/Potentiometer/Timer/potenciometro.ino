// Clase Martes 22 de Febrero
// Potenciometro  
// Uso del potenciometro para establecer un temporizador entre 1 y 10 segundos.

// Uso del potenciometro para establecer un temporizador entre 
// 1 y 10 segundos.
//

int potenciometro;
int pulsador = 1;
int pulsador_ant = 0;
int temporizador = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop()
{
  potenciometro = analogRead(A3); // retorna un valor entre 0 (0v) y 1023 (5v)
  
  Serial.println(potenciometro);
  pulsador_ant = pulsador;
  pulsador = digitalRead(7);
  //Serial.println(pulsador);
  
  if (pulsador_ant == 0 && pulsador == 1) {
    temporizador = potenciometro / 100;
    Serial.print("Temporizador:");
    Serial.println(temporizador);
    delay(100); // delay antirebote
  } 
  while (temporizador != 0) {
    delay(1000);
    temporizador -= 1;
    Serial.print("Temporizador:");
    Serial.println(temporizador);
  }
} 
