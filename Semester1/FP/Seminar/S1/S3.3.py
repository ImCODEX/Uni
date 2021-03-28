def Switchvoc(cuv):
    i=0
    j=len(cuv)-1
    l=list(cuv)
    while(i<j):
        if l[i] not in "AEUIOUaeiou":
            i+=1
        if l[j] not in "AEUIOUaeiou":
            j-=1
        if l[j]  in "AEUIOUaeiou":
            l[j],l[i]=l[i],l[j]
            i+=1
            j-=1
    return "".join(l)


def main():
    stri="Terminator"
    print(Switchvoc(stri))

main()