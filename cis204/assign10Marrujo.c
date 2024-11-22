/* ||=========================================================================||
   ||+This program will sort an array containing (26, 14, 57, 33,  41)        ||
   ||   into ascending and descending order and print the sorted lists.       ||
   ||                                                                         ||
   ||+It must not change the original array or create any other integer arrays||
   ||                                                                         ||
   ||+Requires two pointer arrays, as shown in, were the first pointer array  ||
   ||   is rearranged so that it points to the data in ascending sequence.    ||    
   ||   The second pointer array is rearranged so that it points to the data  ||
   ||   in descending sequence. (I did this all using one pointer and         ||
   ||   some arithmetic :D).                                                  ||
   ||                                                                         ||
   ||+Your output should be formatted with the three arrays printed as a      ||
   ||   vertical list next to each other, for example:                        ||
   ||   Ascending Original Descending									      ||
   ||   14          26          57										      ||
   ||   26          14          41 										      ||
   ||   33          57          33 										      ||
   ||   41          33          26 										      ||
   ||   57          41          14										      ||
   ||=========================================================================||
   ||	Filename: assign10Marrujo.c 									      ||
   ||	Written by: Victor Marrujo											  ||
   ||	Date: 10 April 2023 - 19 April 2023								      ||
   ||=========================================================================||
*/

#include <stdio.h>
#include <stdlib.h> // for malloc

// Function Declarations    ====================================================
void sortAscending(int** arrPtr, int size);
void sortDescending(int** arrPtr, int size);
void printArray(int** arrPtr, int* arr, int size);
// End function declarations    ================================================


// Start of main ===============================================================
int main(void)
{
    // Local Definitions =======================================================
        int arr[] = { 26, 14, 57, 33, 41 };
        int* arrCopy = malloc(5 * sizeof(int)); // make a copy of the array
        int* arrPtr[5];
        int i;
        
    // Statements ==============================================================
        for (i = 0; i < 5; i++) 
        {
            *(arrPtr + i) = arrCopy + i; // pointer array now points at copy
            *(arrCopy + i) = *(arr + i); // copy data of original to copy
        }//for i
    
    // Sorts array and prints ==================================================
        sortAscending(arrPtr, 5);
        sortDescending(arrPtr, 5);
        printArray(arrPtr, arr, 5);
    
    // End of program ==========================================================
		printf("\nThe program has successfully ended\n");
	
    return 0;
}// End of main ================================================================

/*  
   ||=========================================================================||
   ||	Function Name: sortAscending    						              ||
   ||=========================================================================||
   ||	Function Description:							  					  ||
   ||		o Takes a pointer to a pointer array and its size as parameters.  ||
   ||       o It uses pointer arithmetic to sort the array in ascending       ||
   ||           order.                                                        ||
   ||=========================================================================||
   ||	Outputs: 															  ||
   ||       o returns void; uses pointers sort the array in ascending order.  ||
   ||=========================================================================||
   ||	Date: 10 April 2023 - 16 April 2023								      ||
   ||=========================================================================||
*/
void sortAscending(int** arrPtr, int size) 
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++) 
    {
        for (j = i + 1; j < size; j++) 
        {
            if (**(arrPtr + i) > **(arrPtr + j)) 
            {
                temp = **(arrPtr + i);
                **(arrPtr + i) = **(arrPtr + j);
                **(arrPtr + j) = temp;
            }//if
        }//for j
    }//for i
}//sortAscending

/*  
   ||=========================================================================||
   ||	Function Name: sortDescending    						              ||
   ||=========================================================================||
   ||	Function Description:							  					  ||
   ||		o Takes a pointer to a pointer array and its size as parameters.  ||
   ||       o It uses pointer arithmetic to sort the array in descending      ||
   ||           order.                                                        ||
   ||=========================================================================||
   ||	Outputs: 															  ||
   ||       o returns void; uses pointers sort the array in descending order. ||
   ||=========================================================================||
   ||	Date: 10 April 2023 - 17 April 2023								      ||
   ||=========================================================================||
*/
void sortDescending(int** arrPtr, int size) 
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++) 
    {
        for (j = i + 1; j < size; j++) 
        {
            if (**(arrPtr + i) < **(arrPtr + j)) 
            {
                temp = **(arrPtr + i);
                **(arrPtr + i) = **(arrPtr + j);
                **(arrPtr + j) = temp;
            }//if
        }//for j
    }//for i
}//sortDescending

/*  
   ||=========================================================================||
   ||	Function Name: printArray	    						              ||
   ||=========================================================================||
   ||	Function Description:							  					  ||
   ||		o  Takes a pointer to a pointer array, the original array, and    ||
   ||           its size as parameters to print the sorted arrays in          ||
   ||           ascending and descending order alongside the original array.  ||
   ||                                                                         ||
   ||=========================================================================||
   ||	Outputs: 															  ||
   ||       o returns void; prints pointers data                        	  ||
   ||=========================================================================||
   ||	Date: 10 April 2023 - 19 April 2023								      ||
   ||=========================================================================||
*/
void printArray(int** arrPtr, int* arr, int size) 
{
    int i;
    printf("Ascending\tOriginal\tDescending\n");
    for (i = 0; i < size; i++) 
    {
        printf("%d\t\t%d\t\t%d\n", **(arrPtr + i), *(arr + i), **(arrPtr + 4 - i));
    }//for i
}//printArray
