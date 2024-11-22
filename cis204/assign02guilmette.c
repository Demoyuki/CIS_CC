/*	Write a program that prompts the user to enter three numbers and then
	  prints them vertically (each on one line), first forward and then 
	  reversed (the last one first).
	File Name: assign02guilmette.c
	Written by:	Dan Guilmette
	Date: January 25th, 2023
*/

#include <stdio.h>

int main(void)
{
	// Local Definitions
	int first = 0;
	int second = 0;
	int third = 0;
	
	// Statements ================
	
	// Display program prompts
	printf("This program will ask for three numbers, and then\n");
	printf("display in the order you entered them, and then in reverse order\n");
	
	// Get three numbers from the user
	printf("\nEnter three numbers: ");
	scanf(" %d %d %d", &first, &second, &third);
	
	// display the numbers as entered (forward)
	printf("Your numbers forward:\n");
	printf("   %d\n", first);
	printf("   %d\n", second);
	printf("   %d\n", third);
	// display the numbers in reverse order
	printf("Your numbers reversed:\n");
	printf("   %d\n", third);
	printf("   %d\n", second);
	printf("   %d\n", first);
	
	// End the program
	printf("\nThis ends our program.\n");
	
	return 0;
}