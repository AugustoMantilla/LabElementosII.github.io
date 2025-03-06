unsigned long tiempoInicio, tiempoFin;
const int operaciones = 1000000; // Número de operaciones a medir

void setup() {
    Serial.begin(115200); // Inicializa el Monitor Serial a 115200 baudios

    tiempoInicio = micros(); // Guarda el tiempo inicial en microsegundos

    for (int i = 0; i < operaciones; i++) {
        volatile int x = i * 2; // Operación simple para evaluar velocidad
    }

    tiempoFin = micros(); // Guarda el tiempo final en microsegundos

    unsigned long tiempoTotal = tiempoFin - tiempoInicio;

    float operacionesPorSegundo = (operaciones / (tiempoTotal / 1000000.0));
    Serial.print("Operaciones por segundo: ");
    Serial.println(operacionesPorSegundo);
}

void loop() {
    // No hace nada después de la medición
}
