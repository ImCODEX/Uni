def main():
    l=[]; nr = 0
    n=int(input("n="))
    for i in range(n):
        l.append(int(input()))
    i = 0
    while i < n:
        x=(l[i]%10)*10+l[i]//10
        if x in l[i+1:]:
            nr += 1
        i += 1
    print(nr)


main()
