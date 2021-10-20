bits 32 ; assembling for the 32 bits architecture
;Se da un sir de octeti S. Sa se construiasca sirul D1 ce contine elementele de pe pozitiile 
;pare din S si sirul D2 ce contine elementele de pe pozitiile impare din S. 
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s db 1, 5, 3, 8, 2, 9
    l equ $-s
    d1 times l/2 + 1 db 0 ;pare
    d2 times l/2 db 0
segment code use32 class=code
    start:
        mov ecx, l
        mov ebx, 0
        mov edx, 0 ; counter pt d1 si d2
        jecxz sareclubusarecandsatraeplecataindeplasare ; sare cand lungimea sirului e 0
        
        lup: 
            mov al, [s+ebx] ; pregatesc byte-ul care urmeaza sa fie mutat 
            test ebx, 1 ; seteaza zero flag = 1 cand e para
            JZ sarepara ; sare cand pozitia e para 
            mov [d2+edx], al ; pune in d2 elementele de pe pozitii impare 
            inc edx ; incrementeaza counterul din d2 si d1 concomitent ( prima pozitie fiind 0 face jump la "sarepara" si urmatoarea va fi impara iar abia atunci face incrementare, si tot asa, face incrementare doar dupa ce parcurge doua pozitii in sirul s)
            JMP sarecandeimpar; jump neconditionat care se executa cand pozitia e impara 
            sarepara:
                mov [d1+edx], al ; pune in d1 elementele de pe pozitii pare
            sarecandeimpar:
                inc ebx; incrementeaza la fiecare loop valoarea din ebx pentru a determina pozitia din s
        loop lup
        
        sareclubusarecandsatraeplecataindeplasare:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
