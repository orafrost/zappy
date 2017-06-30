#!/usr/bin/python2.7

import sys

# coucou j'ecris la doc en francais parce que fuck l'anglais
# Appeller la fonction pathFinder(...) avec :
# -entryTab (tableau de string formate comme convenu avec Francois txt[0] = "food food sibur"
# -level (niveau en int de l'ia)
# -ressource (la ressource a rechercher en string)
# Cette fonction retourne un double tableau contenant potentiellement :
# -soit "up" / "down" / "left" / "right"
# -soit "ko" dans le cas ou la ressource recherchee n'est pas presente
# -soit "" si l'ia se trouve sur la meme case que la ressource recherchee

def pathFinder(entryTab, ressource):
    resIsFound = False
    idx = -1

    for res in entryTab:
        tab = res.split()
        for littleRes in tab:
            if (littleRes == ressource):
                resIsFound = True
        idx += 1
        if (resIsFound):
            break
    if (resIsFound == False):
        return "ko"
    if (idx == 0):
        return ""
    toRet = []
    toRet.append("Forward\n")
    line = 1
    startLine = 1
    endLine = 3
    while (idx - endLine > 0):
        startLine += (1 + line * 2)
        line += 1
        endLine = startLine + (line * 2)
        toRet.append("Forward\n")
    mid = ((endLine - startLine) / 2) + 1
    col = mid
    if (mid + startLine - 1 == idx):
        return toRet
    elif (mid + startLine - 1 < idx):
        toRet.append("Right\n")
        toRet.append("Forward\n")
        col += 1
    else:
        toRet.append("Left\n")
        toRet.append("Forward\n")
        col -= 1
    while (col != (idx - startLine + 1)):
        toRet.append("Forward\n")
        if (mid + startLine - 1 < idx):
            col += 1
        else:
            col -= 1
    return toRet

#def main(av):
#    entryTab = ["food",
#                "toto", "linemate", "fifi",
#                "sibur", "", "plop", "mescouilles", "phiras"]
#    level = 2
#    ressource = "phiras"
#    print(pathFinder(entryTab, level, ressource))

#if __name__ == "__main__":
#    main(sys.argv)
