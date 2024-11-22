;========================================================================
;	Name: Victor Marrujo
;	Program: final206Marrujo.asm
;	Description;
;	Part 1 (105 points – 70% of the Final Project)
;		Create a simple menu system that displays the following:
;		Class Menu
;				1. Say Hello
;				2. Add two numbers
;				3. Exit menu
;		Enter your item number:
;
;	● Option 1 should ask the user for their name, display "Hello, NAME", and then redisplay the menu
;	● Option 2 should just display (Work in Progress) and then redisplay the menu
;	● Option 3 should display "Thanks for using our program" and then exit the program
;	● If the user enters something other than a 1, 2, or 3 is entered - display an appropriate error message and
;   redisplay the menu
;
;   Part 3 (30 points – 20% of the Final Project)
;       When the user chooses option 2, ask the user for two numbers (you may assume the numbers will be positive integers),
;       then display a prompt stating that "NUM1 + NUM2 = SUM" and then redisplay the menu. You can break this part of the
;       project into two pieces (you are not required to approach it in this manner):
;       • Add two 1-digit numbers together for a maximum sum of 18 (a 2-digit number). 
;       • Add two 2-digit numbers together for a maximum sum of 198 (a 3-digit number). 
;==========================================================================
%include  "myFunctions.asm"

; Section for initialized variables =================================
section .data
newline: db 10, 0 ; Newline character

menu: db "Class Menu", 0Ah, "1. Say Hello", 0Ah, "2. Add two numbers", 0Ah
lenMenu equ  ($ - menu)

menu2: db "3. Exit menu", 0Ah, "Enter your item number:", 0Ah, 0
lenMenu2 equ  ($ - menu2)

error: db "Invalid input. Please enter 1, 2, or 3.", 0Ah, 0
lenError equ  ($ - error)

name: db "Hello, ", 0

work_in_progress: db "Work in Progress", 0Ah, 0
lenWIP equ ($ - work_in_progress)
  
thanks: db "Thanks for using our program", 0Ah, 0
lenThanks equ ($ - thanks)
   
; Section for uninitialized variables =================================
section .bss
   name_buf: resb 32

section .text
global _start
 
_start:
    ; display a newline character
	printMsg newline, 1
	
    ; display menu
    printMsg menu, lenMenu 
    printMsg menu2, lenMenu2 
    
    ; get user input
    getInput name_buf, 32 
 
    ; check input
    mov bl, byte [name_buf]
    cmp bl, '1'
    je say_hello
    cmp bl, '2'
    je add_numbers
    cmp bl, '3'
    je exit_menu
    jmp invalid_input
 
say_hello:
    ; display "Hello, NAME"
    printMsg name, 7 ;
    printMsg name_buf + 1, 32
    jmp _start
 
add_numbers:
    ; display "Work in Progress"
    printMsg work_in_progress, lenWIP
    addNums
    jmp _start
 
exit_menu:
	    ; display "Thanks for using our program" and exit
    printMsg thanks, lenThanks ; message length
    syscall
	exit
 
invalid_input:
    ; display error message and redisplay menu
    printMsg error, lenError
    jmp _start