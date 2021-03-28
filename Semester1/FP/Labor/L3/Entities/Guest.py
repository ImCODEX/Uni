class Gaste:
    def __init__(self, nachname, vorname, reserv):
        self.__nachname = nachname
        self.__vorname = vorname
        self.__reserv = reserv

    @property#getter nachname
    def nachname(self): return self.__nachname

    @property#getter vorname
    def vorname(self): return self.__vorname

    @property#getter reserv
    def reserv(self): return self.__reserv

    @nachname.setter#setter nachname
    def nachname(self, a):
        self.__nachname = a

    @vorname.setter#setter vorname
    def vorname(self, b):
        self.__vorname = b

    @reserv.setter#setter reserv
    def reserv(self, a): self.__reserv = a

    def add_reserv(self, reserv):#appends a reserv to the guests reserv list
        self.__reserv.append(reserv)

    def __str__(self):
        return "{};{};{}".format(self.__nachname, self.__vorname, self.__reserv)

    def __repr__(self):  # guest representation (used in lists)
        return "{}:{}".format(self.__nachname, self.__vorname)
        # return "Nachname: %s Vorname: %s " % (self.__nachname, self.__vorname)

