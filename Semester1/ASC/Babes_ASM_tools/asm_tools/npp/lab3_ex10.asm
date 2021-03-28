;d-(7-a*b+c)/a-6+x/2; a,c-byte; b-word; d-doubleword; x-qword
; a = 2 c = 1 b = 2 d = 10 x = 80;
; 10-(7-2*2+1)/2-6+80/2 = 10 - (7-5)/2 -6 + 40 = 10 - 1 - 6 + 40 = 43

; REZOLVARE PENTRU INTERPRETAREA FARA SEMN


bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 2
    c db 1
    b dw 2
    d dd 10
    x dq 80

; our code starts here
segment code use32 class=code
    start:
        mov al, [a]; AL = a
        mov ah, 0 ; am convertit [a] din byte in word 
        mul WORD [b]; DX:AX = AL * [b] = a * b
        mov cl, [c]; Cl = c
        mov ch, 0; am convertit [c] din byte in word 
        mov bx, 0; am convertit [c] din word in double word BX:CX = [c]
        add ax, cx; 
        adc dx, bx; in DX:AX avem a*b+c si am tratat cazul cu carry 
        mov cx, 7; 
        mov bx, 0; l-am convertit pe 7 in double word BX:CX = 7
        sub cx,ax; 
        sbb bx,dx; am facut operatia BX:CX = 7-a*b+c tinand cont si de borrow
        mov dx, bx; 
        mov ax, cx; am mutat rezultatul din BX:CX in DX:AX pentru a putea imparti
        mov cl, [a]; 
        mov ch, 0; am convertit [a] din byte in word
        div cx; in AX avem rezultatul impartirii AX = DX:AX / CX
        mov dx, 0; am ignorat restul impartirii de mai sus si am convertit rezultatul impartirii din nou in doubleword
        mov cx, word[d]; 
        mov bx, word[d+4]; in BX:CX l-am pus pe d
        sub cx, ax;
        sbb bx, dx; am efectuat scaderea BX:CX = BX:CX - DX:AX
        mov dx, 0;
        mov ax, 6; am facut 6 double word
        sub cx,ax;
        sbb bx,dx; am efectuat scaderea cu 6: BX:CX = BX:CX - DX:AX
        mov eax, dword[x]; 
        mov edx, dword[x+4]; EDX:EAX = [x]
        push bx; 
        push cx; pune BX:CX pe stiva
        pop ebx; scoatem BX:CX de pe stiva si al punem in EBX
        mov ecx, 2; ECX = 2
        div ecx; EAX = EDX:EAX / 2
        add eax, ebx; EAX = rezultatul final
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
