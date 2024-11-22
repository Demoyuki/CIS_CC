; Evan Grubbs 
; Assignment: program5.asm
; Description: Program that takes string and converts all uppercase letters 
;				to lowercase and keeps track of conversions.

; Section for variable definitions
SECTION .data   

	str1: 		db 	"I DON'T KNOW WHAT WE'RE YELLING ABOUT!", 10, 0		; Original string
	lenStr		equ  ($ - str1) 	
	numChars 	dw 0

; Section for uninitialized variables
SECTION .bss   

	str2:  		resb lenStr + 1                						; New string 

; Section for instructions/code
SECTION .text                     
	global _start

_start:
	
	mov rcx, lenStr		; Set counter variable
	mov rbx, str1		; load address of array
	mov rdi, str2   	; load address of array

_loop:
	mov al, byte [rbx]

; Check if character is an uppercase letter
	cmp al, 'A'
	jl _next		; if less than 65
	cmp al, 'Z'
	jg _next		; if greater than 90
	
; Convert uppercase letter to lowercase
	add al, 32

; Count converted characters
	inc r8

_next:	
		
    mov byte [rdi], al		; Copy characters to str2
	add rbx, 1      		; move to next array element
	add rdi, 1      		; move to next array element
	loop _loop				; Decrement loop counter


; Print the original string
	mov rax, 1
	mov rdi, 1
	mov rsi, str1
	mov rdx, lenStr
	syscall

; Print the converted string 
	mov rax, 1
	mov rdi, 1
	mov rsi, str2
	mov rdx, lenStr
	syscall

	
; Move count to numChars
	mov [numChars], r8	
	

; properly end execution for 64-bit program
	mov rax, 60		;system call for exit
	xor	rdi,rdi		;exit code 0
	syscall			;invoke operating system to exit


;	nasm -f elf64 -F dwarf program5.asm && ld program5.o -o program5
;	./program5
;	gdb program5
;	set disassembly-flavor intel
;	layout regs
