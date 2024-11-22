;===============================================================================
;   Name: Victor Marrujo
;   Program: Hw5Marrujo.asm
;   Description: program that defines a 3-element array named myArray that will 
;       contain the following values in order: 2, 3, and 4. 
;	Will add using a loop - the number of elements will be stored in a memory 
;   variable named numElements, and total in a memory variable named sum. 
;	There is no requirement for displaying a result
;===============================================================================


; Section for uninitialized variables ==========================================
SECTION .data	
myArray DB 2, 3, 4	; Initializing variables from description:
numElements: DQ 3		
sum: DQ 0					

; Section for uninitialized variables ==========================================
SECTION .bss


; Section for Main =============================================================
SECTION .text
global _start
	_start: 			
	; Loop that adds variables
	mov rcx, qword [numElements]    ; Move data in numElements to rcx
	mov rax, 0                      ; Array counter

myLoop:; =======================================================================
	movsx rdx, byte [myArray + rax]	; Move element of the array to rdx
	add [sum], rdx					; Add rdx to sum
	inc rax							; moves to next num in myArray
	loop myLoop						; Here we go again
	
exit:; Exit the program ========================================================
	mov rax, 60             ; System call number to exit
	xor rdi, rdi	
	syscall                 ; Invoke exit