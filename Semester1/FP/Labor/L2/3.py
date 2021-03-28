def main():
    l=[]; nr = 0
    n=int(input("n="))
    for i in range(n):
        l.append(int(input()))
    l.sort(reverse=True)
    x=0;
    for i in range(n):
       x = x * 100 + l[i]
    print("numarul maxim = ",x)
main()
