def is_prim(i):
    ok=1
    for j in range (2,i):
        if (i % j) == 0:
             ok=0
             return False
    if ok!=0:
        return True
def main():
    n = input("n= ")
    n = int(n)
    i = 0
    x = 2
    while i < n:
        if is_prim(x)==True:
            print(x,' ')
            i += 1
        x += 1

main()