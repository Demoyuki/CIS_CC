/*	This program modifys Project 8 to add:
		1) Use a first and last name instead of initials.
		2) An updated data file (called projectData.txt) is to be used for the first three students
		3) Your "Show full report" option should show the students sorted by last name.
		4) Be sure that your add and search functionality is updated for the change in data.
		See the assignment handout for further information.
	Filename: project10.c
	Written by: Dan Guilmette
	Date: April 24th, 2023
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_SCORES 4
#define MAX_STUDENTS 5
#define NUM_INITIAL_STUDENTS 3
#define FLUSH while(getchar() != '\n')
#define MAX_NAME_LENGTH 10

		
// Function Declarations ===========================================
void readData(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[ ], int studentScores[ ][NUM_SCORES], 
							int numInitialStudents);
void reportOutput( char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[ ], int studentScores[ ][NUM_SCORES], 
								int studentMinScore[ ], int studentMaxScore[ ], float studentAvg[ ], int numCurrentStudents, 
								char studentLetterGrade[ ]);	
void calcAve(int studentScores[ ][NUM_SCORES], float studentAvg[MAX_STUDENTS], int numCurrentStudents);
void calcMinScore( int studentScores[ ][NUM_SCORES], int studentMaxScore [ ], int numScores, int numCurrentStudents);								
void calcMaxScore( int studentScores[ ][NUM_SCORES], int studentMinScore [ ], int numScores, int numCurrentStudents);
void findGrade( float studentAvg[ ], char studentLetterGrade[ ], int numCurrentStudents);								
void calcTestStatistics(int studentScores[ ][NUM_SCORES], int testMax[ ], int testMin[ ], float testAvg[ ], int numCurrentStudents, int numScores);
void displayTestStatistics(int testMax[ ], int testMin[ ], float testAvg[ ], int numScores);
void sort(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[], int studentScores[][NUM_SCORES], 
				int studentMinScore[], int studentMaxScore[], float studentAvg[], char studentLetterGrade[], int numCurrentStudents);
void swapInt(int* a, int* b);
void swapFloat(float* a, float* b);
void swapChar(char* a, char* b);
void swapInt2D(int* a, int* b, int size);
int getData(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[], int studentScores[][NUM_SCORES], int numCurrentStudents);
bool checkIntRange(int integer);
void searchForStudent(int studentID[ ], int studentScores[ ][NUM_SCORES], int studentMinScore[ ], int studentMaxScore[ ], 
					float studentAvg[ ], int numCurrentStudents, char studentLetterGrade[ ]);
// end function declarations ========================================



int main(void)
{

	// Local Definitions ==============
	int numScores = 4;
	int maxStudents = 5;
	int numInitialStudents = 3;
	char firstNames[MAX_STUDENTS][MAX_NAME_LENGTH];
	char lastNames[MAX_STUDENTS][MAX_NAME_LENGTH];
	int studentID[maxStudents] ;
	int studentScores[maxStudents][numScores] ;
	int numCurrentStudents = 3;
	int studentMaxScore[maxStudents];
	int studentMinScore[maxStudents];
	float studentAvg[maxStudents];
	char studentLetterGrade[maxStudents];
	char userInput = ' ';
	int testMax[numScores];
	int testMin[numScores];
	float testAvg[numScores];
	
	// Statements ================

	printf("Welcome to The Student Report.\n");
	
	readData(lastNames, firstNames, studentID, studentScores, numInitialStudents);
	
	while (userInput != '4')
	{	
		printf("\n\nMenu: Make A Selection\n");
		printf("1.   Show full report\n");
		printf("2.   Add a student\n");
		printf("3.   Search for a student\n");
		printf("4.   Quit\n\n");
		printf("Your Selection: ");
		scanf(" %c", &userInput);
		
		if (isdigit(userInput) && userInput == '1')
		{
			calcAve(studentScores, studentAvg, numCurrentStudents);
			calcMinScore( studentScores, studentMinScore, numScores, numCurrentStudents);
			calcMaxScore( studentScores, studentMaxScore, numScores, numCurrentStudents);
			findGrade( studentAvg, studentLetterGrade, numCurrentStudents);
			sort(lastNames, firstNames, studentID, studentScores, studentMinScore, studentMaxScore, studentAvg, studentLetterGrade, numCurrentStudents);
			printf("\nReport is\nLast\t   First      ID       Test1    Test2    Test3    Test4    High     Low      Ave      Grade");
			reportOutput( lastNames, firstNames, studentID, studentScores, studentMinScore, studentMaxScore, studentAvg, 
									numCurrentStudents, studentLetterGrade);
									
			// calculate and display test statistics
			calcTestStatistics(studentScores, testMax, testMin, testAvg, numCurrentStudents, numScores);
			displayTestStatistics(testMax, testMin, testAvg, numScores);
			
			FLUSH;
		}// if
		else if (isdigit(userInput) && userInput == '2')
		{
			if (numCurrentStudents < maxStudents)
			{
				numCurrentStudents = getData(lastNames, firstNames, studentID, studentScores, numCurrentStudents);
			}// if there is room
			else
			{
				printf("You have entered the maximum number of students.\n");	
			}// else
		}// else if
		else if (isdigit(userInput) && userInput == '3')
		{
			searchForStudent(studentID, studentScores, studentMinScore, studentMaxScore, studentAvg, numCurrentStudents, studentLetterGrade);
		}// else if

		else if (isdigit(userInput) && userInput == '4')
		{
			// end program
			printf("This program has ended.\n");
		}// else if
		else
		{
			printf("Incorrect input. Please enter 1, 2, 3, or 4.\n");
			FLUSH;
		}// else
		
	}// while
	
    return 0;
} //main

 /* =================================================================================
	Function Name: reportOutput
	Function Description: displays student information for the report
	Inputs: all information for a single student
	Outputs: None
	Date: March 15th, 2023
====================================================================================*/
void reportOutput( char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[ ], int studentScores[ ][NUM_SCORES], 
								int studentMinScore[ ], int studentMaxScore[ ], float studentAvg[ ], int numCurrentStudents, 
								char studentLetterGrade[ ])
{
	// Local Definitions ==============
	
    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
			printf("\n%-10s %-10s %-8d %-8d %-8d %-8d %-8d %-8.1d %-8.1d %-8.1f %-8c", lastNames[row], firstNames[row], studentID[row],
					studentScores[row][0], studentScores[row][1], studentScores[row][2], studentScores[row][3], studentMaxScore[row],
					studentMinScore[row], studentAvg[row], studentLetterGrade[row]);
	}// for
   
    return;
}    // reportOutput

 
 /* =================================================================================
	Function Name: readData
	Function Description: reads information from a file
	Inputs: pass-by-reference pointers to first 3 student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023
====================================================================================*/
void readData(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[ ], int studentScores[ ][NUM_SCORES], 
							int numInitialStudents)
{	
    // Local Definitions ==============
    FILE* spData;
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
    
	// Statements ================
	if ((spData = fopen("projectData.txt", "r")) == NULL)
	{
		printf("Error opening file. Exiting the program.\n");
		exit(10);
	}// if
	
	for (int row = 0; row < numInitialStudents; row++)
	{
		// read a student
		fscanf(spData," %s %s %d %d %d %d %d", firstName, lastName, &studentID[row], 
			&studentScores[row][0], &studentScores[row][1], &studentScores[row][2], &studentScores[row][3]);
			strcpy(firstNames[row], firstName);
			strcpy(lastNames[row], lastName);
	}// for
	
	if ((fclose(spData)) == EOF)
	{
		printf("Error closing file. Exiting the program.\n");
		exit(20);
	}// if
	
	return;
}// readData

/* =================================================================================
	Function Name: calcAve
	Function Description: returns the average of four integer scores
	Inputs: four integer scores
	Outputs: average of scores as a float
	Date: March 15th, 2023
====================================================================================*/
void calcAve(int studentScores[ ][NUM_SCORES], float studentAvg[MAX_STUDENTS], int numCurrentStudents)
{
    // Local Definitions ==============

    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
			studentAvg[row] = (studentScores[row][0] + studentScores[row][1] + studentScores[row][2] + studentScores[row][3]) / 4.0;
	}// for

    return ;
}// calcAve

/* =================================================================================
	Function Name: calcMinScore
	Function Description: calculates a student's min test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
====================================================================================*/
void calcMinScore( int studentScores[ ][NUM_SCORES], int studentMinScore [ ], int numScores, int numCurrentStudents)
{
	// Local Definitions ==============
	int minScore = 101;

    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
		for (int col = 0; col < numScores; col++)
		{
			if( studentScores[row][col] < minScore)
			{
				minScore = studentScores[row][col];
			}// if
		}// for
		
		studentMinScore[row] = minScore;
		minScore = 101;
	}// for

    return;
}// calcMinScore

 /* =================================================================================
	Function Name: calcMaxScore
	Function Description: calculates a student's max test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
====================================================================================*/
void calcMaxScore( int studentScores[ ][NUM_SCORES], int studentMaxScore [ ], int numScores, int numCurrentStudents)
{
	// Local Definitions ==============
	int maxScore = -99;

    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
		for (int col = 0; col < numScores; col++)
		{
			if( studentScores[row][col] > maxScore)
			{
				maxScore = studentScores[row][col];
			}// if
		}// for
		
		studentMaxScore[row] = maxScore;
		maxScore = -99;
	}// for

    return;
}// calcMinScore

 /* =================================================================================
	Function Name: calcTestStatistics
	Function Description: calculates the max, min, and avergae for each test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
====================================================================================*/
void calcTestStatistics(int studentScores[ ][NUM_SCORES], int testMax[ ], int testMin[ ], float testAvg[ ], int numCurrentStudents, int numScores)
{
	// Local Definitions ==============
	int testSum = 0;
	
    // Statements ================
	for (int col = 0; col < numScores; col++)
	{
		// set initial values
		testMax[col] = -1;
		testMin[col] = 101;
		// check for new max and min; sum tests
		for (int row = 0; row < numCurrentStudents; row++)
		{
			testSum = testSum + studentScores[row][col];
			// check for new max
			if( studentScores[row][col] > testMax[col])
			{
				testMax[col] = studentScores[row][col];
			}// if
			// check for new min
			if( studentScores[row][col] < testMin[col])
			{
				testMin[col] = studentScores[row][col];
			}// if
		}// for
		testAvg[col] = testSum / (float)numCurrentStudents;
		testSum = 0;;
	}// for
	return;
}// calcTestStatistics

 /* =================================================================================
	Function Name: displayTestStatistics
	Function Description: displays the max, min, and avergae for each test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
====================================================================================*/
void displayTestStatistics(int testMax[ ], int testMin[ ], float testAvg[ ], int numScores)
{
	// Local Definitions ==============
	
    // Statements ================
    printf("\n\nTest Statistics\nTest Number	 Max Score	  Min Score       Average");
    
	for (int row = 0; row < numScores; row++)
	{
			printf("\n    %-8d        %-8d         %-8d       %-8.1f", (row + 1), testMax[row], testMin[row], testAvg[row]);
	}// for
	
	return;
}// displayTestStatistics

/* =================================================================================
	Function Name: findGrade
	Function Description: determines the letter grade based on student average
	Inputs: average
	Outputs: returns letter grade
	Date: March 15th, 2023
====================================================================================*/
void findGrade( float studentAvg[ ], char studentLetterGrade[ ], int numCurrentStudents)
{
	// Local Definitions ==============

    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
		if (studentAvg[row] >= 90.0)
		{
			studentLetterGrade[row] = 'A';
		}// if
		else if (studentAvg[row] >= 80.0)
		{
			studentLetterGrade[row] = 'B';
		}// else if
		else if (studentAvg[row] >= 70.0)
		{
			studentLetterGrade[row] = 'C';
		}// else if
		else if (studentAvg[row] >= 60.0)
		{
			studentLetterGrade[row] = 'D';
		}// else if
		else
		{
			studentLetterGrade[row] = 'F';
		}// else
	}// for
	
	return;
}// findGrade

/* =================================================================================
	Function Name: sort
	Function Description: sorts all student data arrays based on last name
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 21st, 2023
====================================================================================*/
void sort(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[], int studentScores[][NUM_SCORES], 
				int studentMinScore[], int studentMaxScore[], float studentAvg[], char studentLetterGrade[], int numCurrentStudents) 
{
    int first, second;
    char temp[MAX_NAME_LENGTH];
    for (first = 0; first < numCurrentStudents - 1; first++) 
	{
        for (second = first + 1; second < numCurrentStudents; second++) 
		{
            if (strcmp(lastNames[first], lastNames[second]) > 0) 
			{
				// swap last and first names
                strcpy(temp, lastNames[first]);
                strcpy(lastNames[first], lastNames[second]);
                strcpy(lastNames[second], temp);
                strcpy(temp, firstNames[first]);
                strcpy(firstNames[first], firstNames[second]);
                strcpy(firstNames[second], temp);
				// swap other student information
				swapInt(&studentID[first], &studentID[second]);
                swapInt(&studentMinScore[first], &studentMinScore[second]);
                swapInt(&studentMaxScore[first], &studentMaxScore[second]);
                swapFloat(&studentAvg[first], &studentAvg[second]);
                swapChar(&studentLetterGrade[first], &studentLetterGrade[second]);
				swapInt2D(studentScores[first], studentScores[second], NUM_SCORES);
            }// if
        }// for
    }// for
}// sort

/* =================================================================================
	Function Name: swapInt
	Function Description: swaps values that two pointers to integers point to
	Inputs: pass-by-reference pointers to two integers
	Outputs: None - uses pass-by-reference
	Date: April 21st, 2023
====================================================================================*/
void swapInt(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
	return;
}// swapInt

/* =================================================================================
	Function Name: swapFloat
	Function Description: swaps values that two pointers to floats point to
	Inputs: pass-by-reference pointers to two integers
	Outputs: None - uses pass-by-reference
	Date: April 21st, 2023
====================================================================================*/
void swapFloat(float* first, float* second)
{
	float temp = *first;
	*first = *second;
	*second = temp;
	return;
}// swapFloat

/* =================================================================================
	Function Name: swapChar
	Function Description: swaps values that two pointers to char point to
	Inputs: pass-by-reference pointers to two integers
	Outputs: None - uses pass-by-reference
	Date: April 21st, 2023
====================================================================================*/
void swapChar(char* first, char* second) {
    char temp = *first;
    *first = *second;
    *second = temp;
}// swapChar

/* =================================================================================
	Function Name: swapInt2D
	Function Description: swaps values that two pointers to an array point to
	Inputs: pass-by-reference pointers to two integers
	Outputs: None - uses pass-by-reference
	Date: April 21st, 2023
====================================================================================*/
void swapInt2D(int* first, int* second, int size) 
{
    int i, temp;
    for (i = 0; i < size; i++) 
	{
        temp = *(first + i);
        *(first + i) = *(second + i);
        *(second + i) = temp;
    }// for
}// swapInt2D

/* =================================================================================
	Function Name: getData
	Function Description: gets new student information from the user
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023 (modified April 21st)
====================================================================================*/
int getData(char lastNames[][MAX_NAME_LENGTH], char firstNames[][MAX_NAME_LENGTH], int studentID[], int studentScores[][NUM_SCORES], int numCurrentStudents)
{
    // Local Definitions ==============
    int scanCount = 0;
    int intCheck = 0;
    int dataCount = 0;
    bool isValid = false;
    char tempInput;
    int status = 0;
    int newStudentIndex = numCurrentStudents;

    // Statements ================
    newStudentIndex = numCurrentStudents;

    while (isValid == false)
    {
        FLUSH;
        printf("Enter the student's Last Name (use ] to quit): ");
        scanf("%s", lastNames[newStudentIndex]);
        if (lastNames[newStudentIndex][0] == ']')
        {
            lastNames[newStudentIndex][0] = ' ';
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            lastNames[newStudentIndex][0] = toupper(lastNames[newStudentIndex][0]);
            isValid = true;
        } // if
    } // while getting last name

    isValid = false;
    while (isValid == false)
    {
        FLUSH;
        printf("Enter the student's First Name (use ] to quit): ");
        scanf("%s", firstNames[newStudentIndex]);
        if (firstNames[newStudentIndex][0] == ']')
        {
            firstNames[newStudentIndex][0] = ' ';
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            firstNames[newStudentIndex][0] = toupper(firstNames[newStudentIndex][0]);
            isValid = true;
        } // if
    } // while getting first name

    isValid = false;
    while (isValid == false)
    {
        FLUSH;
        printf("Enter the student's ID (use ] to quit): ");
        tempInput = getc(stdin);
        if (tempInput == ']')
        {
            printf("Quitting Data Entry...\n");
			return numCurrentStudents;
        } // if quit data entry
        else
        {
            ungetc(tempInput, stdin);
        } // else
        status = scanf(" %d", &studentID[newStudentIndex]);
        FLUSH;
        if (status != 1)
        {
            printf("Must be an integer!\n");
        } // if
        else
        {
            isValid = true;
        } // else
    } // while getting ID

    isValid = false;
    while (isValid == false)
    {
        printf("Enter the student's first score (use ] to quit): ");
        tempInput = getc(stdin);
        if (tempInput == ']')
        {
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            ungetc(tempInput, stdin);
        } // else
        status = scanf("%d", &studentScores[newStudentIndex][0]);
        FLUSH;
        if (status != 1)
        {
            printf("Must be an integer!\n");
        } // if
        else
        {
            if (checkIntRange(studentScores[newStudentIndex][0]))
            {
                isValid = true;
            } // if
            else
            {
                isValid = false;
			}
        } // else
    } // while getting score1

    isValid = false;
    while (isValid == false)
    {
        printf("Enter the student's second score (use ] to quit): ");
        tempInput = getc(stdin);
        if (tempInput == ']')
        {
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            ungetc(tempInput, stdin);
        } // else
        status = scanf("%d", &studentScores[newStudentIndex][1]);
        FLUSH;
        if (status != 1)
        {
            printf("Must be an integer!\n");
        } // if
        else
        {
            if (checkIntRange(studentScores[newStudentIndex][1]))
            {
                isValid = true;
            } // if
            else
            {
                isValid = false;
            } // else
        } // else
    } // while getting score2

    isValid = false;
    while (isValid == false)
    {
        printf("Enter the student's third score (use ] to quit): ");
        tempInput = getc(stdin);
        if (tempInput == ']')
        {
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            ungetc(tempInput, stdin);
        } // else
        status = scanf("%d", &studentScores[newStudentIndex][2]);
        FLUSH;
        if (status != 1)
        {
            printf("Must be an integer!\n");
        } // if
        else
        {
            if (checkIntRange(studentScores[newStudentIndex][2]))
            {
                isValid = true;
            } // if
            else
            {
                isValid = false;
            } // else
        } // else
    } // while getting score3

    isValid = false;
    while (isValid == false)
    {
        printf("Enter the student's fourth score (use ] to quit): ");
        tempInput = getc(stdin);
        if (tempInput == ']')
        {
            printf("Quitting Data Entry...\n");
            return numCurrentStudents;
        } // if quit data entry
        else
        {
            ungetc(tempInput, stdin);
        } // else
        status = scanf("%d", &studentScores[newStudentIndex][3]);
        FLUSH;
        if (status != 1)
        {
            printf("Must be an integer!\n");
        } // if
        else
        {
            if (checkIntRange(studentScores[newStudentIndex][3]))
            {
                isValid = true;
            } // if
            else
            {
                isValid = false;
            } // else
        } // else
    } // while getting score4

    printf("Student data added\n");
    // add student count
    numCurrentStudents = numCurrentStudents + 1;

    return numCurrentStudents;
} // getData
           
/* =================================================================================
	Function Name: checkIntRange
	Function Description: checks if input is a character
	Inputs: input value
	Outputs: returns true if character; returns false otherwise
	Date: March 15th, 2023
====================================================================================*/
bool checkIntRange(int intValue)
{
	// Local Definitions ==============
	bool testResult = false;
	
	// Statements ================
	if(intValue < 0 || intValue > 100)
	{
		printf("value must be between 0 - 100 inclusive!\n");
		testResult = false;
	}// if
	else
	{
		testResult = true;
	}// else
		
	return testResult;
}// checkIntRange

/* =================================================================================
	Function Name: searchForStudent
	Function Description: gets student ID from user (with error-checking), searches for student and displays 
		an appropriate message if the student is not found, or the student ID, test scores, min, max, average and
		letter grade for the found student.
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
====================================================================================*/
void searchForStudent(int studentID[ ], int studentScores[ ][NUM_SCORES], int studentMinScore[ ], int studentMaxScore[ ], 
					float studentAvg[ ], int numCurrentStudents, char studentLetterGrade[ ])
{
	// Local Definitions ==============
	bool isValid = false;
	char tempInput = ' ';
	int searchID = 0;
	int currCount = 0;
	int row = 0;
	int status = 0;
	bool quit = false;
	
	// get student ID ================
	isValid = false;
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's ID to search for (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			FLUSH;
			printf("Quitting Data Entry...\n");
			quit = true;
			break;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf(" %d", &searchID);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			isValid = true;
		}// else
	}// while getting ID
	
	// search for ID in studentID ======================
	isValid = false;
	while(isValid == false && currCount < numCurrentStudents && quit == false)
	{
		if (searchID == studentID[row])
		{
			isValid = true;
		}// if
		else
		{
			row++;
			currCount++;
		}// else
	}// while

	// return results of searchForStudent ======================
	if (quit == false)
	{
		if (isValid)
		{
			printf("\nReport is\nID       Test1    Test2    Test3    Test4    High     Low      Ave      Grade");
			printf("\n%-8d %-8d %-8d %-8d %-8d %-8.1d %-8.1d %-8.1f %-8c", studentID[row],
						studentScores[row][0], studentScores[row][1], studentScores[row][2], studentScores[row][3], studentMaxScore[row],
						studentMinScore[row], studentAvg[row], studentLetterGrade[row]);
		}// if
		else
		{
			printf("\nSubmitted Student ID not found...\n");
		}// else
	}// if
	return;
}// searchForStudent