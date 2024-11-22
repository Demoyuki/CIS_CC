/*	This program modifys Project 11 to modifiy an array of structures named Student that contain the following fields:
○ lastName
○ firstName
○ studentID
○ scores[ ]
○ minScore
○ maxScore
○ avgScore
○ letterGrade

	Filename: final04Marrujo.c
	Changes made by: Victor Marrujo
	Date: April 30nd, 2023 (completed on May 10th, 2023)
	
	NOTE:
	project11Marrujo.c was used as a baseline.
    project08guilmette.c by Dan Guilmette was used as a baseline for project11Marrujo.c
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_SCORES 4
#define MAX_STUDENTS 5
#define NUM_INITIAL_STUDENTS 3
#define FLUSH while(getchar() != '\n')

struct Student 
{
    char lastName[20];
    char firstName[20];
    int studentID;
    int scores[NUM_SCORES];
    int minScore;
    int maxScore;
    float avgScore;
    char letterGrade;
};

struct TestStats
{
    int testMax;
    int testMin;
    float testAvg; 
};
// Function Declarations ===========================================
// Inputs
void readData(struct Student *s);
int getData(struct Student *s, int numCurrentStudents);
// Reports 
void reportOutput(struct Student *s, int numCurrentStudents);
void displayTestStatistics(struct TestStats *ts);
// Calcs
void calcAve(struct Student *s, int numCurrentStudents);
void calcMinScore(struct Student *s, int numCurrentStudents);								
void calcMaxScore(struct Student *s, int numCurrentStudents);
void findGrade(struct Student *s, int numCurrentStudents);								
void calcMaxScore(struct Student *s, int numCurrentStudents);								
void calcTestStatistics(struct Student *s, struct TestStats *ts, int numCurrentStudents);
// Validation
bool checkChar(char lastName);
bool checkIntRange(int integer);
// Search
void searchForStudentID(struct Student *s, int numCurrentStudents);
void searchOptionsID(struct Student *s, int numCurrentStudents);
// end function declarations ========================================

int main(void)
{

    // Local Definitions ==============
    char userInput = ' ';
    int numCurrentStudents = NUM_INITIAL_STUDENTS;
    struct Student students[MAX_STUDENTS];
    struct TestStats tests[NUM_SCORES];
    
    // Statements ==============================================================

    printf("Welcome to The Student Report.\n");
    
    readData(students);

	
    while (userInput != '4')
    {   
        // Calcs ===============================================================
        calcAve(students, numCurrentStudents);
	    calcMinScore(students, numCurrentStudents);
	    calcMaxScore(students, numCurrentStudents);
	    findGrade(students, numCurrentStudents);
	    
	    // Menu ================================================================
        printf("\n\nMenu: Make A Selection\n");
        printf("1.   Show full report\n");
        printf("2.   Add a student\n");
        printf("3.   Search for a student (By ID)\n");
        printf("4.   Quit\n\n");
        printf("Your Selection: ");
        scanf(" %c", &userInput);
        
        if (isdigit(userInput) && userInput == '1')
        {
			
			printf("\nReport is\nLast	  First	    ID       Test1    Test2    Test3    Test4    High     Low      Ave      Grade");
			reportOutput(students, numCurrentStudents);
			// calculate and display test statistics
			calcTestStatistics(students, tests, numCurrentStudents);
			displayTestStatistics(tests);
			FLUSH;
		}// if
		else if (isdigit(userInput) && userInput == '2')
		{
			if (numCurrentStudents < MAX_STUDENTS)
			{
				numCurrentStudents = getData(students, numCurrentStudents);
			}// if there is room
			else
			{
				printf("You have entered the maximum number of students.\n");	
			}// else
		}// else if
		else if (isdigit(userInput) && userInput == '3')
		{
		    printf("\nAvailable Student Information\nID	 Last	   First");
		    searchOptionsID(students, numCurrentStudents);
			searchForStudentID(students, numCurrentStudents);
		}// else if
		else if (isdigit(userInput) && userInput == '4')
		{
			// end program
			printf("This program has ended.\n");
		}// else if
		else
		{
			printf("Incorrect input. Please enter 1, 2, 3 OR 4.\n");
			FLUSH;
		}// else
		
	}// while
	
    return 0;
} //main

/* =================================================================================
	Function Name: readData
	Function Description: reads information from a file
	Inputs: pass-by-reference pointers to first 3 student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void readData(struct Student *s)
{
    // Local Definitions ==============
    FILE* spData;
    int sum = 0;
    
    // Statements ================
    if ((spData = fopen("projectData.txt", "r")) == NULL)
    {
        printf("Error opening file. Exiting the program.\n");
        exit(10);
    }// if

    for (int row = 0; row < NUM_INITIAL_STUDENTS; row++)
    {
        // read a student
        fscanf(spData," %s %s %d %d %d %d %d", s[row].firstName, s[row].lastName, &s[row].studentID,
            &s[row].scores[0], &s[row].scores[1], &s[row].scores[2], &s[row].scores[3]);
        
        for(int i=0;i<20;i++)
        {
            s[row].firstName[i] = toupper(s[row].firstName[i]);
        }// for
        for(int i=0;i<20;i++)
        {
            s[row].lastName[i]  = toupper(s[row].lastName[i]);
        }// for
        
    }// for

    if ((fclose(spData)) == EOF)
    {
        printf("Error closing file. Exiting the program.\n");
        exit(20);
    }// if

    return;
}// readData

 /* =================================================================================
	Function Name: getData
	Function Description: gets new student information from the user
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: March 15th, 2023
	Updates: o Initials were changed to full names 04/22/23
		Update: o changed from variables to structure use 05/04/23
====================================================================================*/
int getData(struct Student *s, int numCurrentStudents)
{
	// Local Definitions ==============
	int scanCount = 0;
	int intCheck = 0;
	int dataCount = 0;
	bool isValid = false;
	char tempInput;
	int status = 0;
	int newStudentIndex = 0;
	
    // Statements ================
    newStudentIndex = numCurrentStudents;
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's Last name (use ] to quit): ");
		scanf("%s",  s[newStudentIndex].lastName);
		if( s[newStudentIndex].lastName[0] == ']')
		{
			s[newStudentIndex].lastName[0] = ' ';
			printf("Quitting Data Entry...\n");
			return numCurrentStudents;
		}// if quit data entry
		if (checkChar(s[newStudentIndex].lastName[0]))
		{
		    for(int i=0;i<20;i++)
		    {
    			s[newStudentIndex].lastName[i]  = toupper(s[newStudentIndex].lastName[i]);
    			isValid = true;
		    }
		}// if
	}// while getting last initial

	isValid = false;
	while (isValid == false)
	{
		FLUSH;
		printf("Enter the student's First name (use ] to quit): ");
		scanf("%s",  s[newStudentIndex].firstName);
		if(s[newStudentIndex].firstName[0] == ']')
		{
			s[newStudentIndex].firstName[0] = ' ';
			printf("Quitting Data Entry...\n");
			return numCurrentStudents;
		}// if quit data entry
		if (checkChar(s[newStudentIndex].firstName[0]))
		{
		    for(int i=0;i<20;i++)
		    {
			    s[newStudentIndex].firstName[i] = toupper(s[newStudentIndex].firstName[i]);
			    isValid = true;
		    }
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
			return numCurrentStudents;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf(" %d", &s[newStudentIndex].studentID);
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
			return numCurrentStudents;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", &s[newStudentIndex].scores[0]);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(s[newStudentIndex].scores[0]))
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
			FLUSH;
			printf("Quitting Data Entry...\n");
			return numCurrentStudents;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", &s[newStudentIndex].scores[1]);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(s[newStudentIndex].scores[1]))
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
			FLUSH;
			printf("Quitting Data Entry...\n");
			return numCurrentStudents;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", &s[newStudentIndex].scores[2]);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(s[newStudentIndex].scores[2]))
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
			FLUSH;
			printf("Quitting Data Entry...\n");
			return numCurrentStudents;
		}// if quit data entry
		else
		{
			ungetc(tempInput, stdin);
		}// else
		status = scanf("%d", &s[newStudentIndex].scores[3]);
		FLUSH;
		if (status != 1)
		{
			printf("Must be an integer!\n");
		}// if
		else
		{
			if (checkIntRange(s[newStudentIndex].scores[3]))
			{
				isValid = true;
			}// if
			else
			{
				isValid = false;
			}// else
		}// else
	}// while getting score4

	printf("Student data added\n");
	// add student count
	numCurrentStudents = numCurrentStudents + 1;
	
    return numCurrentStudents;
}// getData

 /* =================================================================================
	Function Name: calcAve
	Function Description: returns the average of four integer scores
	Inputs: four integer scores
	Outputs: average of scores as a float
	Date: March 15th, 2023
	Update: o changed from variables to structure use 05/04/23
====================================================================================*/
void calcAve(struct Student *s, int numCurrentStudents)
{
    // Local Definitions ==============

    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
			s[row].avgScore = (s[row].scores[0] + s[row].scores[1] + s[row].scores[2] + s[row].scores[3]) / 4.0;
	}// for

    return ;
}// calcAve

/* =================================================================================
	Function Name: reportOutput
	Function Description: displays student information for the report
	Inputs: all information for a single student
	Outputs: None
	Date: March 15th, 2023
	Updates: o Initials were changed to full names 04/22/23
	         o Now sorts report by alphabetical order 04/24/23
	         o changed from variables to structure use 05/04/23
====================================================================================*/
void reportOutput(struct Student *s, int numCurrentStudents)
{
    // Sort students by last name
    for (int i = 0; i < numCurrentStudents - 1; i++) {
        for (int j = i + 1; j < numCurrentStudents; j++) {
            if (strcmp(s[i].lastName, s[j].lastName) > 0) {
                // Swap students
                struct Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display sorted students
    for (int row = 0; row < numCurrentStudents; row++) {
        printf("\n%-9s %-9s %-8d %-8d %-8d %-8d %-8d %-8.1d %-8.1d %-8.1f %-8c",
               s[row].lastName, s[row].firstName, s[row].studentID, s[row].scores[0], s[row].scores[1], s[row].scores[2], 
               s[row].scores[3], s[row].maxScore, s[row].minScore, s[row].avgScore, s[row].letterGrade);
    }
    
	return;
}// reportOutput

/* =================================================================================
	Function Name: findGrade
	Function Description: determines the letter grade based on student average
	Inputs: average
	Outputs: returns letter grade
	Date: March 15th, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void findGrade(struct Student *s, int numCurrentStudents)
{
    // Statements ================
	for (int row = 0; row < numCurrentStudents; row++)
	{
		// calculate the letter grade based on the average score
        if (s[row].avgScore >= 90)
        {
            s[row].letterGrade = 'A';
        }// if
        else if (s[row].avgScore >= 80)
        {
            s[row].letterGrade = 'B';
        }// else if
        else if (s[row].avgScore >= 70)
        {
            s[row].letterGrade = 'C';
        }// else if
        else if (s[row].avgScore >= 60)
        {
            s[row].letterGrade = 'D';
        }// else if
        else
        {
            s[row].letterGrade = 'F';
        }// else
	}// for
	
	return;
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

 /* =================================================================================
	Function Name: calcMinScore
	Function Description: calculates a student's min test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void calcMinScore(struct Student *s, int numCurrentStudents)
{
	// Local Definitions ==============
	int minScore = 101;
	
    // Statements ================
    for (int i = 0; i < numCurrentStudents; i++)
    {
        minScore = 101;
        for (int j = 0; j < NUM_SCORES; j++)
        {
            if (s[i].scores[j] < minScore)
            {
                minScore = s[i].scores[j];
            }// if
        }// for
        s[i].minScore = minScore;
    }// for

    return;
}// calcMinScore

 /* =================================================================================
	Function Name: calcMaxScore
	Function Description: calculates a student's max test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void calcMaxScore(struct Student *s, int numCurrentStudents)
{
	// Local Definitions ==============
	int maxScore = -99;

    // Statements ================
    for (int i = 0; i < numCurrentStudents; i++)
    {
        maxScore = -99;
        for (int j = 0; j < NUM_SCORES; j++)
        {
            if (s[i].scores[j] > maxScore)
            {
                maxScore = s[i].scores[j];
            }// if
        }// for
        s[i].maxScore = maxScore;
	}// for

    return;
}// calcMinScore

 /* =================================================================================
	Function Name: calcTestStatistics
	Function Description: calculates the max, min, and avergae for each test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void calcTestStatistics(struct Student *s, struct TestStats *ts, int numCurrentStudents) 
{
    // Local Definitions ==============
	int testSum = 0;
	
    // Statements
    for (int col = 0; col < NUM_SCORES; col++) 
    {
        // Set initial values
        ts[col].testMax = -1;
        ts[col].testMin = 101;
        // Check for new max and min; sum tests
        for (int row = 0; row < numCurrentStudents; row++) 
        {
            testSum += s[row].scores[col];
            // Check for new max
            if (s[row].scores[col] > ts[col].testMax) 
            {
                ts[col].testMax = s[row].scores[col];
            }// if
            // Check for new min
            if (s[row].scores[col] < ts[col].testMin) 
            {
                ts[col].testMin = s[row].scores[col];
            }// if
        }// for
        ts[col].testAvg = testSum / (float)numCurrentStudents;
        testSum = 0;
    }// for
    
    return;
}// calcTestStatistics

 /* =================================================================================
	Function Name: displayTestStatistics
	Function Description: displays the max, min, and avergae for each test score
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
	Update: o changed from variables to structure 05/04/23
====================================================================================*/
void displayTestStatistics(struct TestStats *ts)
{
    // Statements ================
    printf("\n\nTest Statistics\nTest Number    Max Score      Min Score       Average");

    for (int row = 0; row < NUM_SCORES; row++)
    {
        printf("\n    %-8d        %-8d         %-8d       %-8.1f", (row + 1), ts[row].testMax, ts[row].testMin, ts[row].testAvg);
    } // for
    return;
} // displayTestStatistics

 /* =================================================================================
	Function Name: searchForStudentID
	Function Description: gets student ID from user (with error-checking), searches for student and displays 
		an appropriate message if the student is not found, or the student ID, test scores, min, max, average and
		letter grade for the found student.
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 2nd, 2023
	Updates: o search now displays names 04/26/23
             o changed from variables to structure 05/04/23
====================================================================================*/
void searchForStudentID(struct Student *s, int numCurrentStudents)
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
        printf("\n\nEnter the student's ID to search for (use ] to quit): ");
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
        if (searchID == s[row].studentID)
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
            printf("\nReport is\nID       Last      First     Test1    Test2    Test3    Test4    High     Low      Ave      Grade");
            printf("\n%-8d %-9s %-9s %-8d %-8d %-8d %-8d %-8d %-8d %-8.1f %-8c", s[row].studentID, s[row].lastName, s[row].firstName,
                    s[row].scores[0], s[row].scores[1], s[row].scores[2], s[row].scores[3], s[row].maxScore,
                    s[row].minScore, s[row].avgScore, s[row].letterGrade);
        }// if
        else
        {
            printf("\nSubmitted Student ID not found...\n");
        }// else
    }// if
    
    return;
}// searchForStudentID

 /* =================================================================================
	Function Name: searchOptionsID
	Function Description: display stundents available for search
	Inputs: pass-by-reference pointers to student's data
	Outputs: None - uses pass-by-reference
	Date: April 30th, 2023
             o changed from variables to structure 05/04/23
====================================================================================*/
void searchOptionsID(struct Student *s, int numCurrentStudents)
{
    struct Student tempS[MAX_STUDENTS];
    // Sort students by last name
    for (int i = 0; i < numCurrentStudents-1; i++)
    {
        for (int j = i+1; j < numCurrentStudents; j++)
        {
            if (strcmp(s[i].lastName, s[j].lastName) > 0)
            {
                // Swap students
                tempS[i] = s[i];
                s[i] = s[j];
                s[j] = tempS[i];
            }// if
        }// for
    }// for

    // Display sorted students
    for (int row = 0; row < numCurrentStudents; row++)
    {
        printf("\n%-8d %-9s %-9s ", s[row].studentID, s[row].lastName, s[row].firstName);
    }//for
}// searchOptionsID
