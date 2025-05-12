#include <WiFi.h>
#include <PubSubClient.h>

// Configuración WiFi
const char* ssid = "Guty";  
const char* password = "123456789";

// Configuración del broker MQTT
const char* mqtt_server = "test.mosquitto.org";  
const char* topic = "elementos2/augusto";

WiFiClient espClient;
PubSubClient client(espClient);

// Función de conexión WiFi
void setup_wifi() {
    delay(10);
    //Serial.println("Conectando a WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi conectado.");
}

// Función de reconexión MQTT
void reconnect() {
    while (!client.connected()) {
        //Serial.print("Conectando a MQTT...");
        if (client.connect("ESP32_Client")) {
            //Serial.println("Conectado!");
            client.subscribe(topic);  // Suscripción al canal
        } else {
            //Serial.print("Falló. Código: ");
            //Serial.print(client.state());
            //Serial.println(" Intentando en 5 segundos...");
            delay(5000);
        }
    }
}

// Callback cuando se recibe un mensaje MQTT
void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Mensaje recibido en el canal: ");
    Serial.println(topic);
    Serial.print("Contenido: ");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

    reconnect();  // Reconectar y suscribirse al canal
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();  // Mantener la conexión MQTT abierta
}
