;===============================================================================
;   Name: Victor Marrujo
;   Program: Hw7Marrujo.asm
;   Description: 
;    Get a single character from the user through the keyboard
;        Depending on what the user types:
;        If the user types 'y' or 'Y,' display the message "You typed a Y"
;        If the user types 'n' or 'N,' display the message "You typed an N"
;        If the user types anything else, display the message "Invalid input"
;        You may assume single character, followed by the Enter key.
;===============================================================================

; NOTE TO SELF: rax, rbx, rcx, ... DONT WORK IN 32-BIT MODE

; Section for uninitialized variables ==========================================
section .data	
	userInput      db "Please enter a character ('Y' or 'y' or 'N' or 'n'): ", 0
	userInput_Len   equ ($-userInput)
	msg_Y   	    db 10, "You typed Y", 10, 10			
	msg_N   	    db 10, "You typed N", 10, 10
    msgYN_Len 	    equ ($-msg_Y) ; msg_Y and msg_N have same length
	msg_invalid     db 10, "Invalid input", 10, 10
	msg_invalidLen 	equ ($-msg_invalid)

; Section for uninitialized variables ==========================================    
section .bss
	input resb 1

; Section for Main =============================================================    
section .text
	global _start

_start:
; Prompt user for input  =======================================================    
	mov eax, 4
	mov ebx, 1
	mov ecx, userInput
	mov edx, userInput_Len
 	int 0x80	            ; System call 32-bit
    
; Read user input   ============================================================
	mov eax, 3
	mov ebx, 0
	mov ecx, input
	mov edx, 1
 	int 0x80	            ; System call 32-bit
    
	; Check input
	mov al, [input]
	
;If 'y' or 'Y'   ===============================================================
	cmp al, 'Y'
	je is_Y
	cmp al, 'y'
	je is_Y
	
;If 'n' or 'N'   ===============================================================
	cmp al, 'N'
	je is_N
	cmp al, 'n'
	je is_N
    
is_Invalid:; ===================================================================
	mov eax, 4
	mov ebx, 1
	mov ecx, msg_invalid
	mov edx, msg_invalidLen
	int 0x80	            ; System call 32-bit
	jmp exit
    
is_Y:; =========================================================================
	; y input
	mov eax, 4
	mov ebx, 1
	mov ecx, msg_Y
	mov edx, msgYN_Len
 	int 0x80	            ; System call 32-bit
 	jmp exit	
    
is_N:; =========================================================================
	; N input
	mov eax, 4
	mov ebx, 1
	mov ecx, msg_N
	mov edx, msgYN_Len
    int 0x80	            ; System call 32-bit

exit:; =========================================================================
	mov eax, 1
	xor ebx, 0
	int 0x80				; System call 32-bit