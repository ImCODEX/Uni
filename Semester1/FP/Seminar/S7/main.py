from Entities.Punkt import Point
from Entities.Circle import Circle

def sort_circle(liste, cmp):
    for i in range(len(liste)):
        for j in range(len(liste)):
            if cmp(liste[i]) < cmp(liste[j]):
                liste[i] , liste[j] = liste[j] , liste[i]

def sort_circle2(liste):
    sorted(liste)

def main():
    '''A = Point(1, 0)
    B = Point(3, 1)

    C = A + B
    #print(C)

    Cerc1 = Circle(2, A)
    Cerc2 = Circle(4, B)

    #print(Cerc)'''
    lista = []
    for i in range(5):
        punkt = Point(i+1,i*5)
        cerc = Circle(i, punkt)
        lista.append(cerc)
    print(lista)
    sort_circle2(lista)

    #print(Cerc1*Cerc2)

main()