class Gerat:
    def __init__(self, Preis, Hersteller, Effizienzklasse):
        self.Preis = Preis
        self.Hersteller = Hersteller
        self.Effizienzklasse = Effizienzklasse

    def __eq__(self, other):
        if self.Preis == other.Preis and self.Effizienzklasse == other.Effizienzklasse:
            return True
        return False

    def __str__(self):
        return "Hersteller: "+self.Hersteller +" Preis: "+self.Preis +" Effizienzklasse: "+self.Effizienzklasse

    def __repr__(self):
        return self.__str__()

class Kuhlschrank(Gerat):
    def __init__(self, Preis, Hersteller, Effizienzklasse, Kapazitat):
        super().__init__(Preis, Hersteller, Effizienzklasse)
        self.Kapazitat = Kapazitat

    def __str__(self):
        return "Hersteller: "+self.Hersteller +" Preis: "+self.Preis +" Effizienzklasse: "+self.Effizienzklasse +" Kapazitat: "+self.Kapazitat

class Kuche():
    def __init__(self, lGerate):
        self.__lGerate = lGerate

    def wieEffizient(self, oHersteller):
        return list(filter(lambda gerat: gerat.Hersteller == oHersteller, self.__lGerate))

    def add(self, other):
        self.__lGerate.append(other)

    def show(self):
        print(self.__lGerate)


def main():
 Kuche1 = Kuche([])
 frigiderikea1 = Kuhlschrank("1500", "Samsung", "A", "350")
 frigiderflanco1 = Kuhlschrank("1500", "Whirpool", "B", "450")
 Kuche1.add(frigiderikea1)
 Kuche1.add(frigiderflanco1)
 Kuche1.show()
 print(Kuche1.wieEffizient("Samsung"))
 if frigiderflanco1 == frigiderikea1:
     print("ya")
 else:
     print("na")


main()
