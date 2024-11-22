/*	A class has four assessments worth equal value. The class has 3 students. 
		This program will read in the students’ initials, ID numbers, assessment scores, 
		highest scores, lowest scores, and average scores, and will print out the result 
		in a formatted output that is clear to read.
	File Name: project02guilmette.c
	Written by:	Dan Guilmette
	Date: January 25th, 2023
*/

#include <stdio.h>

int main(void)
{
	// Local Definitions ==============
	// first student
	char lastName1 = ' ';
	char firstName1 = ' ';
	int id1 = 0;
	int test1_1 = 0;
	int test1_2 = 0;
	int test1_3 = 0;
	int test1_4 = 0;
	float firstHigh = 0;
	float firstLow = 0;
	float firstAve = 0.0;
	// second student
	char lastName2 = ' ';
	char firstName2 = ' ';
	int id2 = 0;
	int test2_1 = 0;
	int test2_2 = 0;
	int test2_3 = 0;
	int test2_4 = 0;
	float secondHigh = 0;
	float secondLow = 0;
	float secondAve = 0.0;
	// third student
	char lastName3 = ' ';
	char firstName3 = ' ';
	int id3 = 0;
	int test3_1 = 0;
	int test3_2 = 0;
	int test3_3 = 0;
	int test3_4 = 0;
	float thirdHigh = 0;
	float thirdLow = 0;
	float thirdAve = 0.0;
	
	// Statements ================
	
	// Display program prompts
	printf("Welcome to the student report\n");
	// Prompt and get the first student's data
	printf("Please enter the first student's data all on one line in the sequence\n");
	scanf(" %c,%c,%d,%d,%d,%d,%d,%f,%f,%f", &lastName1, &firstName1, &id1, 
		&test1_1, &test1_2, &test1_3, &test1_4, &firstHigh, &firstLow, &firstAve);
	// Prompt and get the second student's data
	printf("Please enter the second student's data all on one line in the sequence\n");
	scanf(" %c,%c,%d,%d,%d,%d,%d,%f,%f,%f", &lastName2, &firstName2, &id2, 
		&test2_1, &test2_2, &test2_3, &test2_4, &secondHigh, &secondLow, &secondAve);
	// Prompt and get the third student's data
	printf("Please enter the second student's data all on one line in the sequence\n");
	scanf(" %c,%c,%d,%d,%d,%d,%d,%f,%f,%f", &lastName3, &firstName3, &id3, 
		&test3_1, &test3_2, &test3_3, &test3_4, &thirdHigh, &thirdLow, &thirdAve);


	
	// Display Report Header
	printf ("Last   First   ID   Test1   Test2   Test3   Test4   High   Low   Ave\n");
	
	// Display the first student's data
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f\n", lastName1, firstName1, id1, test1_1, 
		test1_2, test1_3, test1_4, firstHigh, firstLow, firstAve);
	// Display the second student's data
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f\n", lastName2, firstName2, id2, test2_1, 
		test2_2, test2_3, test2_4, secondHigh, secondLow, secondAve);
	// Display the third student's data
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f\n", lastName3, firstName3, id3, test3_1, 
		test3_2, test3_3, test3_4, thirdHigh, thirdLow, thirdAve);

	
	// End the program
	printf("\nThis ends our program.\n");
	
	return 0;
}