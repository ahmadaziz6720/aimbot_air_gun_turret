# Importing Libraries
from serial import Serial
import time
arduino = Serial(port='COM6', baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(x.encode())
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    ax = input("Enter a number: ") # Ta
    ay = input("Enter a number: ") # Ta
    gabung = ax + " " +  ay
    print(gabung)
    value = write_read(gabung)
    print(value) # printing the value