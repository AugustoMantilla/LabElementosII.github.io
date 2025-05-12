import paho.mqtt.client as mqtt

# Configuración del broker MQTT y canal
mqtt_broker = "test.mosquitto.org"
topic = "elementos2/augusto"

# Función que se ejecuta cuando el cliente se conecta al broker
def on_connect(client, userdata, flags, rc):
    print(f"Conectado al broker MQTT con código {rc}")
    print("Escribe un mensaje y presiona Enter para enviarlo (escribe 'exit' para salir):")

# Crear el cliente MQTT
client = mqtt.Client()

# Asignar la función de conexión
client.on_connect = on_connect

# Conectar al broker
client.connect(mqtt_broker, 1883, 60)

# Iniciar el loop en un hilo secundario para mantener la conexión activa
client.loop_start()

# Bucle para enviar mensajes desde la terminal
try:
    while True:
        mensaje = input("> ")  # Leer mensaje desde la terminal
        if mensaje.lower() == "exit":
            break  # Salir del programa si el usuario escribe 'exit'
        client.publish(topic, mensaje)  # Publicar el mensaje en MQTT
        print(f"Mensaje enviado: {mensaje}")

except KeyboardInterrupt:
    print("\nCerrando conexión...")

# Detener el loop y cerrar la conexión MQTT
client.loop_stop()
client.disconnect()
print("Desconectado del broker MQTT.")
