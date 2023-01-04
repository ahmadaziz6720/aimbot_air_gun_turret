# Importing Libraries
from serial import Serial
import time
esp32_serial = Serial(port='COM6', baudrate=250000, timeout=.1)
ax = 0
ay = 100
while True:
    ax += 1
    ay -= 1
    
    gabung = str(ax) + " " +  str(ay)
    starttime = time.time_ns()
    esp32_serial.write(gabung.encode())
    returnval = esp32_serial.readline()

    print("nilai kembali =  ", returnval, "time ms = ", (time.time_ns() - starttime) / 1000000)

    if ax == 100:
        ax = 0
        ay = 100