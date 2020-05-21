from picamera import *
import time

camera = PiCamera() 
camera.start_preview()
for i in range(9):
	time.sleep(5)
	data = '{:>5.0f}'.format(time.monotonic())
	camera.capture('image/image%s.jpg' % data)
camera.stop_preview()
