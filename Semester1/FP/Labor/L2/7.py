def factori(a,f):
    d = 2
    while a >= 1 and d <= a:
        p = 0
        while a % d == 0:
            p +=1
            a= a//d

        if p > 0 and d in f and f[d] < p:
            f[d] = p
        elif p > 0 and d not in f:
            f[d] = p

        d += 1
    return f

def main():
    l=[]; nr = 0
    l = [22, 44, 56, 20, 10, 5, 12]
    f = {}
    i=int(input("i=")); j=int(input("j="))
    for k in range(i,j):
       factori(l[k],f)
    m = 1
    for i in f:
        m = m * pow(int(i),f[i])
    print(m)
    print(f)
main()
