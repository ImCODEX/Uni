class Kunde:
    def __init__(self, Name, Adresse, Lieblingsessen):
        self.__Name = Name
        self.__Adresse = Adresse
        self.__BestellungenListe = []
        self.__Lieblingsessen = Lieblingsessen           #list
        self.__BestellungenHistory = []

    def __str__(self):
        return "Name: {}, Adresse: {}, Aktuelle Bestellungen: {}, Lieblingsessen: {}, Alle Bestellungen: {}".format(
            self.__Name, self.__Adresse, self.__BestellungenListe, self.__Lieblingsessen, self.__BestellungenHistory)

    def __repr__(self):
        return "Name: {}, Adresse: {}, Aktuelle Bestellungen: {}, Lieblingsessen: {}, Alle Bestellungen: {}".format(
            self.__Name, self.__Adresse, self.__BestellungenListe, self.__Lieblingsessen, self.__BestellungenHistory)

    def favouritesAnzeigen(self, RestaurantListe, x):
        """Zeigt alle geeignete Restaurants mit rating mindestens x - durch list comprehension"""
        return [restaurant.Name for restaurant in RestaurantListe if restaurant.Profil in self.__Lieblingsessen and restaurant.Rating >= x]

    def bestellen(self, restaurant, Essen):
        restaurant.bestellen(self, Essen)
        self.__BestellungenListe.append([restaurant.Name, Essen])
        self.__BestellungenHistory.append([restaurant.Name, Essen])

    def geliefert(self, restaurantName, Essen):
        if [restaurantName, Essen] in self.__BestellungenListe:
            self.__BestellungenListe.remove([restaurantName, Essen])

    def bestellungenAnzeigen(self):
        for bestellung in self.__BestellungenListe:
            print(bestellung)

    @property
    def Name(self):
        return self.__Name

class Restaurant:
    def __init__(self, Name, Profil, Rating):
        self.__Name = Name
        self.__Profil = Profil
        self.__Rating = Rating      #int
        self.__BestellungenListe = []

    def __str__(self):
        return "Name: {}, Profil: {}, Rating: {}, BestellungenListe: {}".format(
            self.__Name, self.__Profil, self.__Rating, self.__BestellungenListe)

    def __repr__(self):
        return "Name: {}, Profil: {}, Rating: {}, BestellungenListe: {}".format(
            self.__Name, self.__Profil, self.__Rating, self.__BestellungenListe)

    def bestellen(self, kunde, Essen):
        self.__BestellungenListe.append([kunde, Essen])

    def anlieferung(self, kunde, Essen):
        if [kunde, Essen] in self.__BestellungenListe:
            kunde.geliefert(self.__Name, Essen)
            self.__BestellungenListe.remove([kunde, Essen])
            print("Danke für Ihre Bestellung, {}".format(kunde.Name))
        else:
            print("Problem mit {} Befehl. Returning...".format(kunde.Name))

    def bestellungenAnzeigen(self):
        for bestellung in self.__BestellungenListe:
            print(bestellung[0].Name + ", " + bestellung[1])

    @property
    def Profil(self):
        return self.__Profil

    @property
    def Rating(self):
        return self.__Rating

    @property
    def Name(self):
        return self.__Name

def main():
    restaurants = []

    ChinaFood = Restaurant("ChinaFood", "chinesisch", 3)
    XiuHuy = Restaurant("XiuHuy", "chinesisch", 2)
    MaiLi = Restaurant("MaiLi", "chinesisch", 4)
    KFC = Restaurant("KFC", "fast-food", 3)

    restaurants.append(ChinaFood)
    restaurants.append(XiuHuy)
    restaurants.append(MaiLi)
    restaurants.append(KFC)

    Zhang = Kunde("Zhang Liu", "China", ["chinesisch", "fast-food"])
    print(Zhang.favouritesAnzeigen(restaurants, 3))

    Zhang.bestellen(MaiLi, "pasta")
    Zhang.bestellen(KFC, "burger")

    print()
    Zhang.bestellungenAnzeigen()

    print()
    MaiLi.bestellungenAnzeigen()
    MaiLi.anlieferung(Zhang, "pasta")
    print()

    MaiLi.bestellungenAnzeigen() #none
    Zhang.bestellungenAnzeigen()
main()