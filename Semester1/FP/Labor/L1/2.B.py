def cmmdc(a,b):
    while (a!=b):
        if(a>b):
            a=a-b
        else:
            b=b-a
    return a

def output0(lenn,j,l) :
    print(lenn," ")
    for i in range(j,j+lenn):
        print (l[i])

def main():
    len=1; lenn=1; n=int(input("numarul de elemente din vector= "));  l=[]; j=0

    for i in range(n):
     l.append(int(input()))

    for i in range(n-1):
     if cmmdc(l[i],l[i+1])==1:
          len=len+1
     else:
        if len>lenn:
            lenn=len
            j=i+1-lenn
        len=1

    if len>lenn:
        lenn=len
        j=n-lenn

    output0(lenn,j,l)

main()
