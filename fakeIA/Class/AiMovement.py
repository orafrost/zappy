#!/usr/bin/python3

import time
from Class.AiSockets import *

dicto = [{"player":1, "linemate":1},
         {"player":2, "linemate":1, "deraumere":1, "sibur":1},
         {"player":2, "linemate":2, "sibur":1, "phiras":2},
         {"player":4, "linemate":1, "deraumere":1, "sibur":2, "phiras":1},
         {"player":4, "linemate":1, "deraumere":2, "sibur":1, "mendiane":3},
         {"player":6, "linemate":1, "deraumere":2, "sibur":3, "phiras":1},
         {"player":6, "linemate":2, "deraumere":2, "sibur":2, "mendiane":2, "phiras":2, "thystame":1}]

class   AiMovement:
    aiSockets = AiSockets()
    aiSocketsGraph = AiSockets()
    nbOfMyTeam = 0
    nameOfMyTeam = ""
    tileMap = [[]]
    width = 0
    height = 0
    lvl = 1
    need = dicto[0]
    stack = []
    
    def __init__(self, nameOfMyTeam, aiSockets=None):
        if aiSockets is None:
            self.aiSockets = AiSockets()
        else:
            self.aiSockets = aiSockets
        self.nameOfMyTeam = nameOfMyTeam

    def flushSocket(self):
        try:
            msg = ""
            ret = self.aiSockets.receive(1)
            while ret != '\n' and ret != "":
                msg += ret
                ret = str(self.aiSockets.receive(1))
        except RuntimeError:
            exit(84)
        print (msg)
        return (msg)

    def buffReceive(self):
        msg = self.flushSocket()
        if (msg == ""):
            return ("ko")
        ret = msg.replace(',', '')
        ret = msg.split(" ")
        if msg == "dead":
            exit (0)
        if (msg == "Elevation underway"):
            self.lvl += 1
            self.need = dicto[self.lvl - 1]
            if (self.lvl == 3):
                print ("up lvl 3")
                print (self.look())
                time.sleep(5)
            self.flushSocket()
        if ret[0] == "message":
            chaine = "level"
            chaine += str(self.lvl)
#            print (chaine)
            if (ret[2] == chaine):
                if (ret[1] == "0"):
                    time.sleep(3)
                self.stack.append(msg)
                msg = self.buffReceive()
                #                print (ret)
#                ret[1] = ret[1].replace(',', '')
#                self.flushSocketBroadcast()
#                msg = self.listenBroadcast(chaine, ret)

            else:
                if (ret[2] == "stop"):
                    time.sleep(3)
                msg = self.buffReceive()
        return (msg)

    def connectGraphic(self, host, port):
        self.aiSocketsGraph.connect(host, port)

    def update(self):
        msgToSend = "msz\nmct\npnw\npdi\nenw\neht\npla\n"
        self.aiSockets.send(msgToSend)
        msgToSend = self.buffReceive()
        self.aiSocketsGraph.send(msgToSend)

        
    def connect(self, host, port):
        self.aiSockets.connect(host, port)
        msg = self.buffReceive()
        self.aiSockets.send(self.nameOfMyTeam + "\n")
        myTeam = self.buffReceive()
        try:
            print (myTeam)
            self.nbOfMyTeam = int(myTeam)
            w, h = self.buffReceive().split(" ")
            self.width = int(w)
            self.height = int(h)
            self.tileMap = [[0 for x in range(self.width)] for y in range(self.height)]
        except ValueError:
            exit(84)
        

    def forward(self):
        self.aiSockets.send("Forward\n")
        msg = self.buffReceive()
        if msg == ("ok"):
            return ("ok")
        return ("ko")

    def right(self):
        self.aiSockets.send("Right\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")
            
    def left(self):
        self.aiSockets.send("Left\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")

    def look(self):
        self.aiSockets.send("Look\n")
        msg = self.buffReceive()
        if msg != "" and msg != "ko" and len(msg) > 0 and msg[0] == '[':
            try:
                msg = msg.split(', ')
            except:
                return ("ko")
            x = 0
            while (x < len(msg)):
                msg[x] = msg[x].replace('[ ', '')
                msg[x] = msg[x].replace(' ]', '')
                x += 1
            return (msg)
        return ("ko")

    def inventory(self):
        self.aiSockets.send("Inventory\n")
        msg = self.buffReceive()
        if msg != "" and msg[0] == '[':
            return msg
        return ("ko")

    def broadcastText(self, toSend):
        self.aiSockets.send("Broadcast " + toSend + "\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")

    def my_fork(self):
        self.aiSockets.send("Fork\n")
        msg = self.buffReceive()
        if (msg == "ok"):
            return ("ok")
        return ("ko")

    def connect_nbr(self):
        self.aiSockets.send("Connect_nbr\n")
        return int(self.buffReceive())

    def eject(self, direction):
        self.aiSockets.send("eject: " + direction + "\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")

    def takeObject(self, obj):
        self.aiSockets.send("Take " + obj + "\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")

    def setObject(self, obj):
        self.aiSockets.send("Set " + obj + "\n")
        msg = self.buffReceive()
        if msg == "ok":
            return ("ok")
        return ("ko")
            
    def incantation(self):
        self.aiSockets.send("Incantation\n")
        msg = self.buffReceive()
        print ("INCANTATION : ", end='')
        print (msg)
        if msg == "Elevation underway":
            return ("ok")
        print (msg)
        msg = self.flushSocket()
        print (msg)
        time.sleep(5)
        return ("ko")

    def BroadcastReceive(self):
        try:
            msg = ""
            ret = self.aiSockets.receive(1)
            while ret != '\n' and ret != "":
                msg += ret
                ret = str(self.aiSockets.receive(1))
        except RuntimeError:
            return ("ko")
        msg = msg.replace(',', '')
        msg = msg.split(" ")
        if (msg[0] == "message"):
            return (msg)
        return ("ko")
        
        
    def listenBroadcast(self):
        x = len(self.stack)
        if (x == 0):
            return ("ko")
        x -= 1
        chaine = "level"
        chaine += str(self.lvl)
        listen = self.stack[x]
        listen = listen.replace(',', '')
        listen = listen.split(' ')
        while (x > 0):
            listen = self.stack[x]
            listen = listen.replace(',', '')
            listen = listen.split(' ')
            if (listen[0] == "Elevation"):
                self.lvl += 1
                self.need = dicto[self.lvl - 1]
            if (chaine == listen[1]):
                break
            x -= 1
        run = listen[0]
        self.stack[:] = []
        while (run != "ko"):
            print ("Message reçu : ", end='')
            print (listen)
            if (listen[1] == "1"):
                print ("1bis")
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("1")
            elif (listen[1] == "2"):
                print ("2bis")
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                self.aiSockets.send("Left\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                print ("2")
            elif (listen[1] == "3"):
                print ("3bis")
                self.aiSockets.send("Left\n")
                self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("3")
            elif (listen[1] == "4"):
                print ("4bis")
                self.aiSockets.send("Left\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                self.flushSocket()
                self.aiSockets.send("Left\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("4")
            elif (listen[1] == "5"):
                print ("5bis")
                self.aiSockets.send("Left\n")
                msg = self.flushSocket()
                self.aiSockets.send("Left\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("5")
            elif (listen[1] == "6"):
                print ("6bis")
                self.aiSockets.send("Right\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                self.aiSockets.send("Right\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("6")
            elif (listen[1] == "7"):
                print ("7bis")
                self.aiSockets.send("Right\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("7")
            elif (listen[1] == "8"):
                print ("8bis")
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                self.aiSockets.send("Right\n")
                msg = self.flushSocket()
                self.aiSockets.send("Forward\n")
                msg = self.flushSocket()
                print ("8")
            elif (listen[1] == "0"):
                time.sleep(2)
                return ("ko")
            time.sleep(0.2)
            run = self.BroadcastReceive()
            listen = run
        return ("ko")
