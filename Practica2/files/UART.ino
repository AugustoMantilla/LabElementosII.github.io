void setup() {
    Serial.begin(9600); // Inicializa el Monitor Serial a 9600 baudios
    Serial.println("Monitor Serial Iniciado. Escribe algo:");
}

void loop() {
    if (Serial.available() > 0) { // Verifica si hay datos en el buffer serial
        String entrada = Serial.readStringUntil('\n'); // Lee el dato ingresado
        Serial.print("Recibido: ");
        Serial.println(entrada); // Muestra el dato en el monitor serial
    }
}
