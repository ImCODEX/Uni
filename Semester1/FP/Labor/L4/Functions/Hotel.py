from datetime import datetime
from Entities.Guest import Gaste
from Entities.Room import Room
from Entities.Reservation import Reserv


class Hotel:
    def __init__(self):
        self.__index_reserv = 5
        self.__guests = []
        self.__rooms = []
        self.__reservs = []

    @property
    def guests(self):
        return self.__guests

    @property
    def rooms(self):
        return self.__rooms

    @property
    def reservs(self):
        return self.__reservs

    @property
    def index_reserv(self):
        return self.__index_reserv

    @index_reserv.setter
    def index_reserv(self, other):
        self.__index_reserv = other

    '''def read_guest(self):#console read for guests
        Nume = str(input("Name: "))
        Prenume = str(input("Vorname:"))
        g = Gaste(Nume, Prenume, [])
        return g

    def read_room(self):#console read for rooms
        nr = int(input("Zimmern number: "))
        maxguest = int(input("Maximal Anzahl der Gaste: "))
        price = int(input("Zimmern Preis: "))
        color = str(input("Zimmern Farbe: "))
        sea_view = int(input("Hat der Zimmern einen Meerblick (0 - Nein; 1 - Ya): "))
        z = Room(nr, maxguest, price, color, sea_view)
        return z

    def read_reserv(self):#console read for reservations
        nrguests = int(input("Anzahl der Gäste: "))
        guests = []

        for i in range(0, nrguests):
            self.show_guests()
            print("Wahlen noch ", nrguests - i, " Gueste\n")
            x = int(input("ID Guest:\n"))
            guests.append(self.__guests[x])

        self.show_rooms()
        room = int(input("Zimmernummer: "))
        room = self.room_by_number(room)

        datestart = str(input("Datum Kommen DD-MM-YYYY: "))
        datestart = datetime.strptime(datestart, '%d-%m-%Y')

        datefin = str(input("Datum Abfahrt DD-MM-YYYY: "))
        datefin = datetime.strptime(datefin, '%d-%m-%Y')

        r = Reserv(self.__index_reserv, guests, room, datestart, datefin)
        return r
'''
    def show_guests(self):#prints all the guests in console
        l = []
        i = 0
        for g in self.__guests:
            l.append("Id: "+str(i)+" "+str(g))
            i += 1
        return l

    def add_guest(self, g):#adds a guest to the guests list
        self.__guests.append(g)
        self.show_guests()

    def add_room(self, r):#adds a room to the rooms list
        self.__rooms.append(r)
        self.show_rooms()

    def add_reservs(self, r):#adds a reservation to the reservs list
        self.__reservs.append(r)

    def del_guest(self, i):#removes a guest (based on ID/place in list)
        self.__guests.pop(i)

    def change_room_cost(self, i, val):#changes the cost of a room(i)
        i.price = val
        self.show_rooms()

    def del_room(self, i):#removes a room based on the object itself
        self.__rooms.remove(i)
        self.show_rooms()

    def show_rooms(self):#prints all the rooms in console
        l = []
        for r in self.__rooms:
            if r.sea_view==1:
                l.append("ID:"+str(r.nr)+" MaxGaste:"+str(r.maxguest)+" Preis:"+str(r.price)+" Color:"+r.color+ " Meerblick")
            else:
                l.append("ID:"+str(r.nr)+" MaxGaste:"+str(r.maxguest)+" Preis:"+str(r.price)+" Color:"+r.color+ " Keine Meerblick")
        #print(str(l))
        return l

    def show_reserv_guests(self):#prints all the guests that have at least one reservation
        for g in self.__guests:
            if g.reserv != []:
                print(g)

    def show_reservs(self):#prints all the reservations in console
        l = []
        for r in self.__reservs:
            l.append(str(r))
            l.append("")

        print(str(l))
        return l

    def show_room_filter(self, price1, price2, sea_view):#filters rooms based on min_cost,max_cost and view
        l = []
        for r in self.__rooms:
            if (r.price < price2 or price2 == 0) and r.price > price1 and (r.sea_view == sea_view or sea_view == 2):

                if r.sea_view == 1:
                    l.append("ID:" + str(r.nr) + " MaxGaste:" + str(r.maxguest) + " Preis:" + str(
                        r.price) + " Color:" + r.color + " Meerblick")
                else:
                    l.append("ID:" + str(r.nr) + " MaxGaste:" + str(r.maxguest) + " Preis:" + str(
                        r.price) + " Color:" + r.color + " Keine Meerblick")
        return l

    def make_reserv_existing(self, r):  # creates a reservation based on a reserv object
        ok = 1
        if (r.datefin < r.datestart):
            ok = 0

        if r.room.maxguest < len(r.guests):
            ok = 0

        for reservc in self.__reservs:
            if reservc.room == r.room:

                if r.datestart > reservc.datestart and r.datestart < reservc.datefin or r.datefin > reservc.datestart and r.datefin < reservc.datefin or r.datefin >= reservc.datefin and r.datestart <= reservc.datefin:
                    ok = 0
        if ok == 1:
            self.__index_reserv += 1
            self.add_reservs(r)
        else:
            print("Reservierung nicht möglich")

    def make_reserv(self, r):#creates a reservation based on a reserv object
        ok = 1
        if (r.datefin < r.datestart):
            ok = 0

        if r.room.maxguest < len(r.guests):
            ok = 0

        for reservc in self.__reservs:
            if reservc.room == r.room:

                if r.datestart > reservc.datestart and r.datestart < reservc.datefin or r.datefin > reservc.datestart and r.datefin < reservc.datefin or r.datefin >= reservc.datefin and r.datestart <= reservc.datefin:
                    ok = 0
        if ok == 1:
            self.__index_reserv += 1
            self.add_reservs(r)
            for g in r.guests:
                g.add_reserv(r)
        else:
            print("Reservierung nicht möglich")

    def room_by_number(self, x):#uses the room number(ID) to return the object
        for i in self.__rooms:
            if i.nr == x:
                return i

    def add_guest_input(self):#console read for guests
        self.add_guest(self.read_guest())
        self.show_guests()
    '''
    def change_guest_name_input(self):#console read for changing guests name, also shows the list for easier access
        self.show_guests()
        i = int(input("ID Gast: "))
        gast = self.read_guest()
        self.__guests[i].set_nachname = gast.nachname
        self.__guests[i].set_vorname = gast.vorname
        self.show_guests()

    def del_guest_input(self):#deletes a guest based on ID from console input, also shows the list for easier access
        self.show_guests()
        i = int(input("ID Gast: "))
        self.del_guest(i)
        self.show_guests()

    def add_room_input(self):#console read for rooms
        self.add_room(self.read_room())
        self.show_rooms()

    def change_room_cost_input(self):#console read for rooms change_cost
        self.show_rooms()
        i = int(input("Zimmernummer, deren Preis Sie ändern möchten: "))
        val = int(input("Preis: "))
        self.change_room_cost(self.room_by_number(i), val)
        self.show_rooms()

    def del_room_input(self):#deletes a room based on nr(ID) from console input, also shows the list for easier access
        self.show_rooms()
        i = int(input("Zimmernnummer: "))
        self.del_room(self.room_by_number(i))
        self.show_rooms()

    def make_reserv_input(self):#console read for reservs
        self.make_reserv(self.read_reserv())
        self.show_reservs()

    def show_room_filter_input(self):#console read for showing rooms based on filters
        x1 = int(input("Minimum Preis: "))
        x2 = int(input("Maximum Preis (0 - kein maximal preis): "))
        y = int(input("Hat meerblick oder nicht (0 - nein; 1 - ja; 2 - gleichgultig): "))
        self.show_room_filter(x1, x2, y)
'''
    def free_today(self, today=datetime.now()):#prints all of the rooms that are free "today"(adjustable date, implicit based on system clock)
        l = []
        for r in self.__rooms:
            ok = 1
            for reserv in self.__reservs:
                if reserv.room == r:
                    if (reserv.datestart <= today and reserv.datefin >= today):
                        ok = 0
            if ok == 1:

                if r.sea_view == 1:
                    l.append("ID:" + str(r.nr) + " MaxGaste:" + str(r.maxguest) + " Preis:" + str(
                        r.price) + " Color:" + r.color + " Meerblick")
                else:
                    l.append("ID:" + str(r.nr) + " MaxGaste:" + str(r.maxguest) + " Preis:" + str(
                        r.price) + " Color:" + r.color + " Keine Meerblick")
        return l

    def guest_today(self, today=datetime.now()):  # prints all of the guests that are free "today"(adjustable date, implicit based on system clock)
        l = []
        for g in self.__guests:
            ok = 1
            for reserv in g.reserv:
                if (reserv.datestart <= today and reserv.datefin >= today):
                    ok = 0
            if ok == 0:
                l.append(str(g))
        return l

    def guest_by_name(self,nachname,vorname):
        for g in self.__guests:
            if(g.nachname==nachname and g.vorname==vorname):
                return g

    def reserv_by_id(self,v):
        for r in self.__reservs:
            if r.nr==v:
                return r