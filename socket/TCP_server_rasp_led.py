#!/usr/bin/env python

import socket
import RPi.GPIO as GPIO
import time

TCP_IP = '192.168.1.249'
TCP_PORT = 5005
BUFFER_SIZE = 20  # Normally 1024, but we want fast response


GPIO.setmode(GPIO.BCM)    #usiamo la numerazione BCM
GPIO.setwarnings(False)

#associamo ad ogni led il corrispettivo pin GPIO
ledUno = 5
ledDue = 6
ledTre = 16
ledQuattro = 17
ledCinque = 22
ledSei = 23
ledSette = 24
ledOtto = 25

#creiamo una lista che tiene conto delle posizioni dei led
led = [ledUno, ledDue, ledTre, ledQuattro, ledCinque, ledSei, ledSette, ledOtto]

GPIO.setup(ledUno, GPIO.OUT)   #imposto Pin 5 ad out
GPIO.setup(ledDue, GPIO.OUT)   #imposto Pin 6 ad out
GPIO.setup(ledTre, GPIO.OUT)   #imposto Pin 16 ad out
GPIO.setup(ledQuattro, GPIO.OUT)   #imposto Pin 17 ad out
GPIO.setup(ledCinque, GPIO.OUT)   #imposto Pin 22 ad out
GPIO.setup(ledSei, GPIO.OUT)   #imposto Pin 23 ad out
GPIO.setup(ledSette, GPIO.OUT)   #imposto Pin 24 ad out
GPIO.setup(ledOtto, GPIO.OUT)   #imposto Pin 25 ad out

#per utilizzare i GPIO:



s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print 'Connection address:', addr
while 1:
	data = conn.recv(BUFFER_SIZE)
	if not data: break
	print "received data:", data
	
	nLed = int(data)
	
	for giri in range(10):
		while i<nLed:
		
			print "LED on"
			GPIO.output(led[i],GPIO.HIGH) 	#accendo il led, corrispondente al comando: gpio write 0 1
			time.sleep(1)             		#attendo 1 secondo
			print "LED off"
			GPIO.output(led[i],GPIO.LOW)  	#spengo il led, corrispondente al comando: gpio write 0 0
			
			i = i+1
	
	
	conn.send(data)  # echo
conn.close()

