def main():
    l=[];
    n=int(input("n="))
    for i in range(n):
        l.append(int(input()))
    i = 0
    while i < n:
        if l[i] in l[i+1:]:
            l.pop(i)
            n -= 1
            i -= 1
        i += 1
    print(l)

main()

