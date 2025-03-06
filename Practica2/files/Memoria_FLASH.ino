void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);

  // Calcular el tamaño de la memoria flash en bytes
  uint16_t flashSize = FLASHEND + 1; // FLASHEND es la última dirección de memoria flash

  // También puedes mostrarlo en kilobytes
  Serial.print("Tamaño de la memoria flash: ");
  Serial.print(flashSize / 1024.0);
  Serial.println(" KB");
}

void loop() {
  // No es necesario hacer nada en el loop
}