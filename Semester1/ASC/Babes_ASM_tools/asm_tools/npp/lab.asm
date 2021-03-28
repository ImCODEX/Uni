bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s db 'a', 'A', 'b', 'B','2','%','x','M' ; declararea sirului initial s
	l equ $-s ; stabilirea lungimea sirului initial l
	d times l db 0 ; rezervarea unui spatiu de dimensiune l pentru sirul destinatie d si initializarea acestuia
; our code starts here
segment code use32 class=code
    start:
        mov ecx, l ;punem lungimea in ECX pentru a putea realiza bucla loop de ecx ori
        mov esi, 0   
        mov edi, 0
        mov bl, 'A' 
        jecxz Sfarsit      
        Repeta:
            mov al, [s+esi]
            sub bl, al     
            JNAE sare
                mov [d+edi], al
                inc edi
            sare:
            inc esi
        loop Repeta
        Sfarsit:;terminarea programului
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
