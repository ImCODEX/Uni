; Scrieți un program în limbaj de asamblare care să rezolve expresia aritmetică, considerând domeniile de definiție ale variabilelor
; a,b,c - byte;
; 3*[20*(b-a+2)-10*c]/5 ;  ex: a = 50 , b= 100 ; c = 25 => 3*[20*(100-50+2)-10*25)/5 = 3*[20*52 - 250]/5 = 3*[1040 - 250]/5 = 3*790/5 = 2370/5 = 474
bits 32 ;asamblare si compilare pentru arhitectura de 32 biti
; definim punctul de intrare in programul principal
global  start 

extern  exit ; indicam asamblorului ca exit exista, chiar daca noi nu o vom defini
import  exit msvcrt.dll; exit este o functie care incheie procesul, este definita in msvcrt.dll
        ; msvcrt.dll contine exit, printf si toate celelalte functii C-runtime importante
segment  data use32 class=data ; segmentul de date in care se vor defini variabilele 
	a db 50
	b db 100
	c db 25
    
segment  code use32 class=code ; segmentul de cod
start: 
    mov al, [c]; mutam valoare lui c in AL
    mov dl,10 ; DL = 10
    mul BYTE dl ;facem operatia AX = 10*c
    push ax ; punem ax in stiva
    
	mov al, [b] ;punem valoarea lui b in AL 
    sub al, [a] ; facem operatia AL = b -  a
    add al, 2 ; facem operatia AL = b - a + 2 
    mov dl, 20 ; DL = 20
	mul BYTE dl ; AX = AL * DL
    
    pop bx ;punem vechea valoare a lui ax ( 10*c ) in bx
    
    sub ax, bx ;facem operatia AX = 20*(b-a+2)-10*c
    mov dx,3
    mul WORD dx; facem operatia DX:AX = 3*[20*(b-a+2)-10*c]
    mov bx,5; BX = 5 
    div bx; facem operatia AX = DX:AX / BX = 3*[20*(b-a+2)-10*c]/5
    
    

	
    push dword 0 ;se pune pe stiva codul de retur al functiei exit
	call [exit] ;apelul functiei sistem exit pentru terminarea executiei programului	