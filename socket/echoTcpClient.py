#script liberamente tratto da https://pymotw.com/2/socket/tcp.html


import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('localhost', 10000)
print >>sys.stderr, 'connesso a %s porta %s' % server_address
sock.connect(server_address)

try:
    
    # Send data
    message = 'Scrivo qui il messaggio da rigirare.'
    print >>sys.stderr, 'invio "%s"' % message
    sock.sendall(message)

    # Look for the response
    amount_received = 0
    amount_expected = len(message)
    
    while amount_received < amount_expected:
        data = sock.recv(10)
        amount_received += len(data)
        print >>sys.stderr, 'ricevuto "%s"' % data

finally:
    print >>sys.stderr, 'chiudo il socket'
    sock.close()
