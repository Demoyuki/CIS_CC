;===============================================================================
;   Name: Victor Marrujo
;   Program: prog5Marrujo.asm
;   Description:
;       Write a program using the appropriate string primitive instructions that 
;       iterates through the string "I DON'T KNOW WHAT WE'RE YELLING ABOUT!" and 
;       converts each character to its convert counterpart and stores the 
;       resulting string in another location. In addition:
;
;   o Do not modify non-character element.
;   o Keep a count of the number of characters you actually change from upper 
;       case to lower case and store the final count into a memory variable 
;       named numChars
;===============================================================================


; Section for initializing variables============================================
SECTION .data   
	string1: 	db 	"I DON'T KNOW WHAT WE'RE YELLING ABOUT!", 0	
	lenString1	equ  ($ - string1) 	

; Section for uninitializing variables==========================================
SECTION .bss 
    convertedString:  resb lenString1 + 1
    numChars		  resb 1

; Section for Main =============================================================
SECTION .text 

	global _start
_start:
	; Statements
	mov rcx, lenString1		    ; Loop variable
	mov rbx, string1		    ; load array
	mov rdi, convertedString   	; load array

convertLoop:; ==================================================================
	mov al, byte [rbx]
	cmp al, 'A'     ; Check if character is uppercase
	jl convert		
	cmp al, 'Z'
	jg convert	
	add al, 32      ; 32 converts to lowercase
	inc r8          ; numChars++

convert:; ======================================================================	
    mov byte [rdi], al		; Copy characters to convertedString
	add rbx, 1         		; move to next array element
	add rdi, 1         		; move to next array element
	loop convertLoop		; Decrement loop counter

	mov [numChars], r8      ; numChars = r8	
	
printInitial:; =================================================================
	mov rax, 1              ; System call for write
	mov rdi, 1
	mov rsi, string1
	mov rdx, lenString1
	syscall                 ; Invoke write

printConverted:; ===============================================================
	mov rax, 1                  ; System call for write
	mov rdi, 1
	mov rsi, convertedString
	mov rdx, lenString1
	syscall                     ; Invoke write

exit:; Exit the program ========================================================
	mov rax, 60             ; System call number to exit
	xor rdi, rdi	
	syscall                 ; Invoke exit