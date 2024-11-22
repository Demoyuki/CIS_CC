;========================================================================
;	Name: Victor Marrujo
;	Program: myFunctions.asm
;	Description;
;		Part 2 (30 points – 20% of the Final Project)
;		Building on what you did for Part 1, you will need to create an include file called myFunctions.asm that contains all the
;		functions you have used in your program. You may assume that final.asm and myFunctions.asm will be in the same
;		directory.
;==========================================================================
%macro exit 0
    mov rax, 60 ; exit
    xor rdi, rdi ; exit status code
    syscall
 %endmacro

%macro printMsg 2
    mov rax, 1 ; write
    mov rdi, 1 ; stdout
    mov rsi, %1 ; message to display
    mov rdx, %2 ; message length
    syscall
%endmacro

%macro getInput 2
	mov rax, 0 ; read
    mov rdi, 0 ; stdin
    mov rsi, %1 ; input buffer
    mov rdx, %2 ; buffer size
    syscall
%endmacro

%macro addNums 0
    section .data
    prompt db "Enter first number: ", 0
    prompt2 db "Enter second number: ", 0
    result db " + ", 0
    equals db " = ", 0
    newline db 10, 0

    section .text
    global _start
        _start::
            ; Display the prompt for the first number
            mov eax, 4
            mov ebx, 1
            mov ecx, prompt
            mov edx, 18
            int 0x80
    
            ; Get the first number input from the user
            mov eax, 3
            mov ebx, 2
            mov ecx, num1
            mov edx, 4
            int 0x80
    
            ; Display the prompt for the second number
            mov eax, 4
            mov ebx, 1
            mov ecx, prompt2
            mov edx, 19
            int 0x80
    
            ; Get the second number input from the user
            mov eax, 3
            mov ebx, 2
            mov ecx, num2
            mov edx, 4
            int 0x80
    
            ; Compute the sum of the two numbers
            mov eax, [num1]
            add eax, [num2]
            mov [sum], eax
    
            ; Display the result
            mov eax, 4
            mov ebx, 1
            mov ecx, prompt
            mov edx, 18
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, num1
            mov edx, 4
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, result
            mov edx, 3
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, num2
            mov edx, 4
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, equals
            mov edx, 3
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, sum
            mov edx, 4
            int 0x80
    
            mov eax, 4
            mov ebx, 1
            mov ecx, newline
            mov edx, 1
            int 0x80
    
        section .data
            num1: resd 1
            num2: resd 1
            sum: resd 1
%endmacro