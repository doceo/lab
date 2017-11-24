#script liberamente tratto da https://pymotw.com/2/socket/tcp.html


import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('192.168.1.96', 6789)
print >>sys.stderr, 'connesso a %s porta %s' % server_address
sock.connect(server_address)

try:
    
    # Send data
    message = 'la scuola e\' bella'
    print >>sys.stderr, 'ricevo "%s"' % message
    sock.sendall(message)

    # Look for the response
    amount_received = 0
    amount_expected = len(message)
    
    while amount_received < amount_expected:
        data = sock.recv(6789)
        amount_received += len(data)
        print >>sys.stderr, ' "%s"' % data

finally:
    print >>sys.stderr, 'chiudo il socket'
    sock.close()
