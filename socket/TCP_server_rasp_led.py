#!/usr/bin/env python

import socket
import RPi.GPIO as GPIO
import time
import sys
import random
	



def inviaCodice(parola):
	gruppi = ['GACP', 'DLMT88', 'DjIckar', 'Giosimera', 'Enzotor', 'Darkdj651', 'Vittraff', 'Pedataangelinocastelli']

	trovato = parola in gruppi
	
	if trovato:
		domanda = random.randint(1, 10)
	else:
		domanda = -1	
	
	return domanda
	
				

def accendiLed():

	nLed = 8
	
	for giri in range(10):
		while i<nLed:
		
			print "LED on"
			GPIO.output(led[i],GPIO.HIGH) 	#accendo il led, corrispondente al comando: gpio write 0 1
			time.sleep(0.1)             		#attendo 1 secondo
			print "LED off"
			GPIO.output(led[i],GPIO.LOW)  	#spengo il led, corrispondente al comando: gpio write 0 0
			
			i = i+1



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


#configuro il server in ascolto

BUFFER_SIZE = 20  # Normally 1024, but we want fast response

#crea un socket TCP/IP
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Associa IP alla porta
server_address = ('192.168.1.249', 5005)
print >>sys.stderr, 'in ascolto su %s porta %s' % server_address
sock.bind(server_address)

sock.listen(1)

conn, addr = s.accept()
print 'Connection address:', addr
while 1:
	# Wait for a connection
    print >>sys.stderr, 'In attesa di connessione...'
    connection, client_address = sock.accept()
	
	try:
        print >>sys.stderr, 'una connessione da', client_address

        # Receive the data in small chunks and retransmit it
        while True:
            data = connection.recv(32)
            print >>sys.stderr, 'ricevuto "%s"' % data
            if data:
                print >>sys.stderr, 'rinvia il dato al client'
                connection.sendall(inviaCodice(data))
            else:
                print >>sys.stderr, 'nessun altro dato da', client_address
                break
            
    finally:
        # Clean up the connection
        connection.close()
	
	
