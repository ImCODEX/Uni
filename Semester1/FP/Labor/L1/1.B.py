def _input(l):
    n = int(input("numarul de elemente din vector= "))
    for i in range(n):
        l.append(int(input()))
    return n

def output0(lenn,j,l):
    print(lenn," ")
    print(l[j:j+lenn])
    #for i in range(j,j+lenn):
       # print (l[i])

def main():
    len=1; lenn=1; j=0; l=[]
    n=_input(l)
    for i in range(n-1):
        if l[i]<l[i+1]:
         len=len+1
        else:
            if len>lenn:
                 lenn=len
                 j=i+1-lenn
            len=1

    if len>lenn:
            lenn=len
            j =n-lenn
    output0(lenn,j,l)

main()

