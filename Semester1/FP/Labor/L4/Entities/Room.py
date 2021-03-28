class Room:
    def __init__(self, nr, maxguest, price, color, sea_view):
        self.__nr=nr#used as unique ID
        self.__maxguest=maxguest
        self.__price=price
        self.__color=color
        self.__sea_view=sea_view

    @property#getter nr
    def nr(self): return self.__nr

    @property#getter maxguest
    def maxguest(self): return self.__maxguest

    @property#getter price
    def price(self): return self.__price

    @property#getter color
    def color(self): return self.__color

    @property#getter sea_view
    def sea_view(self): return self.__sea_view

    @nr.setter#setter nr
    def nr(self,a): self.__nr = a

    @maxguest.setter#setter maxguest
    def maxguest(self,a): self.__maxguest = a

    @price.setter#setter price
    def price(self, a): self.__price = a

    @color.setter#setter color
    def color(self,a): self.__color = a

    @sea_view.setter#setter sea_view
    def sea_view(self,a): self.__view = a

    def __str__(self):
        return "{};{};{};{};{}".format(self.__nr, self.__maxguest, self.__price, self.__color, self.__sea_view)