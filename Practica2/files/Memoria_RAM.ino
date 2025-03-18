void setup() {
  // Iniciar la comunicación serial
  Serial.begin(115200);

  // Calcular la memoria RAM disponible
  int freeRAM = ESP.getFreeHeap();

  // Mostrar la memoria RAM disponible en el monitor serial
  Serial.print("Memoria RAM: ");
  Serial.print(freeRAM);
  Serial.println(" bytes");
}

void loop() {
  // No es necesario hacer nada en el loop para esta tarea
}