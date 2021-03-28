class Service:
    def __init__(self, Pizzerie, Kunde):
        self.__Pizzerie = Pizzerie
        self.__Kunde = Kunde

    def bestellen(self, k, p):
        vpa = self.__Pizzerie.index(p)
        vp = self.__Pizzerie[vpa]
        vka = self.__Kunde.index(k)
        vk = self.__Kunde[vka]
        vk.order_list.append(vp.name)
        vp.order_list.append(vk.vorname)
        
    def ratingGeben(self, nota, p):
        vpa = self.__Pizzerie.index(p)
        vp = self.__Pizzerie[vpa]
        vp.rating.append(int(nota))

    def lieblingsPizzerien(self, k):
        vka = self.__Kunde.index(k)
        vk = self.__Kunde[vka]
        max1 = 0
        max2 = 0
        max3 = 0
        p1 = None
        p2 = None
        p3 = None
        for pizzerie in self.__Pizzerie:
            nr = vk.order_list.count(pizzerie.name)
            if nr > max1:
                max3 = max2
                p3 = p2
                max2 = max1
                p2 = p1
                max1 = nr
                p1 = pizzerie
            elif nr > max2:
                max3 = max2
                p3 = p2
                max2 = nr
                p2 = pizzerie
            elif nr > max3:
                max3 = nr
                p3 = pizzerie
        print(p1,"Comenzi: ", max1, "\n",p2, "Comenzi: ", max2 ,"\n", p3,"Comenzi: ",max3)


class Pizzierie:
    def __init__(self, name, rating, orderlist):
        self.__name = name
        self.__rating = rating
        self.__order_list = orderlist

    @property
    def name(self):
        return self.__name

    @property
    def rating(self):
        return self.__rating

    @property
    def order_list(self):
        return self.__order_list

    @name.setter
    def name(self, other):
        self.__name = other

    @rating.setter
    def rating(self, other):
        self.__rating = other

    @order_list.setter
    def order_list(self, other):
        self.__order_list = other


    def get_rating(self):
        return "Rating-ul total este: " + str(sum(self.__rating)/len(self.__rating))

    def __str__(self):
        return "Name: "+self.__name +" Rating: "+str(self.get_rating())+" Order List: " + str(self.__order_list)

    def __repr__(self):
        return "Name: " + self.__name + " Rating: " + str(self.get_rating()) + " Order List: " + str(self.__order_list)

class Kunde:
    def __init__(self, name, vorname, cardnumber, orderlist):
        self.__name = name
        self.__vorname = vorname
        self.__cardnumber = cardnumber
        self.__order_list = orderlist

    @property
    def name(self):
        return self.__name

    @property
    def vorname(self):
        return self.__vorname

    @property
    def order_list(self):
        return self.__order_list

    @property
    def cardnumber(self):
        return self.__cardnumber

    @name.setter
    def name(self, other):
        self.__name = other

    @vorname.setter
    def vorname(self, other):
        self.__vorname = other

    @order_list.setter
    def order_list(self, other):
        self.__order_list = other

    @cardnumber.setter
    def cardnumber(self, other):
        self.__cardnumber = other


    def __str__(self):
        return "Name: "+self.__name +" Vorname: "+self.__vorname+" Card Number: "+self.__cardnumber+" Order List: " + str(self.__order_list)

    def __repr__(self):
        return "Name: "+self.__name +" Vorname: "+self.__vorname+" Card Number: "+self.__cardnumber+" Order List: " + str(self.__order_list)

def main():
    lp = [Pizzierie("Pizeria1",[5],[]),Pizzierie("Pizeria2",[4],[]),Pizzierie("Pizeria4",[2],[])]
    lk = [Kunde("marcel","dorel","5555",[]),Kunde("viorel","gabriel","552355",[]),Kunde("andrei","hap","5555",[])]
    Sv1 = Service(lp,lk)
    Sv1.bestellen(lk[1],lp[2])
    Sv1.bestellen(lk[1], lp[2])
    Sv1.bestellen(lk[1], lp[2])
    Sv1.bestellen(lk[1], lp[1])
    Sv1.bestellen(lk[1], lp[0])
    #print(lk[1])
    #print(lp[2])
    #print(lk[1])
    x = 10
    y = 15
    print(hex(id(x)))
    print(hex(id(y)))
    #print(hex(id(lk[1]._Kunde__name)))
    #print(id(lk[1].name))

    #Sv1.ratingGeben(3,lp[1])
    #print(lp[1].get_rating())
    #Sv1.lieblingsPizzerien(lk[1])


main()