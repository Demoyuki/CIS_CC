/*	This program read a text file containing quiz and exam scores. The program will determine and display 
		the following:
			- High and low quiz score
			- High and low exam score
			- The overall average for all quizzes
			- The overall average for all exams
			- The overall class grade. The overall class grade is based on the following:
				- Quizzes are worth 60% of the course grade
				- Exams are worth 40% of the course grade
				- You must display the numeric grade (2 decimal places)
	Filename: midtermguilmette.c
	Written by: Dan Guilmette
	Date: March 26th, 2023
*/
#include <stdio.h>
#include <stdlib.h>

// Function Declarations ===========================================
void displayResults(int highQuiz, int lowQuiz, int highExam, int lowExam, float quizAvg,
									float examAvg, float classGrade, char letterGrade);
char calcLetterGrade(float classGrade);
void readData(int* highQuiz, int* lowQuiz, int* highExam, int* lowExam, float* quizAvg,
									float* examAvg, float* classGrade, int* totalQuiz, int* totalExam, int* count);
// end function declarations ========================================

int main(void)
{
	
	// Local Definitions
	int highQuiz = -1;
	int lowQuiz = 101;
	int highExam = -1;
	int lowExam = 101;
	int totalQuiz = 0;
	int totalExam = 0;
    float quizAvg = 0.0;
	float examAvg = 0.0;
	float classGrade = 0.0;
	char letterGrade = ' ';
	int count = 0;
	
	// Statements ================
	readData(&highQuiz, &lowQuiz, &highExam, &lowExam, &quizAvg,
									&examAvg, &classGrade, &totalQuiz, &totalExam, &count);
	
    quizAvg = (float)totalQuiz / (count * 3);
    examAvg = (float)totalExam / (count * 2);
    classGrade = quizAvg * 0.6 + examAvg * 0.4;
	
	letterGrade = calcLetterGrade(classGrade);
	
	displayResults(highQuiz, lowQuiz, highExam, lowExam, quizAvg, examAvg, classGrade, letterGrade);

	// end program
	printf("This ends our program\n");
	
    return 0;
}// main

/* =================================================================================
	Function Name: displayResults
	Function Description: displays the results of the grade calculations
	Inputs: highQuiz, lowQuiz, highExam, lowExam, quizAvg, examAvg, classGrade, letterGrade
	Outputs: None
	Date: March 26th, 2023
====================================================================================*/
void displayResults(int highQuiz, int lowQuiz, int highExam, int lowExam, float quizAvg,
									float examAvg, float classGrade, char letterGrade)
{
	// Local Definitions ==============
	
	// Statements ================
	printf("High quiz score: %d\n", highQuiz);
    printf("Low quiz score: %d\n", lowQuiz);
    printf("High exam score: %d\n", highExam);
    printf("Low exam score: %d\n", lowExam);
    printf("Overall average for all quizzes: %.2f\n", quizAvg);
    printf("Overall average for all exams: %.2f\n", examAvg);
    printf("Overall class grade: %.2f\n", classGrade);
	printf("Overall class letter grade: %c\n", letterGrade);

}// displayResults

/* =================================================================================
	Function Name: calcLetterGrade
	Function Description: determines the letter grade based on student average
	Inputs: classGrade
	Outputs: returns letter grade
	Date: March 26th, 2023
====================================================================================*/
char calcLetterGrade(float classGrade)
{
	// Local Definitions ==============
	char letterGrade = ' ';
	
	// Statements ================
	if (classGrade >= 90.0) {letterGrade = 'A';}// if
	else if (classGrade >= 80.0) {letterGrade = 'B';}// else if
	else if (classGrade >= 70.0) {letterGrade = 'C';}// else if
	else if (classGrade >= 60.0) {letterGrade = 'D';}// else if
	else {letterGrade = 'F';}// else
	
	return letterGrade;
}// calcLetterGrade

/* =================================================================================
	Function Name: readData
	Function Description: reads quiz and exam data from file
	Inputs: pointers to highQuiz, lowQuiz, highExam, int* lowExam, float* quizAvg,
									float* examAvg, float* classGrade, int* totalQuiz, int* totalExam, int* count
	Outputs: returns letter grade
	Date: March 15th, 2023
====================================================================================*/
void readData(int* highQuiz, int* lowQuiz, int* highExam, int* lowExam, float* quizAvg,
									float* examAvg, float* classGrade, int* totalQuiz, int* totalExam, int* count)
{
	// Local Definitions ==============
	FILE *fp;
	int quiz1 = 0;
	int quiz2 = 0;
	int quiz3 = 0;
	int exam1 = 0;
	int exam2 = 0;
	
	// Statements ================
	 fp = fopen("studentData.txt", "r");
	
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(100);
    }// if

    while (fscanf(fp, "%d,%d,%d,%d,%d", &quiz1, &quiz2, &quiz3, &exam1, &exam2) != EOF)
    {
        if (quiz1 > *highQuiz) {*highQuiz = quiz1;}
        if (quiz1 < *lowQuiz) {*lowQuiz = quiz1;}
        if (quiz2 > *highQuiz) {*highQuiz = quiz2;}
        if (quiz2 < *lowQuiz) {*lowQuiz = quiz2;}
        if (quiz3 > *highQuiz) {*highQuiz = quiz3;}
        if (quiz3 < *lowQuiz) {*lowQuiz = quiz3;}
        if (exam1 > *highExam) {*highExam = exam1;}
        if (exam1 < *lowExam) {*lowExam = exam1;}
        if (exam2 > *highExam) {*highExam = exam2;}
        if (exam2 < *lowExam) {*lowExam = exam2;}
        *totalQuiz += quiz1 + quiz2 + quiz3;
        *totalExam += exam1 + exam2;
        (*count)++;
    }// while
	
	fclose(fp);

}// readData