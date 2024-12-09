/*
	Made by: Victor Marrujo
	Assignment: Chpt2 PA
	Filename: BubbleSort.c
	Date: Feburary 9th, 2023 (completed on Feburary 15h, 2023 
*/ 

#include <stdio.h>
 //Function Declarations =========================
void swap(int *a, int *b) ;
void BubbleSort(int Array[], int n) ;
// end function declarations =======================


int main() 
{
	 // Local Definitions ==========================
	int Array[] = {93, 52, 72, 42, 3, 63, 100, 19, 61, 44, 21, 98, 6, 41, 78, 5, 51, 60, 67, 11};
    int n = sizeof(Array) / sizeof(Array[0]);
	
	// Statements ==============================

	// State original array
    printf("The original array is: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", Array[i]);
    } // for

	// Sort array
    BubbleSort(Array, n);
	
	// sorted array
    printf("\nThe sorted array is: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", Array[i]);
    } // for
	
	// end of program
	printf("\n\nThis program has ended.\n");
    return 0;
} // main


/* ==========================================================
	Function Name: swap
	Function Description: 
		Swaps a and b values
		
	Inputs: int *a, *b ( Uses pass by reference)
	Outputs: none ( Uses pass by reference)
	Created: Feburary 11th, 2023 
	Updates:
============================================================*/
void swap(int *a, int *b) 
{
	// Local Definitions ==========================
    int temp = *a;
	
	// Statements ==============================
    *a = *b;
    *b = temp;
} // swap

/* ==========================================================
	Function Name: BubbleSort
	Function Description: 
		in-place sorting algorithm that finds max. element in each cycle and puts it 
		in appropriate position in list by performing swapping adjacent elements. 
		In bubble sort, we continue swapping adjacent elements until they are in 
		correct order.
	
	Inputs: int Array[], n
	Outputs: none ( Uses pass by reference)
	Created: Feburary 11th, 2023 
	Updates:
============================================================*/

void BubbleSort(int Array[], int n) 
{
	// Local Definitions ==========================

	// Statements ==============================
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - 1; j++) 
		{
            if (Array[j] > Array[j + 1]) 
			{
                swap(&Array[j], &Array[j + 1]);
            } // if
        }// for j
    }// for i
} // BubbleSort