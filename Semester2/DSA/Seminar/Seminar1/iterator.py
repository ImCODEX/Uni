class Iterator:
    def __init__(self, bag):
        self.__i = 0
        self.__bag = bag

    def valid(self):
        if self.__i < 0 or self.__i >= self.__bag.size:
            return False
        return True

    def first(self):
        if not self.valid():
            raise IndexError
        self.__i=0

    def next(self):
        if not self.valid():
            raise IndexError
        self.__i=self.__i+1


    def getCurrent(self):
        if not self.valid():
            raise IndexError
        return self.__bag.list[self.__i]
