from picamera import PiCamera
import time

camera = PiCamera() 

camera.start_preview()
time.sleep(10)
camera.capture('image/image.jpg')
camera.stop_preview()

