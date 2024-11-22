 ;Name: Dan Guilmette
; Assignment: Program 5 (program5.asm)
; Description: Write a program using the appropriate string primitive instructions that iterates through 
;	the string "I DON'T KNOW WHAT WE'RE YELLING ABOUT!" and converts each character to its lowercase 
;	counterpart and stores the resulting string in another location. In addition:
;		Do not modify non-character elements (such as the single quote and the exclamation point).
;		Keep a count of the number of characters you actually change from upper case to lower case 
;			and store the final count into a memory variable named numChars.
:
;	NOTE: this solution does a couple of things the assignemnt did not ask for - in particular, there 
;		is no requirement to display either string or the value of numChars (which is the number of 
;		modified characters from the string. I added these and the use of a function as a "kick start"
;		as you work on your Final Program.
;

; Section for initialized variables
SECTION .data
s1:			DB "I DON'T KNOW WHAT WE'RE YELLING ABOUT!",0
lenS1:		EQU ($ - s1)
numChars:	DD 0
newline:    DB 10, 0 ; Newline character
originalMsg DB "Original String: ",0
lenOriginalMsg EQU ($ - originalMsg)
modifiedMsg DB "Modified String: ",0
lenModifiedMsg EQU ($ - modifiedMsg)
countMsg DB "Number of changed characters: ",0
lenCountMsg EQU ($ - countMsg)

; Section for uninitialized variables
SECTION .bss
s2:		RESB lenS1
lenS2:	EQU ($ - s2)
digitSpace resb 100
digitSpacePos resb 8

; Section for code
SECTION .text
global _start
_start:

	cld
	mov rcx, lenS1
	lea rsi, [s1]
	lea rdi, [s2]
	xor rax, rax

top:
	lodsb
	cmp rax, 65
	jl skip
	cmp rax, 90
	jg skip
	inc dword [numChars]
	or eax, 32
skip:
	cmp rcx, 0
	je display
	stosb
	loop top

display:
	; display the original string message
	mov rax, 1
	mov rdi, 1
	mov rsi, originalMsg
	mov rdx, lenOriginalMsg
	syscall
	
	; display the original string
	mov rax, 1
	mov rdi, 1
	mov rsi, s1
	mov rdx, lenS1
	syscall
	
	; display a newline character
	mov rax, 1
	mov rdi, 1
	mov rsi, newline
	mov rdx, 1
	syscall
	
	; display the modified string message
	mov rax, 1
	mov rdi, 1
	mov rsi, modifiedMsg
	mov rdx, lenModifiedMsg
	syscall
	
	; display the modified string
	mov rax, 1
	mov rdi, 1
	mov rsi, s2
	mov rdx, lenS2
	syscall
	
	; display a newline character
	mov rax, 1
	mov rdi, 1
	mov rsi, newline
	mov rdx, 1
	syscall

	; display the count message
	mov rax, 1
	mov rdi, 1
	mov rsi, countMsg
	mov rdx, lenCountMsg
	syscall
	
	; display numChars
	xor rax, rax
	mov eax, [numChars]
	call _printRAX
		
	; display a newline character
	mov rax, 1
	mov rdi, 1
	mov rsi, newline
	mov rdx, 1
	syscall

done:
	; properly end execution for 64-bit program
	mov		rax, 60                 ; system call for exit
	xor     rdi, rdi                ; exit code 0
	syscall                         ; invoke operating system to exit

;==================================================================
;Function: _printRAX
;Inputs: integer should be in register RAX
;Outputs: display the integer in the RAX register
; based on code from:
;   https://www.youtube.com/playlist?list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn
;==================================================================

_printRAX:
    mov rcx, digitSpace
    mov [digitSpacePos], rcx
 
_printRAXLoop:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48
 
    mov rcx, [digitSpacePos]
    mov [rcx], dl
    inc rcx
    mov [digitSpacePos], rcx
    
    pop rax
    cmp rax, 0
    jne _printRAXLoop
 
_printRAXLoop2:
    mov rcx, [digitSpacePos]
 
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
 
    mov rcx, [digitSpacePos]
    dec rcx
    mov [digitSpacePos], rcx
 
    cmp rcx, digitSpace
    jge _printRAXLoop2
 
    ret
	
