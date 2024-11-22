;===============================================================================
;   Name: Victor Marrujo
;   Program: Hw6Marrujo.asm
;   Description: 
;    Write a modified Sum program that passes eight (8) integer parameters to a 
;       sum function according to the x86_64 calling convention. Doing so will 
;       require you to use parameter registers and the stack to pass all the 
;       parameters. 
;   Refer to the x86_64 calling convention rules and the x86 versions of 
;       Program 6.1 on GitHub for guidance. Add the values using any approach 
;       you wish and return the value.
;===============================================================================
		

; Section for uninitialized variables ==========================================
SECTION .data	
int1: dq 1
int2: dq 2
int3: dq 3
int4: dq 4
int5: dq 5
int6: dq 6
int7: dq 7
int8: dq 8

; Section for uninitialized variables ==========================================
SECTION .bss


; Section for Main =============================================================
SECTION .text

global _start, _sum ;Initializing Function
_start: 
	
	; Push variables 1-7, entered backwards because its read first in last out
	push qword [int7]
	push qword [int6]
	push qword [int5]
	push qword [int4]
	push qword [int3]
	push qword [int2]
	push qword [int1]

	; One variable in a register since its required for the program
	mov rdi, qword [int8]
	
	; Call Function
	call _sum

exit:; =========================================================================
	mov rax, 60		; System call for exit
	xor rdi, rdi	; Return value
	syscall			; Invoke exit
	
_sum:; =========================================================================
	push rbp		; Holds stack frame
	mov rbp, rsp 	; rbp = top of stack frame
	add rbp, 8		; Increments by 8 bytes, dont really understand why,
                    ;       but Roy said this would make it work and it did.
	mov rcx, 7		; Control variable = variables not in registers
	mov r9, 1		; Increments top of stack
	
sumLoop:; ======================================================================
	add rax, [rbp + (8 * r9)]	; Adds next variable in queue
	inc r9						; Control variable
	loop sumLoop				; Decrement rcx and loop
	add rax, rdi				; add int8
	pop rbp						; Pop rbp, then goes to line after this was called
	ret 						; Return