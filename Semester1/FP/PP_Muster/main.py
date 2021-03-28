def isPrime(n):
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    for i in range(3, int(n**0.5)+1, 2):   # only odd numbers
        if n%i==0:
            return False

    return True


def verificare(f):
    fread = f.readlines()
    #print(fread)
    mul3 = 0
    nr = 0
    nrcrt = {}

    for i in fread:
        mul3 += 1
        x = 0
        if mul3 % 3 == 0 and i.strip().split()[0][0] != ".":
            raise Exception("Linia ", mul3, " nu incepe cu .")

        for j in range(len(i.strip().replace(" ","").split()[0])):
            if i.strip().replace(" ","").split()[0][j] >= "0" and i.strip().replace(" ","").split()[0][j] <= "9":
                #print("Numar: ", i.strip().replace(" ","").split()[0][j])
                nr = nr + int(i.strip().replace(" ","").split()[0][j])

        for j in range(len(i.split())):
            if i.split()[j].isalpha():
                x += len(i.split()[j])

        nrcrt[mul3] = x
        #print(nrcrt[mul3], " ", mul3)
        if nrcrt[mul3] > 124:
            raise Exception("Numarul caracterelor de pe linia ", mul3, " este mai mare decat 124")

    if isPrime(nr) == False:
        raise Exception("Suma numerelor (", nr,") nu este prima!")

    print("OK")




def main():
    #f = open("file.txt", "r")
    #verificare(f)
    l = [10,20,30]
    for idx, elem in enumerate(l): print(elem," ", idx)

main()