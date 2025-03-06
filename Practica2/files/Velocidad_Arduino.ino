unsigned long startTime;
unsigned long endTime;
unsigned long loopCount = 0;

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial
  startTime = millis(); // Guarda el tiempo inicial
}

void loop() {
  loopCount++; // Incrementa el contador de bucles

  endTime = millis(); // Guarda el tiempo actual

  // Si ha pasado 1 segundo, imprime el número de bucles y reinicia el contador
  if (endTime - startTime >= 1000) {
    Serial.print("Bucles por segundo: ");
    Serial.println(loopCount);

    loopCount = 0; // Reinicia el contador de bucles
    startTime = millis(); // Reinicia el tiempo inicial
  }
}