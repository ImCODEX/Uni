# math import pi
import math
class Circle:
    def __init__(self, radius, centre):
        self.__radius = radius
        self.__centre = centre

    def __str__(self):
        return "radius: " +str(self.__radius) + " centre: " + str(self.__centre)

    def __repr__(self):
        return "radius: " +str(self.__radius) + " centre: " + str(self.__centre)

    def __lt__(self, other):
        return self.__radius < other.radius

    @property
    def radius(self):
        return self.__radius

    @property
    def centre(self):
        return self.__centre

    @radius.setter
    def radius(self, new_radius):
        self.__radius = new_radius

    def compute_area(self):
        return math.pi*self.__radius**2

    def __mul__(self, other):
        sum_m = self.__centre + other.centre
        produkt_radius = self.__radius * other.radius
        new_circle = Circle(produkt_radius, sum_m)
        return new_circle

