#script liberamente tratto da https://pymotw.com/2/socket/tcp.html

import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('localhost', 10000)
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
                connection.sendall(data)
            else:
                print >>sys.stderr, 'nessun altro dato da', client_address
                break
            
    finally:
        # Clean up the connection
        connection.close()
        
