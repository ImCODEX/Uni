from Functions.Hotel import *
#from datetime import datetime




def recall(x):#returns the user on the main menu if x==1
    if x == 1:
        menu()
    else:
        return 0

#Menu Gaste
def a():
    print(
        '1. Füge ein neuer Gast hin\n2. Aktualisierung der Nachname eines Gastes\n3. Löschung eines Gastes\n4. Anzeige die Liste von Gästen\n0. Exit')
    N = int(input("Option:"))

    if N == 1:
        Funct.add_guest_input()
        print("Der Gast wurde hinzugefügt. Möchten Sie andere Operationen ausführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 2:
        Funct.change_guest_name_input()
        print("Der Name des Gastes wurde geändert. Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 3:
        Funct.del_guest_input()
        print("Der Gast wurde gelöscht. Möchten Sie andere Operationen ausführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 4:
        Funct.show_guests()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 0:
        recall(1)

    else:
        print("Ungultige Ziffer")
        a()

#Menu Zimmern
def b():
    print(
        '1. Füge ein Zimmer hin\n2. Aktualisierung des Preises eines Zimmers\n3. Löschung eines Zimmers\n4. Anzeige die Liste von Zimmern\n0. Exit')
    N = int(input("Option:"))

    if N == 1:
        Funct.add_room_input()
        print("Die Kamera wurde hinzugefügt. Möchten Sie andere Vorgänge ausführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 2:
        Funct.change_room_cost_input()
        print("Der Preis des Zimmers wurde geändert. Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 3:
        Funct.del_room_input()
        print("Das Zimmer war gelöscht, möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 4:
        Funct.show_rooms()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 0:
        recall(1)

    else:
        print("Ungultige Ziffer")
        b()

#Menu Gemeinsam
def c():
    print(
        '1. Mach eine Reservierung\n2. Anzeige die Liste von Gästen, die aktuelle Reservierungen haben\n3. Anzeige alle Zimmer gefiltert mit Preis und Meerblick Kriterien (z. B. ein Zimmer billiger als 100 Euro, mit Meerblick)\n4. Anzeige alle Zimmer, die heute frei sind\n 0. Exit')
    N = int(input("Option:"))

    if N == 1:
        Funct.make_reserv_input()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)


    elif N == 2:
        x = int(input(
            "Verwenden Sie das aktuelle Datum oder geben Sie es über die Tastatur ein? (0 - aktuell, 1 - eingegeben):"))
        if x == 1:
            data = datetime.strptime(str(input("Data DD-MM-YYYY: ")), '%d-%m-%Y')
            Funct.guest_today(data)
        else:
            Funct.guest_today()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 3:
        Funct.show_room_filter_input()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 4:
        x = int(input(
            "Verwenden Sie das aktuelle Datum oder geben Sie es über die Tastatur ein? (0 - aktuell, 1 - eingegeben):"))
        if x == 1:
            data = datetime.strptime(str(input("Data DD-MM-YYYY: ")), '%d-%m-%Y')
            Funct.free_today(data)
        else:
            Funct.free_today()
        print("Möchten Sie andere Operationen durchführen? (0 - nein, 1 - ja)")
        x = int(input())
        recall(x)

    elif N == 0:
        recall(1)
    else:
        print("Ungultige Ziffer")
        c()


def menu():
    print("1. Menu Gäste\n2. Menu Zimmern\n3. Menu Gemeinsam\n0. Exit")
    n = int(input("Option:"))
    if n == 1:
        a()
    elif n == 2:
        b()
    elif n == 3:
        c()
    elif n == 0:
        return
    else:
        print("Ungultige Ziffer")
        menu()
