import serial
import time

micro = serial.Serial("COM15", 2000000, timeout=0.1)
time.sleep(2)

tiempos = []  

for i in range(100):
    micro.reset_input_buffer() 
    inicio = time.perf_counter()  

    micro.write(b"A")
    respuesta = micro.readline().decode().strip()  
    if respuesta == "A": 
        fin = time.perf_counter()  
        rtt = (fin - inicio) * 1000 
        tiempos.append(rtt)

if tiempos:
    promedio = sum(tiempos) / len(tiempos)
    print(f"{promedio:.4f}")

micro.close()  