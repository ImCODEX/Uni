class Point:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    def __str__(self):
        return "x = " +str(self.__x) + " y= " +str(self.__y)

    def __repr__(self):
        return "x = " + str(self.__x) + " y= " + str(self.__y)

    @property
    def x(self):
        return self.__x

    @x.setter
    def x(self, new_x):
        self.x = new_x

    @property
    def y(self):
        return self.__y

    @y.setter
    def y(self, new_y):
        self.y = new_y

    def __add__(self, other):
        sum_x = self.__x + other.x
        sum_y = self.__y + other.y
        new_point = Point(sum_x, sum_y)
        return new_point