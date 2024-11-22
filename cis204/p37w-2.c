/*	Description: Write a program to create the following pattern:
		1 2 3 4 5 6 7 8 9
		1 2 3 4 5 6 7 8
		1 2 3 4 5 6 7
		1 2 3 4 5 6
		1 2 3 4 5
		1 2 3 4
		1 2 3
		1 2
		1
	Filename: p37w-2.c
	Written by: Dan Guilmette
	Date: March 1st, 2023
*/
#include <stdio.h>


// Function Declarations ===========================================
int myFunction();
// end function declarations ========================================

int main (void)
{

	// Local Definitions
		
	// Statements
	for(int numLines = 9; numLines >=1; numLines--)
	{
		for(int numStars = 1; numStars <= numLines; numStars++)
		{
			printf("%d ", numStars);
		}// for-2
		printf("\n");
	}// for-1
	
	// end program
	printf("This ends the program.\n");
	
	return 0;
} // end of main

/* =================================================================================
	Function Name:
	Function Description: 
		Indented after the first line
	Inputs: 
	Outputs:
	Date: Date you started writing it - may add date completed line (optional)
====================================================================================*/
int myFunction()
{
	return 0;
}// myFunction
