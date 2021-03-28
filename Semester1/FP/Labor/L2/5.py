def main():
    l=[]; nr = 0
    n=int(input("n="))
    for i in range(n):
        l.append(int(input()))
    i=0
    while i < n:
        if (l[i]//10) != (l[i]%10 * 3): # if (l[i]//10)/(l[i]%10) == 2:
            del l[i]
            i -= 1
            n -= 1
        i += 1
    print(l)
main()
