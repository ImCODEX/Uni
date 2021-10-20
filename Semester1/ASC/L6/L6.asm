bits 32 ; assembling for the 32 bits architecture
;Se de cuvantul A si octetul B. Sa se obtina dublucuvantul C astfel:

;   bitii 0-3 ai lui C coincid cu bitii 6-9 ai lui A
;   bitii 4-5 ai lui C au valoarea 1
;   bitii 6-7 ai lui C coincid cu bitii 1-2 ai lui B
;   bitii 8-23 ai lui C coincid cu bitii lui A
;   bitii 24-31 ai lui C coincid cu bitii lui B

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
     a dw 0111011101010111b
     b db 10111110b
     c dd 0 

; our code starts here
segment code use32 class=code
    start:
        mov dx, 0
        mov ax, 0; c-ul nostru va fi pe dx:ax
        mov cx, [a];
        and cx, 0000001111000000b; izolam bitii
        ror cx, 6; rotim 6 pozitii la dreapta
        or ax, cx;
        
        or ax, 0000000000110000b; bitii 4-5 ai lui C au valoarea 1
        
        mov cx, 0;
        mov cl, [b];
        and cl, 00000110b; izolam bitii 4-5
        rol cx, 5;
        or ax, cx; bitii 6-7 ai lui C coincid cu bitii 1-2 ai lui B
        
        mov cx, [a];
        mov ah, cl;
        mov dl, ch;bitii 8-23 ai lui C coincid cu bitii lui A
        
        mov cx, 0;
        mov cl, [b];
        mov dh, cl; bitii 24-31 ai lui C coincid cu bitii lui B
        
        push dx
        push ax
        
        pop dword[c]; punem rezultatul in C
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
