from math import gcd
class rationalnumber:
    def __init__(self,numarator,numitor):
        self.__numarator = numarator
        self.__numitor = numitor
    @property
    def numarator(self):
        return self.__numarator

    @property
    def numitor(self):
        return self.__numitor

    @numarator.setter
    def numarator(self,a):
        self.__numarator = a

    @numitor.setter
    def numitor(self,b):
        self.__numitor = b

    def __str__(self):
        return "Numitor: %s, Numarator: %s" %(self.numitor,self.numarator)

    def add(self,x):
        c = rationalnumber(0,1)
        if self.numitor != x.numitor:
            c.numitor = self.numitor * x.numitor
            c.numarator = self.numarator * x.numitor + x.numarator * self.numitor
        else:
            c.numarator = self.numarator + x.numarator
            c.numitor = self.numitor
        return c

    def simplify(self):
        #c = rationalnumber(0,1)
        cmm = gcd(self.numitor,self.numarator)

        self.numitor = self.numitor // cmm
        self.numarator = self.numarator // cmm
        #return c