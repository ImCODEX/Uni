def output0(lenn,j,l) :
    print(lenn," ")
    print (l[j:j+lenn])

def main():
    len=1; lenn=1; n=int(input("numarul de elemente din vector= "));  l=[]; j=0

    for i in range(n):
     l.append(int(input()))

    for i in range(n-1):
      y = l[i] % 10; x = l[i+1]//10
      if y == x:
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