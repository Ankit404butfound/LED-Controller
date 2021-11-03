import serial
import pyautogui as ptg
import time

initial = (0, 0, 0)
final = (0, 0, 1)

ser = serial.Serial('COM4', timeout=0, rtscts=1)

while True:
    final = ptg.pixel(*ptg.position())
    if initial != final:
        initial = final
        data = f"{final[0]},{final[1]},{final[2]}\n"
        ser.write(bytes(data, encoding="ascii"))
        print(data)

        time.sleep(1)
