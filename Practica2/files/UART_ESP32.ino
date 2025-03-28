void setup() {
  Serial.begin(115200); // Inicia la comunicación serial a 115200 baudios
  Serial.println("Monitor Serial Iniciado");
}

void loop() {
  Serial.println("Hola, ESP32 está funcionando");
  delay(1000); // Espera 1 segundo
}
