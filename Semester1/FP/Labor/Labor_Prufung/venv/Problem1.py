def isPrime(n):
    if n == 2 or n == 3: return True
    if n % 2 == 0 or n < 2: return False
    for i in range(3, int(n ** 0.5) + 1, 2):  # merge din numar impar in numar impar
        if n % i == 0:
            return False

    return True


def verificare(f):
    fread = f.readlines()
    line = 0
    linep = 0
    nr = 0
    nrb = 0

    for i in fread:
        line += 1
        ok = 0
        if line % 2 == 0:
            for x in i.strip().split(","):
                if x[-1] in "aeiou":
                    ok = 1

            if ok == 0:
                raise Exception("Linia ", line, " nu contine ce putin un cuvant care sa se termine cu a,e,i,o sau u")

        for j in i.strip().split(","):
            if j.isnumeric():
                nr = nr + int(j)
                if isPrime(int(j)) == True:
                    linep += 1
            elif j.isalpha():
                for x in j:
                    nrb += 1

    if nr != 0 and nr < nrb:
        raise Exception("Suma tuturor numerelor", nr, ") nu este mai mare decat suma tuturor literelor", nrb)

    if isPrime(linep) == False:
        raise Exception("Numarul linilor care au numere prime (", linep, ") nu este prim!")

    print("OK")


def main():
    f = open("file.txt", "r")
    try:
        verificare(f)
    except Exception as eroare:
        print(eroare)


main()
