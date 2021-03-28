;d-(7-a*b+c)/a-6+x/2; a,c-byte; b-word; d-doubleword; x-qword
; a = 3 c = 1 b = 5 d = 10 x = 80;
; 10 - (7-3*5+1)/3 -6 + 40 = 10 + 2 -6 + 40 = 46 
;  

; REZOLVARE PENTRU INTERPRETAREA CU SEMN


bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 3
    c db 1
    b dw 5
    d dd 10
    x dq 80
    q dw 40

; our code starts here
segment code use32 class=code
    start:
        mov al, [a]; AL = a
        cbw ; am convertit [a] din byte in word 
        mul WORD [b]; DX:AX = AL * [b] = a * b
        push dx;
        push ax; am pus a*b pe stiva
        mov ebx, 7; 
        pop eax; EAX = a*b
        sub ebx,eax; EBX = 7-a*b
        mov al, [c]; AL = c
        cbw; am convertit [c] din byte in word 
        cwde; am convertit [c] din word in double word EAX = [c]
        add eax, ebx; EAX = (7-a*b) + c 
        push eax; 
        pop dx;
        pop dx; am pus in DX:AX = (7-a*b) + c 
        mov bx,ax; salvez pe ax in bx
        mov al, [a]; AL = a
        cbw ; am convertit [a] din byte in word 
        mov cx, ax; salvez pe ax in cx pentru ca idiv cauta valoarea unu dw in dx:ax
        mov ax, bx; -||-
        idiv cx; AX = [7-a*b + c]/a; in DX restul
        cwde; am convertit EAX = [7-a*b + c]/a 
        mov edx, dword[d]; EDX = [d]
        sub edx, eax; EDX = d-(7-a*b+c)/a
        mov eax, 6; am facut 6 double word
        sub edx, eax; EDX = d-(7-a*b+c)/a - 6
        mov ecx, edx; ECX = d-(7-a*b+c)/a - 6
        
        mov eax, dword[x]; 
        mov edx, dword[x+4]; EDX:EAX = [x]
        mov ebx, 2; EBX = 2
        idiv ebx; EAX = EDX:EBX / 2 = x / 2
        add eax, ecx; EAX = rezultatul final
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
