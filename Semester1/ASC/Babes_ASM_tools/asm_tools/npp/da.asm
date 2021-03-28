; EAX = (c+b)/(22-a+b-108)-d+8*a
;a BYTE, b WORD, c,d DOUBLEWORD
;a = 4 , b = 100, c = 50, d = 25 
; (50+100)/(22-4+100-108)-25+8*4 = 150/10 - 25 + 32 = 15 - 25 + 32 = 22

bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 4
    b dw 100
    c dd 50
    d dd 25
; our code starts here
segment code use32 class=code
    start:
        mov BX, [c]; mutam partea low [c] in BX
        mov CX, [c+2]; mutam partea high a lui [c] pe CX
        mov AX, [b];
        cwd; DX:AX = [b]
        add AX,BX
        adc DX,CX ; DX:AX = c+b 
        mov BX, 22
        push AX
        push DX
        mov AL, [a] 
        cbw; AX = [a]
        mov CX,AX; CX = [a]
        pop DX
        pop AX; DX:AX = c+b
        sub BX,CX; BX = 22-a
        mov CX, [b]
        add BX,CX; BX = 22-a+b
        sub BX, 108
        idiv BX; AX = (c+b)/(22-a+b-108)
        cwd; DX:AX = (c+b)/(22-a+b-108)
        mov BX, [d]
        mov CX, [d+2] ; CX:BX = [d]
        sub AX, BX
        sbb DX, CX ; DX:AX = (c+b)/(22-a+b-108)-d
        push AX
        push DX; punem DX:AX pe stiva
        mov AL, [a]; AX = a
        mov CL, 8
        imul CL; AL = a*8
        mov BX, AX; BX = a*8
        pop DX
        pop AX; DX:AX = (c+b)/(22-a+b-108)-d
        add AX,BX
        adc DX,0 ; DX:AX = rezultatul final
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
