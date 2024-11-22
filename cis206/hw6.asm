; Name: Dan Guilmette
; Assignment: Homework 6 (hw6.asm)
; Description: Using Program 6.1 as a starting point, write a modified Sum program that passes 
;	eight (8) integer parameters to a sum function according to the x86_64 calling convention. 
;	Doing so will require you to use parameter registers and the stack to pass all the parameters. 
;	Refer to the x86_64 calling convention rules and the x86 versions of Program 6.1 on GitHub for 
;	guidance. Add the values using any approach you wish and return the value.

; Section for initialized variables
section .data
	num1: dq 2
	num2: dq 4
	num3: dq 6
	num4: dq 8
	num5: dq 10
	num6: dq 12
	num7: dq 14
	num8: dq 16

; Section for uninitialized variables
SECTION .bss

; Section for code
section .text
	global _start, _sum
	
_start:
	mov rdi, [num1]
	mov rsi, [num2]
	mov rdx, [num3]
	mov rcx, [num4]
	mov r8,  [num5]
	mov r9,  [num6]
	push QWORD [num8]
	push QWORD [num7]
	call _sum
	add rsp, 16

	; properly end execution for 64-bit program
	mov		rax, 60                 ; system call for exit
	xor     rdi, rdi                ; exit code 0
	syscall                         ; invoke operating system to exit

_sum:
	push rbp
	mov rbp, rsp

	xor rax, rax
	add rax, rdi
	add rax, rsi
	add rax, rdx
	add rax, rcx
	add rax, r8
	add rax, r9
	add rax, [rbp + 16]
	add rax, [rbp + 24]

	pop rbp
	ret
