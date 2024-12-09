/*
	Made by: Victor Marrujo
	Assignment: Chpt2 PA
	Filename: RecursivePower.c
	Date: Feburary 6th, 2023 (completed on Feburary 8h, 2023 
*/ 

#include <stdio.h>
 //Function Declarations =========================
int power(int base, int exponent) ;
// end function declarations =======================


int main() 
{
	 // Local Definitions ==========================
    int base = 0;
	int exponent = 0;
	
	// Statements ==============================
	
    // Get base
    printf("Enter base: ");
    scanf("%d", &base);
	
	// get exponent
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    // Call the recursive power method and print the result
    int result = power(base, exponent);
    printf("Value is: %d\n", result);

    return 0;
}//main


/* ==========================================================
	Function Name: power
	Function Description: 
		Recursive method to calculate base^exponent, with two outcomes
		+ Outcome A: Base case: when exponent is 1, return base
		+ Outcome B: Recursive step: base^exponent = base * base^(exponent-1)
		
	Inputs: int base, exponent
	Outputs: int result
	Created: Feburary 6th, 2023 
	Updates:
============================================================*/

int power(int base, int exponent) 
{
	// Local Definitions ==========================
	int result = 0;
	
	// Statements ==============================
    if (exponent == 1)   // Outcome A
	{
		result = base;
        return result;
    } // if
		else  				// Outcome B
		{
			result = base * power(base, exponent - 1);
			return result;
		} // else
} // power