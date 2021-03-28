def main():
    l=[]; nr = 0
    n=int(input("n="))
    print("Valorile introduse in lista trebuie sa fie de tip boolean (0 sau 1)")
    print("Criptorul=")
    l.append(int(input()))
    print("Lista:")
    for i in range(1,n):
        l.append(int(input()))
    if l[0] == 1:
        for i in range(1,n):
            l[i] = 1 - l[i]
    print("lista criptata este:",l[1:])
main()
