#from picamera import PiCamera
import time

#camera.start_preview()
while(1):
	time.sleep(1)
	data = '{:>5.0f}'.format(time.monotonic())
	f = open('file/%s.txt'%data, 'w')
	#    camera.capture('/home/pi/image%s.jpg' % i)
