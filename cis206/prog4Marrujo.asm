;===============================================================================
;   Name: Victor Marrujo
;   Program: prog4Marrujo.asm
;   Description: Program that compares two strings: 
;	Determines if 2 strings are exactly the same, 
;	the same to a certain index, or are completely different.
;===============================================================================


; Section for initializing variables============================================
SECTION .data
    string1: DB "Try harder",0	; First string
    lenString1: EQU ($ - string1)	; length string1
    string2: DB "Try harder still",0	; Second string
    lenString2: EQU ($ - string2)	; lengthstring2
    
    msgEqual: DB "strings are exactly the same",10,0
    lenEqual: EQU ($ - msgEqual)
    msgPartiallyEqual: DB "strings are the same to a certain index",10,0
    lenPartiallyEqual: EQU ($ - msgPartiallyEqual)
    msgNotEqual: DB "String are completely different",10,0
    lenNotEqual: EQU ($ - msgNoEqual)

	
; Section for uninitialized variables ==========================================
SECTION .bss


; Section for Main =============================================================
SECTION .text

global _start
	_start:
	; Statements
    ; compare string lengths
    mov rax, lenString1
    cmp rax, lenString2
    jle 2ndBigger ;Make jump is second bigger to avoid errors
    
    ; String compare function
    lea rsi, [rel string1]
    lea rdi, [rel string2]
    mov rcx, lenString2
    dec rcx
    cld
    repe cmpsb
    jne notequal
    
    ; Check if any part of strings are equal
    mov rax, lenString1
    cmp rax, lenString2
    jne PartiallyEqual  ;if not equal but similar
    jmp equal
    
2ndBigger: 
    lea rsi, [rel string1]
    lea rdi, [rel string2]
    mov rcx, lenString1
    dec rcx
    cld
    repe cmpsb
    jne notequal
    
    ; Check if any part of strings are equal
    mov rax, lenString1
    cmp rax, lenString2
    jne PartiallyEqual  ;if not equal but similar
    jmp equal
    
PartiallyEqual: ;===============================================================
    mov rsi, msgPartiallyEqual
    mov rdx, lenPartiallyEqual
    jmp print
    jmp done
    
notequal: ;=====================================================================
    mov rsi, msgNotEqual
    mov rdx, lenNotEqual
    jmp print
    jmp done
    
equal: ;========================================================================
    mov rsi, msgEqual
    mov rdx, lenEqual
    jmp print
    
print:; ========================================================================
	mov       rax, 1        ; System call for write
    mov       rdi, 1    
    syscall                 ; Invoke write

exit:; Exit the program ========================================================
	mov rax, 60             ; System call number to exit
	xor rdi, rdi	
	syscall                 ; Invoke exit