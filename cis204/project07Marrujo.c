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
   ||	Date: 30 February 2023 - 22 March 2023												||
   ========================================================
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Function Declarations ================================================
	void appendData(char* fileName, char* lastName4, char* firstName4, int* id4, int* test4_1, 
            int* test4_2, int* test4_3, int* test4_4, float** fourthHigh, float* fourthLow, 
            char* lastName5, char* firstName5, int* id5, int* test5_1, int* test5_2, 
            int* test5_3, int* test5_4, float* fifthHigh, float*fifthLow);
	

	void getData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1, 
			int* pTest2, int* pTest3, int* pTest4, float* pHigh, float* pLow);
		
	void displayStudentInfo(char lastName, char firstName, int id, int test1, 
			int test2, int test3, int test4, float high, float low, float average, char grade);
			
	float calcAverage(int test1, int test2, int test3, int test4, float numTests);
			
	char calcLetterGrade(float average);
		
//	void readFile(char* fileName);
	
	void checkChar (char* test);
	
	void checkDigit (int* test);
	
	void checkDigitF (float* test);
	
// End function declarations 	===========================================

// Start of main =======================================================
int main(void)
{
	// Local Definitions ==================================================
	// menu options
		int menu = 0;
        char quit = ' ';
		char fileName[100];
		
	// number of tests
		float  numTests = 4.0;	
	
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
		char firstGrade = ' ';
		
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
		char secondGrade = ' ';
		
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
		char thirdGrade = ' ';
		
	// fourth student
		char lastName4 = ' ';
		char firstName4 = ' ';
		int id4 = 0;
		int test4_1 = 0;
		int test4_2 = 0;
		int test4_3 = 0;
		int test4_4 = 0;
		float fourthHigh = 0.0;
		float fourthLow = 0.0;
		float fourthAve = 0.0;
		char fourthGrade = ' ';
		
	// fifth student
		char lastName5 = ' ';
		char firstName5 = ' ';
		int id5 = 0;
		int test5_1 = 0;
		int test5_2 = 0;
		int test5_3 = 0;
		int test5_4 = 0;
		float fifthHigh = 0.0;
		float fifthLow = 0.0;
		float fifthAve = 0.0;
		char fifthGrade = ' ';
	
	// Statements ============================================================
		printf("Welcome to the student report\n");
	
	//Input file 
		printf("Enter fileName: ");
		scanf("%s", fileName);
//		readFile(fileName);
		
	//Menu
		while(menu!=3)
		{
			printf("\nMenu: Make a Choice\n");
			printf("1. Display report\n");
			printf("2. Add fourth and fifth student\n");
			printf("3. Exit program\n");
			printf("\nMake a choice (1,2 or 3): ");
			scanf("%d", &menu);
			
			switch (menu)
			{
				// Display report
				case 1:  
								//=======================================================================								
								// Calcluate the first student's average
									firstAve = calcAverage(test1_1, test1_2, test1_3, test1_4, numTests);
								// Calcluate the second student's average
									secondAve = calcAverage(test2_1, test2_2, test2_3, test2_4, numTests);
								// Calcluate the third student's average
									thirdAve = calcAverage(test3_1, test3_2, test3_3, test3_4, numTests);
								// Calcluate the fourth student's average
									fourthAve = calcAverage(test4_1, test4_2, test4_3, test4_4, numTests);
								// Calcluate the fifth student's average
									fifthAve = calcAverage(test5_1, test5_2, test5_3, test5_4, numTests);			
									
								//=======================================================================					
								// Calcluate the first student's letter grade
									firstGrade = calcLetterGrade(firstAve);
								// Calcluate the second student's letter grade
									secondGrade = calcLetterGrade(secondAve);
								// Calcluate the third student's letter grade
									thirdGrade = calcLetterGrade(thirdAve);
								// Calcluate the fourth student's letter grade
									fourthGrade = calcLetterGrade(fourthAve);
								// Calcluate the fifth student's letter grade
									fifthGrade = calcLetterGrade(fifthAve);		
									
								//=======================================================================
								// Display Report Header
									printf ("Last   First   ID   Test1   Test2   Test3   Test4   High   Low   Ave   Grade\n");
	
								// Display the first student's data
									displayStudentInfo(lastName1, firstName1, id1, test1_1, test1_2, 
										test1_3, test1_4, firstHigh, firstLow, firstAve, firstGrade);
								// Display the second student's data
									displayStudentInfo(lastName2, firstName2, id2, test2_1, test2_2, 
										test2_3, test2_4, secondHigh, secondLow, secondAve, secondGrade);
								// Display the third student's data
									displayStudentInfo(lastName3, firstName3, id3, test3_1, test3_2, 
										test3_3, test3_4, thirdHigh, thirdLow, thirdAve, thirdGrade);
								//Check if fourth student was input
									if(id4 > 0)
									{
										// Display the fourth student's data
										displayStudentInfo(lastName4, firstName4, id4, test4_1, test4_2, 
											test4_3, test4_4, fourthHigh, fourthLow, fourthAve, fourthGrade);
									}
								//Check if fifth student was input
									if(id5 > 0)
									{
										// Display the fifth student's data
										displayStudentInfo(lastName5, firstName5, id5, test5_1, test5_2, 
											test5_3, test5_4, fifthHigh, fifthLow, fifthAve, fifthGrade);
									}
								//=======================================================================
								break;
				//Add a student
				case 2:		
								//=======================================================================							
								while (quit != 'y')
                                {
                                // Prompt and get the fourth student's data
									getData(&lastName4, &firstName4, &id4, &test4_1, &test4_2, 
										&test4_3, &test4_4, &fourthHigh, &fourthLow);
								// Prompt and get the fifth student's data
									getData(&lastName5, &firstName5, &id5, &test5_1, &test5_2, 
										&test5_3, &test5_4, &fifthHigh, &fifthLow);
                                // Quit instruction
                                    printf("Would you like to re-enter data (y or n): ");
                                    scanf("%c", quit);
                                }
								//=======================================================================

								break;
				//Exit program
				case 3:	printf("Ending program...\n");
                        printf("Adding 4th and 5th student data to input file.");
                        appendData(fileName, &lastName4, &firstName4, &id4, &test4_1, &test4_2, 
										&test4_3, &test4_4, &fourthHigh, &fourthLow,
                                   &lastName5, &firstName5, &id5, &test5_1, &test5_2, 
										&test5_3, &test5_4, &fifthHigh, &fifthLow);
								break;
				default:	printf("Please enter a valid option.\n");
			}
		}

	// End of program
		printf("\nThe program has successfully ended\n");
	
	return 0;
}// End of main =============================================================

/*  
   ========================================================
   ||	Function Name: checkChar																    ||
   ||======================================================||
   ||	Function Description:																				||
   ||		o Checks if input char is alphabetical											 		||
   ||======================================================||
   ||	Inputs: 																							 		||
   ||		o test																						 	 		||
   ||======================================================||
   ||	Outputs: 																							 		||
   ||       o returns void; only verifies input			     										||
   ||======================================================||
   ||	Date: 15 March 2023 								 												||
   ========================================================
*/
void checkChar (char* test)
{
	if (isalpha(test)) 
	{
        test = toupper(test);
        return;
	} else 
		{
			printf("%c is not a character, please re-enter data.\n", test);
		}
    return;
}//checkChar 

/*  
   ======================================================
   ||	Function Name: checkDigit																	||
   ||====================================================||
   ||	Function Description:																		  	||
   ||		o Checks if input integer is a digit											 	 	||
   ||====================================================||
   ||	Inputs: 																							 	||
   ||		o test																						     	||
   ||====================================================||
   ||	Outputs: 																							 	||
   ||       o returns void; only verifies input			     									||
   ||====================================================||
   ||	Date: 15 March 2023 																			||
   ======================================================
*/
void checkDigit (int* test)
{
	if (isdigit(test)) 
	{
        if (test>0)
        {
            if (test<100)
            {
            } else
                {
                    printf("%d is not between 0-100, please re-enter data.\n", test);
                }
        }else
         {
             printf("%d is not between 0-100, please re-enter data.\n", test);
         }
        return;
	} else 
		{
			printf("%d is not an integer, please re-enter data.\n", test);
		}
	return;
}//checkDigit

/*  
   ======================================================
   ||	Function Name: checkDigitF																||
   ||====================================================||
   ||	Function Description:																		 	||
   ||		o Checks if input float is a digit											 			||
   ||====================================================||
   ||	Inputs: 																							 	||
   ||		o test																						 	 	||
   ||====================================================||
   ||	Outputs: 																							 	||
   ||       o returns void; only verifies input			     									||
   ||====================================================||
   ||	Date: 15 March 2023 								 											||
   ======================================================
*/
void checkDigitF (float* test)
{
	if (isdigit(test)) 
	{
         if (test>0)
        {
            if (test<100)
            {
            } else
                {
                    printf("%.2f is not between 0-100, please re-enter data.\n", test);
                }
        }else
         {
             printf("%.2f is not between 0-100, please re-enter data.\n", test);
         }
        return;
	} else 
		{
			printf("%.2f is not a float, please re-enter data.\n", test);
		}
	return;
}//checkDigitF
/*  
	=======================================================
   ||	Function Name: getData																	 ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||		o Asks the user for the required data											 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o None																						 	 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o returns void; reads input data using pass by reference			     ||
   ||======================================================||
   ||	Date: 11 February 2023 - 28 February 2023									 ||
	=======================================================
*/
void getData(char* pLastName1, char* pFirstName1, int* pId1, int* pTest1, 
					 int* pTest2, int* pTest3, int* pTest4, float* pHigh, float* pLow)
{
	// Prompting user for student info =============================================
	printf("Please enter the next student's data all on one line in the sequence\n");
	scanf(" %c,%c,%d,%d,%d,%d,%d,%f,%f", pLastName1, pFirstName1, pId1, 
				pTest1, pTest2, pTest3, pTest4, pHigh, pLow);
	
	// Char verification ========================================================
	checkChar(pLastName1);
	checkChar(pFirstName1);
	// Int verification ==========================================================	
	checkDigit(pId1);
	checkDigit(pTest1);
	checkDigit(pTest2);
	checkDigit(pTest3);
	checkDigit(pTest4);
	checkDigitF(pHigh);
	checkDigitF(pLow);
}// getData

/*  
	=======================================================
   ||	Function Name: calcAverage														 	 ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||		o Calculates the average test score for a student						 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o All four student test scores, the number of tests						 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o returns float; average of the submitted scores						     ||
   ||======================================================||
   ||	Date: 11 February 2023 - 28 February 2023									 ||
	=======================================================
*/
float calcAverage(int test1, int test2, int test3, int test4, float numTests)
{
	float tempAverage = 0.0;
	tempAverage = (float)(test1 + test2 + test3 + test4) / numTests;

	return tempAverage;
}// calcAverage

/*  
	=======================================================
   ||	Function Name: displayStudentInfo												     ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||		o displays the information for one student									 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o Integers - all four test scores													 ||
   ||		o Chars - last and first name														 ||
   ||		o Floats - high, low, and average score										 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o returns void; displays the information		     							 ||
   ||======================================================||
   ||	Date: 11 February 2023 - 28 February 2023									 ||
	=======================================================
*/
void displayStudentInfo(char lastName, char firstName, int id, int test1, 
									  int test2, int test3, int test4, float high, float low, 
									  float average, char grade)
{
	printf("%c%7c%11d%3d%8d%8d%8d%8.0f%7.0f%8.1f%3c\n", 
				lastName, firstName, id, test1, test2, test3, test4, high, 
				low, average, grade);

	return;
}// displayStudentInfo

/*  =======================================================
   ||	Function Name: calcLetterGrade														 ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||	o Determines student's letter grade based on their average score	 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o float - average																			 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o returns char; Return the letter grade									         ||
   ||======================================================||
   ||	Date: 28 February 2023 																     ||
	=======================================================
*/
char calcLetterGrade(float average)
{
	if (average <= 69) 																
	{
        return 'F';
	} 
	else if (average <= 79) 							
		{
			return 'C';
		} 
		else if (average <= 89) 													
			{
				return 'B';
			} 
			else 
				{
					return 'A';
				}
}//calcLetterGrade

/*  =======================================================
   ||	Function Name: appendData														 ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||	o Appends data from 4th and 5th student into input file	 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o fileName, alongisde all of the 4th and 5th students data											 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o returns voir; only appends data									         ||
   ||======================================================||
   ||	Date: 06 March 2023 - 22 March 2023 											 ||
	=======================================================
*/
void appendData(char* fileName, char* lastName4, char* firstName4, int* id4, int* test4_1, int* test4_2, 
				int* test4_3, int* test4_4, float** fourthHigh, float* fourthLow, 
                char* lastName5, char* firstName5, int* id5, int* test5_1, int* test5_2, 
				int* test5_3, int* test5_4, float* fifthHigh, float*fifthLow)
{
    FILE *spIn;
    spIn = fopen(fileName, "a");  // open the file in "append" mode
    if (spIn == NULL) 
    {
        printf("Append file not found\n");
    }
    // Append data to file
    fprintf(spIn, " %c,%c,%d,%d,%d,%d,%d,%f,%f", lastName4, firstName4, id4, test4_1, test4_2, 
                                               test4_3, test4_4, fourthHigh, fourthLow);
	fprintf(spIn, " %c,%c,%d,%d,%d,%d,%d,%f,%f", lastName5, firstName5, id5, test5_1, test5_2, 
                                               test5_3, test5_4, fifthHigh, fifthLow);
    fclose(spIn);  // close the file
    
    return 0;
}//appendData
/*  =======================================================
   ||	Function Name: readFile																	 ||
   ||======================================================||
   ||	Function Description:																		 ||
   ||	o  Read initial input for the first 3 students from a file 						 ||
   ||======================================================||
   ||	Inputs: 																							 ||
   ||		o 																									 ||
   ||======================================================||
   ||	Outputs: 																							 ||
   ||       o																							         ||
   ||======================================================||
   ||	Date: 06 March 2023 - 22 March 2023 											 ||
	=======================================================
*//*
void readFile(char* fileName, char* pLastName, char* pFirstName, 
					  int* pId, int* pTest1, int* pTest2, int* pTest3, 
					  int* pTest4, float* pHign, float* pLow)
{
	FILE *spIn;
	char currentChar = ' ';
	spIn = fopen(fileName, "r");
// Open file
	if (spIn == NULL)
	{
		printf("Input file not found\n");
	} //If file not found
	
	
// Count the number of students in the file
    while (fscanf(spIn, "%c %c %d", fileName, pLastName, pFirstName, pId, pTest1, pTest2, pTest3, pTest4, pHigh, pLow) == 9)
	{
    }
	//Read until EOF and Process characters
		while((currentChar = fgetc(spIn)) != EOF )
		{
		}//while
		
	//Close files
		fclose(spIn);
		
		FILE *spOut;
		char *outputFile = "temp.txt";	
	//Open OutputFile(w)
		if(!(spIn = fopen(fileName, "w")))
		{
			printf("Input file not found\n");
			return;
		}//if fails
		fclose(spOut);
	return;
}//readFile
*/

