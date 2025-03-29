const int buzzerPin = 4;  // Pin del buzzer (ajusta según tu conexión)
unsigned long tiempoInicio;
unsigned long tiempoFinal;
unsigned long tiempoTotal;

void setup() {
  pinMode(buzzerPin, OUTPUT);  
  tiempoInicio = micros();  // Guarda el tiempo inicial en microsegundos
}

void loop() {
  // Realiza alguna operación intensiva (ejemplo: un cálculo matemático)
  for (volatile long i = 0; i < 1000000; i++) {
    __asm__ __volatile__ ("nop");  // Instrucción de "no operación" para simular procesamiento
  }

  tiempoFinal = micros();  // Guarda el tiempo final
  tiempoTotal = tiempoFinal - tiempoInicio;  // Calcula el tiempo total

  // Activa el buzzer para indicar que terminó
  tone(buzzerPin, 1000, 20000);  // 1000 Hz, 200 ms de duración
  delay(500);  // Pequeña pausa para evitar repeticiones rápidas

  // Reinicia el tiempo para la próxima medición
  tiempoInicio = micros();
}