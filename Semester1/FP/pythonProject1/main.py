class Student:
    index = 0
    def __init__(self):
        self.__Name = ''
        self.__Noten = []
        self.index = Student.index
        Student.index += 1

    def __str__(self):
        return "Name: {}, Noten: {}".format(self.__Name, self.__Noten)

    def __repr__(self):
        return "Name: {}, Noten: {}".format(self.__Name, self.__Noten)

    def read_data(self):
        with open("date2.txt", "r") as file:
            line = file.readlines()[self.index]
            for word in line.split():
                if word.isdigit() == False:
                    self.__Name = self.__Name + word + ' '
                else:
                    self.__Noten.append(int(word))
            self.__Name = self.__Name.rstrip()    #elimin ultimul whitespace din nume, not sexy

    def __lt__(self, other):
        """Compararea a doua obiecte din clasa student se va face pe baza listelor de note: Obiect1 < Obiect2 <=> lista_note1 mai mic lexicografic (deja implemetat prin '<') decat lista_note2"""
        if self.__Noten < other.Noten:
            return True
        return False

    @property
    def Noten(self):
        return self.__Noten

def selection_sort(list):
    for i in range(len(list)):
        min_index = i   #indexul minim by default

        #acum cautam cel mai mic index din lista nesortata
        for j in range(i+1, len(list)):
            if list[j] < list[min_index]:
                min_index = j

        #dupa ce il gasim, il inlocuim cu primul element
        list[i], list[min_index] = list[min_index], list[i]
    return list

def main():

    StudentsList = []

    Eva = Student()
    Adam = Student()
    Snake = Student()
    Cain = Student()
    Abel = Student()

    Eva.read_data()
    Adam.read_data()
    Snake.read_data()
    Cain.read_data()
    Abel.read_data()

    StudentsList.append(Eva)
    StudentsList.append(Adam)
    StudentsList.append(Snake)
    StudentsList.append(Cain)
    StudentsList.append(Abel)

    print(selection_sort(StudentsList))

main()