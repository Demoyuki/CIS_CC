/*	Description: Write a program that asks the user to enter a list of integers. Determine
		the largest value and how many times it was entered.	
	Filename: p36w-4.c
	Written by: Dan Guilmette
	Date: March 1st, 2023
*/
#include <stdio.h>
#include <limits.h>

// Function Declarations ===========================================
int myFunction();
// end function declarations ========================================

int main (void)
{

	// Local Definitions
	int num = 0;
	int max = INT_MIN;
	int count = 0;
		
	// Statements
	printf("Enter a list of integers (Ctrl-D to end): ");
	while (scanf(" %d", &num) != EOF)
	{
		if (num > max)
		{
			max = num;
			count = 1;
		}// if
		else if (num == max)
		{
			count++;
		}// else if
	}// while
	
	// display maximum number and count
	printf("The maximum integer entered was: %d\n", max);
	printf("This number was entered %d times\n", count);
	
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
