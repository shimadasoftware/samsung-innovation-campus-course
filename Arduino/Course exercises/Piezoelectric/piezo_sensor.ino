// Clase Martes 15 de Febrero
// Sensor piezo eléctrico

int sensorPiezo = 0;

void setup() {
  pinMode(13, OUTPUT);       // LED
  Serial.begin(9600);
}

void loop() {
  sensorPiezo = analogRead(A2);      // se lee el valor del sensor piezo
  Serial.println(sensorPiezo);
  delay(100);
}
