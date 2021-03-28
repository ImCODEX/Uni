class Tisch:
    def __init__(self, Farbe, Lange):
        self.__Farbe = Farbe
        self.__Lange = Lange

    '''
    def __lt__(self, other):
        return self.__Lange < other.__Lange
    '''

    @property
    def Farbe(self):
        return self.__Farbe

    @property
    def Lange(self):
        return self.__Lange

    @Farbe.setter
    def Farbe(self, other):
        self.__Farbe = other

    @Lange.setter
    def Lange(self, other):
        self.__Lange = other

    def __str__(self):
        return f"Tischstr: {self.__Farbe}; {self.__Lange}"

    def __repr__(self):
        return f"Tisch: {self.__Farbe}; {self.__Lange}"
