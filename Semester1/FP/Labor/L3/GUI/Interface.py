from datetime import datetime
from tkinter import *
from tkinter import messagebox
from Functions.Hotel import *
from Entities.Guest import *
from GUI.Windows import *
from tkinter.filedialog import askopenfilename
'''
Funct = Hotel()
guest1 = Gaste("Bob", "Derryl", [])
guest2 = Gaste("Emil", "Dorel", [])
Funct.add_guest(guest1)
Funct.add_guest(guest2)
room1 = Room(1, 3, 200, "Rot", 0)
room2 = Room(2, 2, 150, "Grun", 1)
Funct.add_room(room1)
Funct.add_room(room2)
reserv1 = Reserv(1, [guest1, guest2], room1, datetime(2020, 11, 21), datetime(2020, 11, 24))
Funct.make_reserv(reserv1)
'''

class GUI:
    def __init__(self, gui_master, controller):
        self.__window = gui_master
        self.__controller = controller
        self.__roommenu = Frame(master=self.__window, borderwidth=45)
        self.__guestmenu = Frame(master=self.__window, borderwidth=45)
        self.__reservmenu = Frame(master=self.__window, borderwidth=45)
        self.__mainmenu = Frame(master=self.__window, borderwidth=45)
        self.meerblickvar = 0
        self.populate_roommenu()
        self.populate_mainmenu()
        self.populate_guestmenu()
        self.populate_reservmenu()

    def pick_out_file(self):
        return askopenfilename(initialdir=r"C:\Users\razva\OneDrive\Documents\UBBIG\FP\L3_redone",
                               title="Select the output file", filetype=
                               (("Text files", "*.txt"),
                                ("All files",
                                 "*.*")))  # show an "Open" dialog box and return the path to the selected file

    def saveToFile(self, Funct, Filename):
        '''gaste_file = open("Gaste_File.txt", 'w')
        room_file = open("Room_File.txt", 'w')
        reserv_file = open("Reserv_File.txt", 'w')'''
        all_file = open(Filename, 'w')
        for el in Funct.rooms:
            all_file.write(str(el) + '\n')

        all_file.write('-' + '\n')
        for el in Funct.guests:
            all_file.write(str(el) + '\n')

        all_file.write('-' + '\n')
        for el in Funct.reservs:
            all_file.write(str(el) + '\n')

    def show_guests_reserv_today(self):
        l = self.__controller.guest_today()
        l = "\n".join(l)
        messagebox.showinfo("Gueste Heute", l)

    def show_rooms_free_today(self):
        l = self.__controller.free_today()
        l = "\n".join(l)
        messagebox.showinfo("Zimmern Frei Heute", l)

    def check_button_pressed(self):
        if self.meerblickvar == 0:
            self.meerblickvar = 1
        else:
            self.meerblickvar = 0

    def sort_room_filter(self, preismin, preismax, meerblick):
        print("mer: ", meerblick)
        l = self.__controller.show_room_filter(preismin, preismax, meerblick)
        l = "\n".join(l)
        messagebox.showinfo("Zimmern Gefiltert", l)

    def read_reserv(self, guests, room, datestart, datefin):
        datestart = datetime.strptime(datestart, '%d-%m-%Y')
        datefin = datetime.strptime(datefin, '%d-%m-%Y')
        guests = guests.split(",")
        guests = [int(item) for item in guests]
        guests = [self.__controller.guests[item] for item in guests]
        room = self.__controller.room_by_number(int(room))
        reserv = Reserv(self.__controller.index_reserv + 1, guests, room, datestart, datefin)
        self.__controller.make_reserv(reserv)

    def add_guest(self, nachname, vorname):
        guest = Gaste(nachname, vorname, [])
        self.__controller.add_guest(guest)

    def change_guest_name(self, id, nachname, vorname):
        l = self.__controller._Hotel__guests[int(id)]
        l.nachname = nachname
        l.vorname = vorname

    def del_guest(self, id):
        self.__controller.del_guest(int(id))

    def add_room(self, nr, maxguest, price, color, sea_view):
        room = Room(int(nr), int(maxguest), int(price), color, int(sea_view))
        self.__controller.add_room(room)

    def change_room_cost(self, i, price):
        room = self.__controller.room_by_number(int(i))
        self.__controller.change_room_cost(room, int(price))

    def del_room(self, i):
        room = self.__controller.room_by_number(int(i))
        self.__controller.del_room(room)

    def show_rooms(self):
        l = self.__controller.show_rooms()
        l = "\n".join(l)
        messagebox.showinfo("Zimmern Liste", l)

    def show_guests(self):
        l = self.__controller.show_guests()
        l = "\n".join(l)
        messagebox.showinfo("Gueste Liste", l)
        '''
        self.second_window = Toplevel(self.__window)
        self.second = NewWindow(self.second_window, self.__controller)
        '''

    def show_reservs(self):
        l = self.__controller.show_reservs()
        l = "\n".join(l)
        messagebox.showinfo("Reservierungen Liste", l)

    def populate_mainmenu(self):

        btn = Button(self.__mainmenu, text='Roommenu', command=self.draw_roommenu)
        btn.grid(column=0, row=0)

        btn2 = Button(self.__mainmenu, text='Guestmenu', command=self.draw_guestmenu)
        btn2.grid(column=1, row=0)

        btn3 = Button(self.__mainmenu, text='Reservmenu', command=self.draw_reservmenu)
        btn3.grid(column=2, row=0)

        btn4 = Button(self.__mainmenu, text='Exit', command=self.__window.destroy)
        btn4.grid(column=3, row=0)

        btn4 = Button(self.__mainmenu, text='Save', command= lambda: self.saveToFile(self.__controller, self.pick_out_file()))
        btn4.grid(column=3, row=5)

    def populate_roommenu(self):
        string1_txt = Entry(self.__roommenu, width=50)
        string2_txt = Entry(self.__roommenu, width=50)
        string3_txt = Entry(self.__roommenu, width=50)
        string4_txt = Entry(self.__roommenu, width=50)
        string5_txt = Entry(self.__roommenu, width=50)

        btn1 = Button(self.__roommenu, text='Füge ein Zimmer hin', command=lambda: self.add_room(string1_txt.get(), string2_txt.get(), string3_txt.get(), string4_txt.get(), string5_txt.get()))
        btn1.grid(column=0, row=0)

        btn2 = Button(self.__roommenu, text='Aktualisierung des Preises eines Zimmers', command=lambda: self.change_room_cost(string1_txt.get(),string3_txt.get()))
        btn2.grid(column=1, row=0)

        btn3 = Button(self.__roommenu, text='Löschung eines Zimmers', command=lambda: self.del_room(string1_txt.get()))
        btn3.grid(column=2, row=0)

        btn4 = Button(self.__roommenu, text='Anzeige die Liste von Zimmern', command=self.show_rooms)
        btn4.grid(column=3, row=0)

        btn5 = Button(self.__roommenu, text='Go to main menu', command=self.draw_menu_again_roommenu)
        btn5.grid(column=4, row=0)

        nr = Label(self.__roommenu, text='nr')
        nr.grid(column=0, row=2)
        string1_txt.grid(column=1, row=2)

        maxguest = Label(self.__roommenu, text='maxguest')
        maxguest.grid(column=0, row=3)
        string2_txt.grid(column=1, row=3)

        price = Label(self.__roommenu, text='price')
        price.grid(column=0, row=4)
        string3_txt.grid(column=1, row=4)

        color = Label(self.__roommenu, text='color')
        color.grid(column=0, row=5)
        string4_txt.grid(column=1, row=5)

        sea_view = Label(self.__roommenu, text='sea_view')
        sea_view.grid(column=0, row=6)
        string5_txt.grid(column=1, row=6)

        btn5 = Button(self.__roommenu, text='HELP', command=lambda: messagebox.showinfo("help roommenu", "ROOMMENU HELP:\n\"Füge ein Zimmer hin\":\n- Taste, um eine neue Kamera hinzufügen\n- Füllen Sie jedes Feld \"Zimmernumer\", \"Max Gueste\", \"Preis\", \"Farbe\", \"Meerblick\" (füllen Sie 0 oder 1 aus) aus\n\n\"Aktualisierung des Preises eines Zimmers\"\n- Taste, um den Preis eines bestimmten Raum zu aktualisieren\n- nur die Felder \"Zimmernumer\" und \"Preis\" ausfüllen\n\n\"Löschung eines Zimmers\":\n- Taste zum Löschen einer bestimmten Kamera\n- Füllen Sie einfach das Feld \"Zimmernumer\" aus\n\n\"Anzeige die Liste von Zimmern\":\n- Taste, um die Liste der Räume anzuzeigen\n"))
        btn5.grid(column=4, row=7)



    def draw_roommenu(self):
        self.__mainmenu.pack_forget()
        self.__roommenu.pack(fill=X)


    def populate_guestmenu(self):
        string1_txt = Entry(self.__guestmenu, width=50)
        string2_txt = Entry(self.__guestmenu, width=50)
        string3_txt = Entry(self.__guestmenu, width=50)

        btn1 = Button(self.__guestmenu, text='Füge ein neuer Gast hin', command=lambda: self.add_guest(string1_txt.get(), string2_txt.get()))
        btn1.grid(column=0, row=0)

        btn2 = Button(self.__guestmenu, text='Aktualisierung der Name eines Gastes', command=lambda: self.change_guest_name(string3_txt.get(), string1_txt.get(), string2_txt.get()))
        btn2.grid(column=1, row=0)

        btn3 = Button(self.__guestmenu, text='Löschung eines Gastes', command=lambda: self.del_guest(string3_txt.get()))
        btn3.grid(column=2, row=0)

        btn4 = Button(self.__guestmenu, text='Anzeige die Liste von Gästen', command=self.show_guests)
        btn4.grid(column=3, row=0)

        btn0 = Button(self.__guestmenu, text='Main Menu', command=self.draw_menu_again_guestmenu)
        btn0.grid(column=4, row=0)

        nachname = Label(self.__guestmenu, text='nachname')
        nachname.grid(column=0, row=2)
        string1_txt.grid(column=1, row=2)

        vorname = Label(self.__guestmenu, text='vorname')
        vorname.grid(column=0, row=3)
        string2_txt.grid(column=1, row=3)

        id = Label(self.__guestmenu, text='id')
        id.grid(column=0, row=4)
        string3_txt.grid(column=1, row=4)

    def draw_guestmenu(self):
        self.__mainmenu.pack_forget()
        self.__guestmenu.pack(fill=X)


    def populate_reservmenu(self):
        string1_txt = Entry(self.__reservmenu, width=50)
        string2_txt = Entry(self.__reservmenu, width=50)
        string3_txt = Entry(self.__reservmenu, width=50)
        string4_txt = Entry(self.__reservmenu, width=50)
        string5_txt = Entry(self.__reservmenu, width=50)
        string6_txt = Entry(self.__reservmenu, width=30)
        string7_txt = Entry(self.__reservmenu, width=30)

        btn1 = Button(self.__reservmenu, text='Mach eine Reservierung', command= lambda: self.read_reserv(string2_txt.get(), string3_txt.get(), string4_txt.get(), string5_txt.get()))
        btn1.grid(column=0, row=0)

        btn2 = Button(self.__reservmenu, text='Anzeige die Liste von Gästen, die aktuelle Reservierungen haben', command=self.show_guests_reserv_today)
        btn2.grid(column=1, row=0)

        btn3 = Button(self.__reservmenu, text='Anzeige alle Zimmer gefiltert mit Preis und Meerblick Kriterien', command= lambda: self.sort_room_filter(int(string6_txt.get()), int(string7_txt.get()), self.meerblickvar))
        btn3.grid(column=2, row=0)

        btn4 = Button(self.__reservmenu, text='Anzeige alle Zimmer, die heute frei sind', command= self.show_rooms_free_today)
        btn4.grid(column=3, row=0)

        btn5 = Button(self.__reservmenu, text='Main Menu', command=self.draw_menu_again_reservmenu)
        btn5.grid(column=4, row=0)

        nr = Label(self.__reservmenu, text='nr')
        nr.grid(column=0, row=2)
        string1_txt.grid(column=1, row=2)

        guests = Label(self.__reservmenu, text='guests')
        guests.grid(column=0, row=3)
        string2_txt.grid(column=1, row=3)

        room = Label(self.__reservmenu, text='room')
        room.grid(column=0, row=4)
        string3_txt.grid(column=1, row=4)

        datestart = Label(self.__reservmenu, text='datestart')
        datestart.grid(column=0, row=5)
        string4_txt.grid(column=1, row=5)

        datefin = Label(self.__reservmenu, text='datefin')
        datefin.grid(column=0, row=6)
        string5_txt.grid(column=1, row=6)

        pricestart = Label(self.__reservmenu, text='Preis Start:   ')
        pricestart.grid(column=2, row=2)
        string6_txt.grid(column=3, row=2)

        pricefinish = Label(self.__reservmenu, text='Preis Finish: ')
        pricefinish.grid(column=2, row=3)
        string7_txt.grid(column=3, row=3)

        meerblickc = IntVar()
        meerblicklabel = Label(self.__reservmenu, text='Meerblick:   ')
        meerblicklabel.grid(column=2, row=4)
        Checkbutton(self.__reservmenu, variable=meerblickc, onvalue=1, offvalue=0, command = lambda: self.check_button_pressed()).grid(column=3, row=4)


    def draw_reservmenu(self):
        self.__mainmenu.pack_forget()
        self.__reservmenu.pack(fill=X)

    def draw_menu_again_roommenu(self):
        self.__roommenu.pack_forget()
        self.__mainmenu.pack(fill=X)

    def draw_menu_again_guestmenu(self):
        self.__guestmenu.pack_forget()
        self.__mainmenu.pack(fill=X)

    def draw_menu_again_reservmenu(self):
        self.__reservmenu.pack_forget()
        self.__mainmenu.pack(fill=X)

    def draw_menu(self):
        self.__mainmenu.pack(fill=X)

    def pass1(self):
        pass

'''
    def __add_guest(self):
        s1 = self.__string1_txt.get()
        s2 = self.__string2_txt.get()
        # print(s1)
        # print(s2)
        g = Gaste(str(s1), str(s2), [])
        print(g)
        Funct.add_guest(g)

        # clear textboxes
        self.__string1_txt.delete(0, 'end')
        self.__string2_txt.delete(0, 'end')
'''