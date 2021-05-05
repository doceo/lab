import time
import serial

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)

ser.isOpen()

#print 'Enter your commands below.\r\nInsert "exit" to leave the application.'
out =''

time.sleep(1)
while 1:
    while ser.inWaiting() > 0:
        print(str(ser.read(1)))