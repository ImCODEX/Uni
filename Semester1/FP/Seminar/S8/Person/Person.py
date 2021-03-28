class Person:#baseclass
    def __init__(self, name):
        self.__name = name

    def eat(self):
        print(self.name + ' is eating...')

    @property
    def name (self):
        return self.__name

class Student(Person):
    def __init__(self, name, uni):
        Person.__init__(self, name)

        self.uni = uni

    def sleep(self):
        print(self.name + ' is sleeping...')

    def eat(self):
        print(self.name + ' is eating MUCH!!')
