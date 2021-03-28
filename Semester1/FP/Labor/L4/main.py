from GUI.Interface import GUI
from tkinter import *
from Functions.Hotel import Hotel
from Entities.Guest import *
from Entities.Reservation import *
from Entities.Room import *
from datetime import datetime
from tkinter.filedialog import askopenfilename
def pick_in_file():
    return askopenfilename(initialdir=r"C:\Users\razva\OneDrive\Documents\UBBIG\FP\L3_redone", title="Select the input file", filetype=
    (("Text files", "*.txt"),
     ("All files", "*.*")))  # show an "Open" dialog box and return the path to the selected file
def pick_out_file():
    return askopenfilename(initialdir=r"C:\Users\razva\OneDrive\Documents\UBBIG\FP\L3_redone", title="Select the output file", filetype=
    (("Text files", "*.txt"),
     ("All files", "*.*")))  # show an "Open" dialog box and return the path to the selected file


max_id = 0
def loadFromFile(Funct,Filename):
    max_id = 0
    #gaste_file = open("Gaste_File.txt", 'r')
    #room_file = open("Room_File.txt", 'r')
    #reserv_file = open("Reserv_File.txt", 'r')
    all_file = open(Filename,'r')
    i=0


    def read_room(line):
        info = line.split(";")
        temp = Room(int(info[0]), int(info[1]), int(info[2]), str(info[3]), int(info[4]))
        Funct.add_room(temp)
    #room_file.close()

    def read_guest(line):
        info=line.split(";")

        info[2]=info[2].replace(' ','')
        info[2]=info[2].replace('[','')
        info[2]=info[2].replace(']','')
        info[2]=info[2].replace('\n','')
        li = info[2].split(",")
        if info[2]:
            for i in range(0,len(li)):
                li[i]=int(li[i])
        else:
            li=[]

        temp=Gaste(str(info[0]),str(info[1]),li)
        Funct.add_guest(temp)

    #gaste_file.close()
    def read_reserv(line):
        info = line.split(";")
        global max_id
        if int(info[0])>max_id:
            max_id=int(info[0])
        li2=[]
        li = info[1].replace(' ', '')
        li = li.replace('[', '')
        li = li.replace(']', '')
        li = li.replace('\n', '')
        li= li.split(",")

        for el in li:
            el=el.split(":")
            li2.append(Funct.guest_by_name(el[0],el[1]))
        info[3]=info[3].split("-")
        info[4]=info[4].split("-")
        #print(Funct.room_by_number(int(info[2])))
        temp=Reserv(int(info[0]),li2,Funct.room_by_number(int(info[2])),
                    datetime(int(info[3][2]),int(info[3][1]),int(info[3][0])),
                    datetime(int(info[4][2]),int(info[4][1]),int(info[4][0])))
        Funct.make_reserv_existing(temp)
    #reserv_file.close()

    for line in all_file:

        if line=="-\n":
            i=i+1
        elif line=="-":
            i = i + 1
        elif line=="\n":
            i=i+1
        elif i==0:
            read_room(line)
        elif i==1:
            read_guest(line)
        else:
            read_reserv(line)
    for el in Funct.guests:
        for i in range(0,len(el.reserv)):
            el.reserv[i] = Funct.reserv_by_id(el.reserv[i])

    Funct.index_reserv=max_id
    all_file.close()

def saveToFile(Funct,Filename):
    '''gaste_file = open("Gaste_File.txt", 'w')
    room_file = open("Room_File.txt", 'w')
    reserv_file = open("Reserv_File.txt", 'w')'''
    all_file = open(Filename,'w')
    for el in Funct.rooms:
        all_file.write(str(el) + '\n')

    all_file.write('-'+'\n')
    for el in Funct.guests:
        all_file.write(str(el) + '\n')
    all_file.write('-' + '\n')
    for el in Funct.reservs:
        all_file.write(str(el) + '\n')


def main():

     controller = Hotel()
     #loadFromFile(controller, pick_in_file())
     '''guest1 = Gaste("Bob", "Derryl", [])
     guest2 = Gaste("Emil", "Dorel", [])
     controller.add_guest(guest1)
     controller.add_guest(guest2)
     room1 = Room(1, 3, 200, "Rot", 0)
     room2 = Room(2, 2, 150, "Grun", 1)
     controller.add_room(room1)
     controller.add_room(room2)
     reserv1 = Reserv(1, [guest1, guest2], room1, datetime(2020, 11, 21), datetime(2020, 11, 24))
     reserv2 = Reserv(2, [guest1, guest2], room2, datetime(2020, 11, 26), datetime(2020, 11, 29))
     controller.make_reserv(reserv1)
     controller.make_reserv(reserv2)
     '''
     fakeroot=Tk()
     fakeroot.withdraw()
     root = Tk()
     root.title("HOTEL")
     #root.withdraw()
     #root.deiconify()
     g = GUI(root, controller, fakeroot)
     g.draw_menu()
     root.mainloop()  # BLOCKS
     '''
     root = Tk()
     g = GUI(root, controller)
     frame = Frame(root)
     Grid.rowconfigure(root, 0, weight=1)
     Grid.columnconfigure(root, 0, weight=1)
     frame.grid(row=0, column=0, sticky=N + S + E + W)
     grid = Frame(frame)
     grid.grid(sticky=N + S + E + W, column=0, row=7, columnspan=2)
     Grid.rowconfigure(frame, 7, weight=1)
     Grid.columnconfigure(frame, 0, weight=1)

     # example values
     for x in range(10):
          for y in range(5):
               btn = Button(frame)
               btn.grid(column=x, row=y, sticky=N + S + E + W)

     for x in range(10):
          Grid.columnconfigure(frame, x, weight=1)

     for y in range(5):
          Grid.rowconfigure(frame, y, weight=1)

     root.mainloop()
     '''
     


main()