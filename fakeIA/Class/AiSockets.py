#!/usr/bin/python3

import socket

class   AiSockets:

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    def __init__(self, sock=None):
        if sock is None:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        else:
            self.sock = sock
        self.sock.settimeout(5)

    def connect(self, host, port):
        print (host)
        print (port)
        try:
            self.sock.connect((host, int(port)))
        except:
            print ("Can't connect server")
            exit(84)

    def send(self, msg):
        length = 0
        while length < len(msg):
            b = bytes(msg[length:], 'utf-8');
            lengthSend = self.sock.send(b)
            if lengthSend == 0:
                raise RuntimeError("AiSockets: Socket connection broken")
            length = length + lengthSend

    def receive(self, lengthReceive):
        byteReceive = 0
        msgAppend = ""
        try:
            while byteReceive < lengthReceive:
                msg = self.sock.recv(lengthReceive).decode()
                if msg == '':
                    raise RuntimeError("AiSockets: Socket connection broken")
                msgAppend += msg
                byteReceive = byteReceive + len(msg)
            return msgAppend
        except:
            return "";
            
    
