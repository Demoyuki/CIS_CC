; Name: Dan Guilmette
; Assignment: Program 1 (program_1.asm)
; Description: Create a program for NASM that contains the following items:
;	- A message variable that holds the text (preserving line breaks):
;		You already know what the next
;		variable will be, don’t you?
; 	- A length variable that holds the size of the message variable
; 	- A length5 variable (also in the data section) that holds 
; 		the result of adding 5 to length (use EQU)
;	-	A one-operand instruction that adds 1 to the value in the 
; 			length5 variable (think outside the box for this requirement)

; Section for initialized variables
SECTION .data
	message: DB "You already know that the next",0ah		; first line of message variable (ends with line break)
			 DB "variable will be, don't you?",0			; second line of message variable 
	length:  EQU ($ - message)								; variable holding the length of the message variable 	
	; or length: DB ($ - message)
	length5: EQU (length + 5)								; variable assigned using EQU aontaining length + 5
	
; Section for uninitialized variables
SECTION .bss
	
; Section for code
SECTION .text
	global _start

_start:
	mov rax, length5										; move value of length5 variable into register rax 
	inc rax													; increment the value in register rax 
; end of _start

	; properly end execution for 64-bit program
	mov		rax, 60                 						; system call for exit
    xor     rdi, rdi                						; exit code 0
	syscall                         						; invoke operating system to exit