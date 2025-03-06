void setup() {
  // Iniciar la comunicación serial
  Serial.begin(115200);
  
  // Obtener el tamaño de la memoria flash
  uint32_t flashSize = ESP.getFlashChipSize();

  // Mostrar el tamaño de la memoria flash en bytes
  Serial.print("Tamaño de la memoria flash: ");
  Serial.print(flashSize);
  Serial.println(" bytes");
}

void loop() {
  // No es necesario hacer nada en el loop
}