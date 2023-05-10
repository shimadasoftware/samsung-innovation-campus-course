// Clase Martes 22 de Febrero
// Chicharra  

int sonido;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  sonido = analogRead(A5); 
  Serial.println(sonido);

  if (sonido > 0) {
    tone(13, 262, 500); // Reproduce una nota (262 es frecuencia de DO) durante un tiempo en ms(500)
    delay(200);
    tone(13, 294, 500); // RE
    delay(200);
    tone(13, 330, 500); // MI
    delay(200);
    tone(13, 349, 500); // FA
    delay(200);
    tone(13, 392, 500); // SOL
    delay(200);
    tone(13, 440, 500); // LA
    delay(200);
    tone(13, 494, 500); // MI
    delay(200);
  } 
} 
