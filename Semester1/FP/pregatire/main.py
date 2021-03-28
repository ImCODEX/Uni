from Tisch import Tisch
from functools import reduce

def Methode(l):
    l1 = list(filter(lambda t : t.Farbe == "rot", l))
    print(l1)
    l2 = list(map(lambda t : Tisch(t.Farbe, t.Lange + 10), l1))
    l3 = sorted(l2, key=lambda t: t.Lange, reverse=True)

    print(l3)

def MethodeB(l): #[f(el) for el in l if ....]
    l1 = [t for t in l if t.Farbe == "rot"]
    '''
    l1 = []
    for t in l:
        if t.Farbe == "rot":
            l1.append(t)
    '''
    l2 = [Tisch(t.Farbe, t.Lange + 10) for t in l]
    '''
    l2 = []
    for t in l:
        l1.append(Tisch(t.Farbe, t.Lange + 10))
    '''
    l3 = sorted(l2, key=lambda t: t.Lange, reverse=True)

    print(l3)


def Methode1(l):
    l1 = list(filter(lambda t : t.Farbe == "rot", l))
    l2 = list(map(lambda t : Tisch(t.Farbe, t.Lange + 10), l1))
    l3 = sorted(l2, key=lambda t: t.Lange, reverse=True)
    l4 = reduce(lambda a, b: Tisch(a.Farbe, a.Lange + b.Lange) , l3)

    print(l4)

def main():
    l = [Tisch("blau",19), Tisch("rot",32), Tisch("rot",15), Tisch("lila",25), Tisch("geld",10)]
    Methode(l)
    #f = lambda x : x*2
    # def f(x):
    #    return x*2

    #print(f(2))
    l = [1, 2, 3, 4, 5] #3 3 4 5 6 4 5 10 5 15
    #print(reduce(lambda x, y: x+y, l))
    #print(reduce(lambda a, b: a if a > b else b, l))
    #print(reduce(lambda x, y: max(x,y), l))
main()
