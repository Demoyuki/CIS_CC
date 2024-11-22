/* =============================================================================
   ||   This program prompts the user to enter a character, an integer,       ||
   ||       a long integer, and a floating-point number.                      ||
   ||                                                                         ||
   ||   The program then calls a print function that accepts a void pointer as||
   ||       its only parameter and prints the address of the pointer followed ||
   ||       by the data, first as a character, then as an integer, a long     ||
   ||       integer,and a floating-point number.                              ||
   ||                                                                         ||																			||
   ||=========================================================================||
   ||	Filename: assign09Marrujo.c 									      ||
   ||	Written by: Victor Marrujo											  ||
   ||	Date: 05 April 2023 - 11 April 2023								      ||
   ===========================================================================||
*/
#include <stdio.h>

// Function Declarations    ====================================================
void print(void *pointer); 
// End function declarations    ================================================


// Start of main ===============================================================
int main(void)
{
    // Local Definitions =======================================================
        char c = ' ';
        int i = 0;
        long l = 0;
        float f = 0.00;
        
    // Statements ==============================================================
        printf("Enter a character: ");
        scanf("%c", &c);
        print(&c);
        
        printf("\nEnter an integer: ");
        scanf("%d", &i);
        print(&i);
        
        printf("\nEnter a long integer: ");
        scanf("%ld", &l);
        print(&l);
        
        printf("\nEnter a floating-point number: ");
        scanf("%f", &f);
        print(&f);
        
    // End of program
		printf("\nThe program has successfully ended\n");
	
	return 0;
}

/*  
   ||=========================================================================||
   ||	Function Name: print									              ||
   ||=========================================================================||
   ||	Function Description:							  					  ||
   ||		o Accepts a void pointer and prints the address of the pointer    ||
   ||           followed by the data, first as a character, then as an        ||
   ||           integer, a long integer, and a floating-point number. 		  ||
   ||=========================================================================||
   ||	Inputs: 															  ||
   ||		o void pointer	   	   								 	 		  ||
   ||=========================================================================||
   ||	Outputs: 															  ||
   ||       o returns void; prints void pointer as different data types		  ||
   ||=========================================================================||
   ||	Date: 05 April 2023 - 11 April 2023								      ||
   ||=========================================================================||
*/
void print(void *pointer) 
{
  printf("Printing data at location: %p\n", pointer);
  printf("Data as char: %c\n", *(char*)pointer);
  printf("Data as int: %d\n", *(int*)pointer);
  printf("Data as long: %ld\n", *(long*)pointer);
  printf("Data as float: %f\n", *(float*)pointer);
  return;
}//print
