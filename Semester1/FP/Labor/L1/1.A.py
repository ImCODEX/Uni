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
    for i in range(2, n):
        if is_prim(i)==True:
            print(i,' ')

main()