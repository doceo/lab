#script liberamente tratto da https://pymotw.com/2/socket/tcp.html

import socket
import sys
import random
import string

#definisco ip e porta del socket
server_address = ('localhost', 5001)

#funzione per riconoscere l'appartenenza ad un gruppo
def inviaCodice(parola):
	gruppi = ['GACP', 'DLMT88', 'DjIckar', 'Giosimera', 'Enzotor', 'Darkdj651', 'Vittraff', 'Pedataangelinocastelli']

	trovato = parola in gruppi
	
	if trovato:
		quesito = 'domande/domanda' + str(random.randint(1, 4)) + '.txt'

		#print quesito

		in_file = open(quesito,"r")
		domanda = in_file.read()
		in_file.close()

		
	else:
		domanda = str(-1)	
	
	return domanda










# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
#server_address = ('localhost', 5000)
print >>sys.stderr, 'in ascolto su %s porta %s' % server_address
sock.bind(server_address)

# Listen for incoming connections
sock.listen(1)

while (1):
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
                risposta = inviaCodice(data)

                connection.sendall(risposta)
                
                
            else:
                print >>sys.stderr, 'nessun altro dato da', client_address
                break
            
    finally:
        # Clean up the connection
        connection.close()
        
