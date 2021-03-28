from operatii.rational import *

def adaugare(l,x):
    l.append(x)
def stergere(l,x):
    while x in l:
        l.remove(x)
def suma(l):
    s = l[0]
    for i in range(1,len(l)):
      s = add (s,l[i])

    return simplify(s)
def secelem(l):
    max1 = l[0] ; max2 = l[0]
    for i in l:
        if cmp(i,max1) == 1:
            max2 = max1
            max1 = i
        elif cmp(i,max2) == 1:
            max2 = i
    return max2



