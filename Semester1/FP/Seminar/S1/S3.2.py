def bigSum(num1,num2):
    rez=""
    trecerea=0
    #for i in range (min (len(num1),len(num2)),max(len(num1),len(num2))-1,-1):
    for i in range(1,min(len(num1),len(num2))+1):
        s=int(num1[-i])+int(num2[-i])
        if s>9:
            trecerea=1
        else:
            trecerea=0
        rez=str(s%10)+rez
    if len(num1)>len(num2):
        for i in range(min(len(num1),len(num2))+1,len(num1)+1):
            s=int(num1[-i])+trecerea
            if(s>9):
                trecerea=1
            else:
                trecerea=0
            rez=str(s%10)+rez

    if(trecerea):
        rez=str(trecerea)+rez
    return rez

def main ():
    a="923"
    b="123"
    print(bigSum(a,b))

main()