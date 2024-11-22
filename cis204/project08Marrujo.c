/* ========================================================
   ||	A class has four assessments worth equal value. The class has 			||
   ||	5 students. 																								||
   ||	o Program will read 4th and 5th students initials, ID numbers, 				||
   ||		assessment scores, highest scores, and lowest scores. 					||
   ||																													||
   ||	o Program will read a file to get input data for the first 3 students. 		||
   ||																													||
   ||	o It will then calculate each student's average, and then print out the 	||
   ||		input data and average for each student in a formatted output that 	||
   ||		is clear to read. 																					||
   ||																													||
   ||	o There must be functions to get the data, to 										||
   ||		calculate the average, and to display the data.									||
   ||																													||
   ||	o Must also have a menu with the following options: 								||
   ||		1. Display report																					||
   ||		2. Add a student																					||
   ||		3. Exit program																					||
   ||======================================================||
   ||	Filename: project07Marrujo.c																	||
   ||	Written by: Victor Marrujo																		||
   ||	Date: 30 February 2023 - 05 April 2023												||
   ========================================================
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLUSH while(getchar() != '\n')
#define NUMBEROFTESTS 4
#define MAXSTUDENTS 5
// Function Declarations ===========================================
void readData( char* firstInitial[], char* lastInitial[], int* studentID[], int* studentScores[][NUMBEROFTESTS]);
void getData( char* plastInitial, char* pfirstInitial, int* pID, int* pscore1, int* pscore2, int* pscore3, int* pscore4, 
							int* pscoreHigh, int* pscoreLow, int* studentCount);
float calcAve( int score1, int score2, int score3, int score4);
void reportOutput( char lastInitial, char firstInitial, int ID, int score1, int score2, int score3, int score4, int scoreHigh, 
							int scoreLow, float calcAve, char letterGrade);
char findGrade( float calcAve);
bool checkChar(char lastInitial);
bool checkIntRange(int integer);
// end function declarations ========================================
int main(void)
{
   // Local Definitions ==============
	int studentCount = 3;
	int choice = 0;
	int i = 0;
	bool isValid = false;
    char tempInput;
    int status = 0;
		// Arrays
	    char firstInitial[MAXSTUDENTS];
	    char lastInitial[MAXSTUDENTS];
	    int studentID[MAXSTUDENTS];
        int studentScores[MAXSTUDENTS][NUMBEROFTESTS];
	    int studentMaxScore[MAXSTUDENTS];
        int studentMinScore[MAXSTUDENTS];
        float studentAvg[MAXSTUDENTS];
        char studentLetterGrade[MAXSTUDENTS];
	// Statements ================
	printf("Welcome to The Student Report.\n");
	while (choice != 3)
	{	
		readData( &firstInitial, &lastInitial, &studentID, &studentScores);
		
		printf("\n\nMenu: Make A Choice\n");
		printf("1.   Show full report\n");
		printf("2.   Add a student\n");
		printf("3.   Search\n");
		printf("4.   Quit\n\n");
		scanf(" %d", &choice);
		
		if (choice == 1)
		{
			for (i = 0; i < studentCount; ++i)
            {
			    studentAvg[i] = calcAve(studentScores[i][0], studentScores[i][1], studentScores[i][2], studentScores[i][3]);
			}// For calculates student average score
			
			for (i = 0; i < studentCount; ++i)
            {
			    studentLetterGrade[i] = findGrade(studentAvg[i]);
			} // For calculates student letter grade
			
			printf("\nReport is\nLast	 First	  ID       Test1    Test2    Test3    Test4    High     Low      Ave      Grade");
			
			for (i = 0; i < studentCount; ++i)
            {
			    reportOutput(firstInitial[i], lastInitial[i], studentID[i], studentScores[i][0],studentScores[i][1],studentScores[i][2],
			                  studentScores[i][3], studentMaxScore[i], studentMinScore[i], studentAvg[i], studentLetterGrade[i]);
			} // For prints reportOutput
		}// if
		else if (choice == 2)
		{
			if (studentCount == 3)	
			{
				getData(firstInitial[studentCount-1], lastInitial[studentCount-1], studentID[studentCount-1], studentScores[studentCount-1][0],
				studentScores[studentCount-1][1],studentScores[studentCount-1][2],studentScores[studentCount-1][3], 
				studentMaxScore[studentCount-1], studentMinScore[studentCount-1], &studentCount);
			}// if
			else if (studentCount == 4)	
			{
				getData(firstInitial[studentCount-1], lastInitial[studentCount-1], studentID[studentCount-1], studentScores[studentCount-1][0],
				studentScores[studentCount-1][1],studentScores[studentCount-1][2],studentScores[studentCount-1][3], 
				studentMaxScore[studentCount-1], studentMinScore[studentCount-1], &studentCount);
			}// if
			else
			{
				printf("You have entered the maximum number of students.\n");	
			}// else
		}// else if
		else if (choice == 3)
		{   
		    while (isValid != true)
		    {
    			FLUSH;
            	printf("Enter the student's ID (use ] to quit): ");
            	tempInput = getc(stdin);
            	if(tempInput == ']')
        	    {
            		FLUSH;
            		printf("Quitting Data Entry...\n");
        	    }// if quit data entry
            	else
            	    {
            	    	ungetc(tempInput, stdin);
            	    }// else
        	    status = atoi(tempInput);
        	    FLUSH;
            	if (status != 1)
            	{
            		printf("Must be an integer!\n");
            	}// if
            	else
            		{
            			isValid = true;
            		}// else
            	if (search(studentID, status)!= -99)
            	{
            	    status = search(studentID, status);
            	    printf("ID found in system, now displaying student data:");
            	    printf("\nTest1    Test2    Test3    Test4    High     Low      Ave      Grade");
            	    printf("\n%-8d %-8d %-8d %-8d %-8.1d %-8.1d %-8.1f %-8c", studentScores[status][0]
            	            , studentScores[status][1], studentScores[status][2], studentScores[status][3]
            	            , studentMaxScore[status], studentMinScore[status], studentAvg[status]
            	            , studentLetterGrade[status]);
            	}else
            	    {
            	        printf("ID not found.");
            	    }
        	}// while getting ID
		}// else if
		else if (choice == 4)
		{
			// end program
			printf("This program has ended.\n");
		}// else if
		else
		{
			FLUSH;
			printf("Incorrect input. Please enter 1, 2, 3 or 4.\n");
		}// else

	}// while
	
    return 0;
} //main
 /* =================================================================================
	Function Name: search
	Function Description: reads input student ID and searches if its available
	Inputs: arrays containing student info
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023 - April 5th, 2023
====================================================================================*/
int search(int studentID[], int lookingFor) 
{
    for (int i = 0; i < MAXSTUDENTS; i++) 
    {
        if (studentID[i] == lookingFor) 
        {
            return i;
        }
    }
    return -99;
}// search

 /* =================================================================================
	Function Name: readData
	Function Description: reads information from a file
	Inputs: pass-by-reference pointers to first 3 student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023 - April 5th, 2023
====================================================================================*/
void readData(char* firstInitial[], char* lastInitial[], int* studentID[], int* studentScores[][NUMBEROFTESTS])
{
    // Local Definitions ==============
    FILE* spData;
    int i = 0;
	// Statements ================
	if ((spData = fopen("scoresProj08.txt", "r")) == NULL)
	{
		printf("Error opening file. Exiting the program.\n");
		exit(10);
	}// if
	
	fscanf(spData," %c %c %d %d %d %d %d %c %c %d %d %d %d %d %c %c %d %d %d %d %d "
	    , firstInitial[0], lastInitial[0], studentID[0], studentScores[0][0], studentScores[0][1], 
        studentScores[0][2], studentScores[0][3], 
        firstInitial[1], lastInitial[1], studentID[1], studentScores[1][0], studentScores[1][1], 
        studentScores[1][2], studentScores[1][3],
        firstInitial[2], lastInitial[2], studentID[2], studentScores[2][0], studentScores[2][1], 
        studentScores[2][2], studentScores[2][3]);

	if ((fclose(spData)) == EOF)
	{
		printf("Error closing file. Exiting the program.\n");
		exit(20);
	}// if
	
	return;
}//readData

 /* =================================================================================
	Function Name: getData
	Function Description: gets new student information from the user
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023
====================================================================================*/
void getData( char* plastInitial, char* pfirstInitial, int* pID, int* pscore1, int* pscore2, int* pscore3, int* pscore4, 
			int* pscoreHigh, int* pscoreLow, int* studentCount)
{
	// Local Definitions ==============
	int scanCount = 0;
	int intCheck = 0;
	int dataCount = 0;
	bool isValid = false;
	char tempInput;
	int status = 0;

    // Statements ================
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's Last Initial (use ] to quit): ");
		scanf("%c", plastInitial);
		if(*plastInitial == ']')
		{
			*plastInitial = ' ';
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		if (checkChar(*plastInitial))
		{
			*plastInitial = toupper(*plastInitial);
			isValid = true;
		}// if
	}// while getting last initial

	isValid = false;
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's First Initial (use ] to quit): ");
		scanf("%c", pfirstInitial);
		if(*pfirstInitial == ']')
		{
			*pfirstInitial = ' ';
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		if (checkChar(*pfirstInitial))
		{
			*pfirstInitial = toupper(*pfirstInitial);
			isValid = true;
		}// if
	}// while getting first initial

	isValid = false;
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's ID (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			FLUSH;
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf(" %d", pID);
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

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's first score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			FLUSH;
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscore1);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscore1))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting score1

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's second score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscore2);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscore2))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting score2

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's third score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscore3);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscore3))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting score3

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's fourth score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscore4);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscore4))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting score4

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's high score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscoreHigh);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscoreHigh))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting scoreHigh

	isValid = false;
	while (isValid == false)
	{
		printf("Enter the student's low score (use ] to quit): ");
		tempInput = getc(stdin);
		if(tempInput == ']')
		{
			printf("Quitting Data Entry...\n");
			return;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", pscoreLow);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(*pscoreLow))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting scoreLow


	printf("Student data added\n");
	// add student count
	*studentCount = *studentCount + 1;
	
    return;
}// getData

 /* =================================================================================
	Function Name: calcAve
	Function Description: returns the average of four integer scores
	Inputs: four integer scores
	Outputs: average of scores as a float
	Date: March 15th, 2023
====================================================================================*/
float calcAve( int score1, int score2, int score3, int score4)
{
    // Local Definitions ==============
    float localAverage = 0.0;    //the average score of the 4 scores passed into the function

    // Statements ================
    localAverage = (score1 + score2 + score3 + score4) / 4.0;

    return localAverage;
}// calcAve

/* =================================================================================
	Function Name: reportOutput
	Function Description: displays student information for the report
	Inputs: all information for a single student
	Outputs: None
	Date: March 15th, 2023
====================================================================================*/
void reportOutput( char lastInitial, char firstInitial, int ID, int score1, int score2, int score3, int score4, int scoreHigh, 
					int scoreLow, float calcAve, char letterGrade)
{
	// Local Definitions ==============
	
    // Statements ================
    printf("\n%-8c %-8c %-8d %-8d %-8d %-8d %-8d %-8.1d %-8.1d %-8.1f %-8c", lastInitial, firstInitial, ID, score1, score2, score3, score4, scoreHigh, scoreLow, calcAve, letterGrade);
   
    return;
}    // reportOutput

/* =================================================================================
	Function Name: findGrade
	Function Description: determines the letter grade based on student average
	Inputs: average
	Outputs: returns letter grade
	Date: March 15th, 2023
====================================================================================*/
char findGrade( float average)
{
	// Local Definitions ==============
	char letterGrade;
	
	// Statements ================
	if (average >= 90.0)
	{
		letterGrade = 'A';
	}// if
	else if (average >= 80.0)
	{
		letterGrade = 'B';
	}// else if
	else if (average >= 70.0)
	{
		letterGrade = 'C';
	}// else if
	else if (average >= 60.0)
	{
		letterGrade = 'D';
	}// else if
	else
	{
		letterGrade = 'F';
	}// else
	
	return letterGrade;
}// findGrade

/* =================================================================================
	Function Name: checkChar
	Function Description: checks if input is a character
	Inputs: input value
	Outputs: returns true if character; returns false otherwise
	Date: March 15th, 2023
====================================================================================*/
bool checkChar(char inputValue)
{
	// Local Definitions ==============
	bool result = false;
	
	// Statements ================
	if(!(isalpha(inputValue)))
	{
		printf("Must be an letter!\n");
	}// if
	else
	{
		result = true;
	}// else
	
	return result;
}// checkChar

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