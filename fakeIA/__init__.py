#!/usr/bin/python3

import os, sys, re, time
from Class.AiSockets import *
from Class.AiMovement import *
from Class.PathFinder import *

def print_help():
        print ("USAGE: ./zappy_ai -p port -n name -h machine")
        print ("\tport\tis the port number")
        print ("\tname\tis the name of the team")
        print ("\tmachine\tis the name of the machine; localhost by default")
        exit (0)

def debug(string1, string2):
        print (string1, end='')
        print (string2)

def check_player(AI, num):
        look = AI.look()
        debug("check_player / look : ", look)
        debug("num player : ", look[0].count('player'))
        if (look == "ko"):
                return ("exit")
        if (num == look[0].count('player')):
                return ("ok")
        elif (num < look[0].count('player')):
                AI.eject("1")
        return ("ko")

        
def get_object(AI, command):
        x = 0
        print (command)
        while (x < len(command)):
                AI.takeObject(command[x])
                x += 1
        return ("ok")

def clean_floor(AI):
        tile = AI.look()
        if (tile != "ko" and len(tile) > 0):
                tile[0] = tile[0].replace('player ', '')
                command = tile[0].split(' ')
                return (get_object(AI, command))
        return ("ko")

def check_ressource_for_up(AI, obj, inv):
        x = 0
        while (x < len(inv)):
                if (inv[x].find(obj) != -1):
                        try:
                                a = get_num(inv, obj)
                                if (a < AI.need[obj]):
                                        return ("ok")
                                else:
                                        break
                        except KeyError:
                                return ("ko")
                x += 1
        return ("ko")

def take_ressource(AI, liste, ressource):
        obj = liste.split(' ')
        x = 0
        inv = AI.inventory()
        if (inv == "ko"):
                return ("ko")
        inv = inv.replace('[ ', '')
        inv = inv.replace(' ]', '')
        inv = inv.split(', ')
        want = "ko"
        msg = "ko"
        while (x < len(obj)):
                if (obj[x] == "food"):
                        msg = AI.takeObject(obj[x])
                elif (check_ressource_for_up(AI, obj[x], inv) == "ok"):
                        msg = AI.takeObject(obj[x])
                if (want == "ko" and msg == "ok" and obj[x] == ressource):
                        want = "ok"
                x += 1
        return (want)

def get_ressource(AI, ressource):
        look = AI.look()
        if (look != "ko"):
                path = pathFinder(look, ressource)
                debug("Path : ", path)
                if (path == "ko"):
                        return ("ko")
                x = 0
                cnt = 0
                puissance = 0
                add = 0
                msg = "ko"
                if (look[cnt] != ""):
                        res = take_ressource(AI, look[cnt], ressource)
                if (res == "ok" and look[cnt] == ressource):
                        msg = "ok"
                while (x < len(path)):
                        if (path[x] == "Forward\n"):
                                puissance += 1
                                AI.forward()
                        elif (path[x] == "Right\n"):
                                add = 1
                                AI.right()
                        elif (path[x] == "Left\n"):
                                add = -1
                                AI.left()
                        if (add == 0):
                                cnt = pow(cnt, puissance)
                        else:
                                cnt += add
                        if (path[x] == "Forward\n"):
                                res = take_ressource(AI, look[cnt], ressource)
                                if (res == "ok" and look[cnt] == ressource):
                                        msg = "ok"
                        x += 1
                return (msg)
        return ("ko")

def get_num(stock, ressource):
        y = 0
        while (y < len(stock)):
                if (stock[y].count(ressource) > 0):
                        string = stock[y]
                        stack = ""
                        x = 0
                        ind = 0
                        while (x < len(string)):
                                if (string[x] >= '0' and string[x] <= '9'):
                                        stack += string[x]
                                        ind += 1
                                x += 1
                        if (stack != ""):
                                return (int(stack))
                        else:
                                return (0)
                y += 1
        return (0)

def check_ressource(AI, ressource):
        stock = AI.inventory()
        if (stock == "ko"):
                return ("ko")
        stock = stock.split(',')
        x = 0
        cnt = 0
        debug("check_ressource : ", stock)
        while (x < len(ressource)):
                debug("resource : ", ressource)
                debug("need ressource : ", AI.need[ressource[x]])
                if (get_num(stock, ressource[x]) < AI.need[ressource[x]]):
                        rot = 0
                        while (rot < 3):
                                if (get_ressource(AI, ressource[x]) == "ok"):
                                        cnt += 1
                                        break
                                AI.left()                                
                                rot += 1
                        if (rot == 3):
                                AI.forward()
                                AI.forward()
                                AI.forward()
                else:
                        cnt += 1
                x += 1
        debug("cnt : ", cnt)
        if (cnt == len(ressource)):
                return ("ok")
        return ("ko")

def check_min_food(AI, minimum):
        stock = AI.inventory()
        if (stock == "ko"):
                return ("ko")
        stock = stock.split(',')
        if (get_num(stock, "food") > minimum):
                return ("ok")
        return ("ko")

def get_food(AI, need):
        stock = AI.inventory()
        if (stock == "ko"):
                return ("ko")
        stock = stock.split(',')
        while (get_num(stock, "food") < need):
                AI.listenBroadcast()
                debug("inventaire : ", stock)
                debug("get food / Nb food : ", get_num(stock, "food"))
                get_ressource(AI, "food")
                stock = AI.inventory()
                if (stock == "ko"):
                        return ("ko")
                stock = stock.split(',')
        return ("ok")
                
def broadCast(AI, lvl):
        i = 0
        chaine = "level"
        chaine += str(lvl)
#        AI.listenBroadcast()
        while (i < 100):
#                AI.listenBroadcast()                
#                debug("broadcast : ", AI.broadcastText(chaine + i))
#                time.sleep(0.2)
                AI.broadcastText(chaine)
                msg = check_player(AI, 2)
                if (msg == "ok"):
                        return (0)
                if (msg == "exit"):
                        return (2)
                i += 1
        print ("MEME position")
        return (lvl)

def track_level_1(AI):
        search = []
        search.append("linemate")
        print(search)
        if (check_ressource(AI, search) == "ok"):
                clean_floor(AI)
                AI.setObject("linemate")
                debug("Inventory : ", AI.inventory())
                if (AI.incantation() == "ok"):
                        print ("UUUUP lvl 1")
                        return (2)
                AI.takeObject("linemate")
        return (1)

def track_level_2(AI):
        search = []
        search.append("linemate")
        search.append("deraumere")
        search.append("sibur")
        AI.listenBroadcast()
        if (check_ressource(AI, search) == "ok"):
                AI.listenBroadcast()
                if (check_min_food(AI, 20) == "ko"):
                        return (get_food(AI, 40))
                AI.listenBroadcast()
                if (broadCast(AI, 2) == 2):
                        return (2)
                clean_floor(AI)
                AI.setObject("linemate")
                AI.setObject("deraumere")
                AI.setObject("sibur")
                if (AI.incantation() == ("ok")):
                        print ("UP lvl 3")
                        print (AI.look())
                        return (3)
                AI.takeObject("linemate")
                AI.takeObject("deraumere")
                AI.takeObject("sibur")
        return (2)

def check_level(AI):
        if (AI.lvl == 1):
                track_level_1(AI)
        elif (AI.lvl == 2):
                track_level_2(AI)
        else:
                print("Bravo")
                exit(0)

def main(av):
        if len(av) == 2:
                if av[1] == "-help":
                        print_help()
        if len(av) < 3:
                exit (84)
        AI = AiMovement(av[2]);
        if len(av) < 4:
                AI.connect("localhost", av[1])
        else:
                AI.connect(av[3], av[1])
        #TODO : Connect to the graphical client; Call self.update() who take data from server for graphical client and push it to the client_graphical.
        i = 0
        while (i < 40):
                check_level(AI)
                i += 1
        print (AI.inventory())
        #TODO: Call self.update()

if __name__ == "__main__":
    main(sys.argv)
