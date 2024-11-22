/*	A class has four assessments worth equal value. The class has 3 students. 
		This program will read in the students’ initials, ID numbers, assessment scores, 
		highest scores, and lowest scores. it will then calculate each student's 
		average, and then print out the input data and average for each student in a 
		formatted output that is clear to read. There must be functions to get the data, 
		to calculate the average, and to display the data.
	File Name: project06guilmette.c
	Written by:	Dan Guilmette
	Date: February 27th, 2023
*/
#include <stdio.h>
#include <math.h>

// Function Declarations ===========================================
void getData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1, int* pTest2, 
			int* pTest3, int* pTest4, float* pHigh, float* pLow);
float calcAverage(int test1, int test2, int test3, int test4, float numTests);
void displayStudentInfo(char lastName, char firstName, int id, int test1, int test2, 
						int test3, int test4, float high, float low, float average, char letterGrade);
char calcLetterGrade(float average);
int displayMenu(void);
void getAllData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1_1, int* pTest1_2, int* pTest1_3, int* pTest1_4, 
				float* FirstHigh, float* FirstLow, char* pLastName2, char* pFirstName2, int* pId2, int* pTest2_1, int* pTest2_2, 
				int* pTest2_3, int* pTest2_4, float* SecondHigh, float* SecondLow, char* pLastName3, char* pFirstName3, 
				int* pId3, int* pTest3_1, int* pTest3_2, int* pTest3_3, int* pTest3_4, float* ThirdHigh, float* ThirdLow);
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
	char letterGrade1 = ' ';
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
	char letterGrade2 = ' ';
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
	char letterGrade3 = ' ';
	// number of tests
	float  numTests = 4.0;
	int result = 0;
	
	// Statements ================
	
	// Display program prompts
	printf("\nWelcome to the student report\n");
	do
	{
		result = displayMenu();
		if (result ==1)
		{
			// call report
			// Calcluate the first student's average & letter grade
			firstAve = calcAverage(test1_1, test1_2, test1_3, test1_4, numTests);
			letterGrade1 = calcLetterGrade(firstAve);
			// Calcluate the second student's average & letter grade
			secondAve = calcAverage(test2_1, test2_2, test2_3, test2_4, numTests);
			letterGrade2 = calcLetterGrade(secondAve);
			// Calcluate the third student's average & letter grade
			thirdAve = calcAverage(test3_1, test3_2, test3_3, test3_4, numTests);
			letterGrade3 = calcLetterGrade(thirdAve);

			// Display Report Header
			printf ("Last   First   ID   Test1   Test2   Test3   Test4   High   Low   Ave   Grade\n");
			
			// Display the first student's data
			displayStudentInfo(lastName1, firstName1, id1, test1_1, test1_2, test1_3, test1_4, 
								firstHigh, firstLow, firstAve, letterGrade1);
			// Display the second student's data
			displayStudentInfo(lastName2, firstName2, id2, test2_1, test2_2, test2_3, test2_4, 
								secondHigh, secondLow, secondAve, letterGrade2);
			// Display the third student's data
			displayStudentInfo(lastName3, firstName3, id3, test3_1, test3_2, test3_3, test3_4, 
								thirdHigh, thirdLow, thirdAve, letterGrade3);
		}// if
		else if (result == 2)
		{
			// add students
			getAllData(&lastName1, &firstName1, &id1, &test1_1, &test1_2, &test1_3, &test1_4, 
				&firstHigh, &firstLow, &lastName2, &firstName2, &id2, &test2_1, &test2_2, &test2_3, 
				&test2_4, &secondHigh, &secondLow, &lastName3, &firstName3, &id3, &test3_1, &test3_2, 
				&test3_3, &test3_4, &thirdHigh, &thirdLow);
		}// else if
	} while (result != 3);
	
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
						int test4, float high, float low, float average, char letterGrade)
{
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f  %c\n", lastName, firstName, id, test1, test2, test3, 
			test4, high, low, average, letterGrade);

	return;
}// displayStudentInfo

/* =================================================================================
	Function Name: calcLetterGrade
	Function Description: calculates a student's letter grade
	Inputs: average score for student
	Outputs: returns the calculated letter grade
	Date: February 21st, 2023
====================================================================================*/
char calcLetterGrade(float average)
{
	char tempLetterGrade = ' ';
	if (average >= 90)
		tempLetterGrade = 'A';
	else if (average >= 80)
		tempLetterGrade = 'B';
	else if (average >= 70)
		tempLetterGrade = 'C';
	else if (average >= 60)
		tempLetterGrade = 'D';
	else
		tempLetterGrade = 'F';

	return tempLetterGrade;
}// calcLetterGrade

	/* =================================================================================
		Function Name: displayMenu
		Function Description: gets an appropriate menu choice from the user
		Inputs: None
		Outputs: returns the validated menu choice
		Date: February 27th, 2023
	====================================================================================*/
	int displayMenu(void)
	{
		int result = 0;
		
		do
		{
			// display menu
			printf("\nMenu: Make a choice:\n");
		printf("1. Display report\n");
		printf("2. Add a student\n");
		printf("3. Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &result);
		
		switch(result)
		{
			case 1:
			case 2:
			case 3: break;
			default:
				printf("\nInvalid choice. Please try again.\n");
				result = 0;
                break;
		}// switch

		
	} while (result == 0);

	return result;
}// displayMenu

	/* =================================================================================
		Function Name: getAllData
		Function Description: the data for the first three students
		Inputs: all student data passed by reference
		Outputs: None
		Date: February 27th, 2023
	====================================================================================*/
	void getAllData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1_1, int* pTest1_2, int* pTest1_3, int* pTest1_4, 
				float* FirstHigh, float* FirstLow, char* pLastName2, char* pFirstName2, int* pId2, int* pTest2_1, int* pTest2_2, 
				int* pTest2_3, int* pTest2_4, float* SecondHigh, float* SecondLow, char* pLastName3, char* pFirstName3, 
				int* pId3, int* pTest3_1, int* pTest3_2, int* pTest3_3, int* pTest3_4, float* ThirdHigh, float* ThirdLow)
{
	// Prompt and get the first student's data
	getData(pLastName1, pFirstName1, pId1, pTest1_1, pTest1_2, pTest1_3, pTest1_4, FirstHigh, FirstLow);
	// Prompt and get the second student's data
	getData(pLastName2, pFirstName2, pId2, pTest2_1, pTest2_2, pTest2_3, pTest2_4, SecondHigh, SecondLow);
	// Prompt and get the third student's data
	getData(pLastName3, pFirstName3, pId3, pTest3_1, pTest3_2, pTest3_3, pTest3_4, ThirdHigh, ThirdLow);
	
	return;
}// getAllData

