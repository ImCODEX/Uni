class Bag:
    def __init__(self, size):
        self.__list = []
        self.__size = size

    @property
    def list(self):
        return self.__list

    @property
    def size(self):
        return self.__size

    def add_item(self, other):
        if len(self.__list) >= self.__size:
            raise Exception('Bag is full')
        self.__list.append(other)

    def remove_item(self, other):
        self.__list.remove(other)

    def __len__(self):
        return len(self.__list)

    def nrOccurrences(self, other):
        return self.__list.count(other)

    def search(self, other):
        if self.nrOccurrences(other) != 0:
            return True
        return False


