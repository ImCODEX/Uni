/*
Losung zu Aufgabe 8
a) ->  bestimmt den Wert x ^ n, x, n - von den Tastatur
b) -> bestimmt die längste aufeinanderfolgende Teilfolge
wobei jede zwei aufeinanderfolgende Elemente entgegengesetzte 
Vorzeichen haben von einen eingegebenen array
*/
#include <iostream>
using std::cin;
using std::cout;

//diese Funktion berechnet x^n
// x, n - int, gegeben als paramter

int power(int x, unsigned int n)
{
    int i = 1, created_xn = 1;
    while (i <= n)
    {
        created_xn = created_xn * x;
        i++;
    }
    return created_xn;
}

//Funktion zum einfachere Lesen und Schreiben uber die Konsole
//Die Funktion verwendet die Funktion a
void a_input()
{
    int x, n;
    cout << "x=";
    cin >> x;
    cout << "n=";
    cin >> n;
    cout << "x^n= " << power(x, n);
}

//Die Funktion berechnet den Teilstring mit maximaler Länge mit der Eigenschaft, dass
//jede zwei aufeinanderfolgende Elemente entgegengesetzte Vorzeichen haben
//start_index ist als parameter weil wir es in der Hauptfunktion brauchen
void b(int *v, int &n, int &start_index)
{
    int i, j = 0, lenl = 0, leng = 0, subarray_s = 0, subarray_e = 0;
    for (i = 0; i <= n; i++)
    { //2 Elemente haben entgegengesetzte Vorzeichen wenn das Produkt kleiner als Null ist
        if (v[i] * v[i + 1] > 0 || v[i] == 0 && v[i + 1] > 0 || v[i + 1] == 0 && v[i] > 0)
        {
            if (lenl > leng)
            {
                leng = lenl;
                subarray_e = subarray_s;
            }
            lenl = 0;
            subarray_s = i + 1;
        }
        else if (v[i] * v[i + 1] < 0 || v[i] == 0 && v[i + 1] < 0 || v[i + 1] == 0 && v[i] < 0)
            lenl++;
    }
    //wir uberschreiben die Parametern
    start_index = subarray_e;
    n = leng;
}

//Die Funktion druckt ein Array mit einer Länge und einem benutzerdefinierten Startpunkt
void b_output(int *v, int start_index, int length)
{

    for (int i = start_index; i <= start_index + length; i++)
        cout << v[i] << " ";
}

int main()
{   //a)
    a_input();

    //b)
    int v[10] = {1, 0, -3, 4, -5, 6, 9, 10, -4, -2};
    int length = sizeof(v) / sizeof(v[0]), start_index = 0;
    b(v, length, start_index);
    b_output(v, start_index, length);
    return 0;
}