/*	A class has four assessments worth equal value. The class has 3 students. 
		This program will read in the students’ initials, ID numbers, assessment scores, 
		highest scores, and lowest scores. it will then calculate each student's 
		average, and then print out the input data and average for each student in a 
		formatted output that is clear to read. There must be functions to get the data, 
		to calculate the average, and to display the data.
	File Name: project04guilmette.c
	Written by:	Dan Guilmette
	Date: February 13th, 2023
*/
#include <stdio.h>
#include <math.h>

// Function Declarations ===========================================
void getData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1, int* pTest2, 
			int* pTest3, int* pTest4, float* pHigh, float* pLow);
float calcAverage(int test1, int test2, int test3, int test4, float numTests);
void displayStudentInfo(char lastName, char firstName, int id, int test1, int test2, 
						int test3, int test4, float high, float low, float average);
// end function declarations ========================================

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
	float firstHigh = 0.0;
	float firstLow = 0.0;
	float firstAve = 0.0;
	// second student
	char lastName2 = ' ';
	char firstName2 = ' ';
	int id2 = 0;
	int test2_1 = 0;
	int test2_2 = 0;
	int test2_3 = 0;
	int test2_4 = 0;
	float secondHigh = 0.0;
	float secondLow = 0.0;
	float secondAve = 0.0;
	// third student
	char lastName3 = ' ';
	char firstName3 = ' ';
	int id3 = 0;
	int test3_1 = 0;
	int test3_2 = 0;
	int test3_3 = 0;
	int test3_4 = 0;
	float thirdHigh = 0.0;
	float thirdLow = 0.0;
	float thirdAve = 0.0;
	// number of tests
	float  numTests = 4.0;
	
	// Statements ================
	
	// Display program prompts
	printf("Welcome to the student report\n");
	// Prompt and get the first student's data
	getData(&lastName1, &firstName1, &id1, &test1_1, &test1_2, &test1_3, &test1_4, 
			&firstHigh, &firstLow);
	// Prompt and get the second student's data
	getData(&lastName2, &firstName2, &id2, &test2_1, &test2_2, &test2_3, &test2_4, 
			&secondHigh, &secondLow);
	// Prompt and get the third student's data
	getData(&lastName3, &firstName3, &id3, &test3_1, &test3_2, &test3_3, &test3_4, 
			&thirdHigh, &thirdLow);

	// Calcluate the first student's average
	firstAve = calcAverage(test1_1, test1_2, test1_3, test1_4, numTests);
	// Calcluate the second student's average
	secondAve = calcAverage(test2_1, test2_2, test2_3, test2_4, numTests);
	// Calcluate the second student's average
	thirdAve = calcAverage(test3_1, test3_2, test3_3, test3_4, numTests);

	// Display Report Header
	printf ("Last   First   ID   Test1   Test2   Test3   Test4   High   Low   Ave\n");
	
	// Display the first student's data
	displayStudentInfo(lastName1, firstName1, id1, test1_1, test1_2, test1_3, test1_4, 
						firstHigh, firstLow, firstAve);
	// Display the second student's data
	displayStudentInfo(lastName2, firstName2, id2, test2_1, test2_2, test2_3, test2_4, 
						secondHigh, secondLow, secondAve);
	// Display the third student's data
	displayStudentInfo(lastName3, firstName3, id3, test3_1, test3_2, test3_3, test3_4, 
						thirdHigh, thirdLow, thirdAve);
	
	// End the program
	printf("\nThis ends our program.\n");
	
	return 0;
}

/* =================================================================================
	Function Name: getData
	Function Description: Asks the user for the required data
	Inputs: none
	Outputs: none - uses parameter passing
	Date: February 13th, 2023
====================================================================================*/
void getData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1, int* pTest2, 
			int* pTest3, int* pTest4, float* pHigh, float* pLow)
{
	printf("Please enter the next student's data all on one line in the sequence\n");
	scanf(" %c,%c,%d,%d,%d,%d,%d,%f,%f", pLastName1, pFirstName1, pId1, pTest1, pTest2, pTest3, 
		pTest4, pHigh, pLow);

	return;
}// getData

/* =================================================================================
	Function Name: calcAverage
	Function Description: calculates the average test score for a student
	Inputs: all four student test scores, the number of tests
	Outputs: returns the average of the submitted scores
	Date: February 13th, 2023
====================================================================================*/
float calcAverage(int test1, int test2, int test3, int test4, float numTests)
{
	float tempAverage = 0.0;
	tempAverage = (test1 + test2 + test3 + test4) / numTests;
	tempAverage = roundf(tempAverage*10)/10.0;

	return tempAverage;
}// calcAverage

/* =================================================================================
	Function Name: displayStudentInfo
	Function Description: displays the information for one student
	Inputs: last and first name, all four test scores, high, low, and average score
	Outputs: none - displays the information
	Date: February 13th, 2023
====================================================================================*/
void displayStudentInfo(char lastName, char firstName, int id, int test1, int test2, int test3, 
						int test4, float high, float low, float average)
{
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f\n", lastName, firstName, id, test1, test2, test3, 
			test4, high, low, average);

	return;
}// displayStudentInfo

