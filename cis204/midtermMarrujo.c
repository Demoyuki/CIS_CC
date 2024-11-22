/* ========================================================
   ||	C program that:																						||
   ||		● Reads a file located in the same directory as the C program.			||
   ||		● Each line of data file contains 3 quiz scores, 2 exam scores - 		||
   ||				example: 78, 88, 67, 99, 79															||
   ||		● Gathered all the info from file and calculate and display:				||
   ||			○ High and low quiz score																||
   ||			○ High and low exam score															||
   ||			○ The overall average for all quizzes												||
   ||			○ The overall average for all exams												||
   ||			○ The overall class grade. 																||
   ||		The overall class grade is based on the following:								||
   ||			■ Quizzes are worth 60% of the course grade								||
   ||			■ Exams are worth 40% of the course grade									||
   ||			■ You must display the numeric grade (2 decimal places)				||
   ||			■ You must also display the course letter grade 							||
   ||======================================================||
   ||	fileName: midtermMarrujo.c 																	||
   ||	Written by: Victor Marrujo																		||
   ||	Date: 22 March 2023 - 27 March 2023													||
   ========================================================
*/
#include <stdio.h>
#include <stdlib.h>

// Function Declarations ==============================================
	char calculateLetter(float classGrade);
	void printResults(int quizHigh, int quizLow, int examHigh, int examLow, 
								float quizAvg, float examAvg, float classGrade, 
								char letterGrade);
	void importAndCalculateData(char* filename, int* quizHigh, int* quizLow, 
													int* examHigh, int* examLow, float* quizAvg, 
													float* examAvg, float* classGrade);
// End function declarations ============================================

// Start of Main  =====================================================							
int main(void) 
{
  	// Local Definitions  ================================================
		char* filename = "studentData.txt";
		int quizHigh = 0;
		int quizLow = 100;
		int examHigh = 0; 
		int examLow = 100;
		float quizAvg = 0.00; 
		float examAvg = 0.00; 
		float classGrade = 0.00;
		char letterGrade = ' ';
	// Statements  ====================================================
	// Browse studentData.txt to determine highs, lows, averages and class grades
		importAndCalculateData(filename, &quizHigh, &quizLow, &examHigh, &examLow, 
								&quizAvg, &examAvg, &classGrade);
	// Calculate letterGrade	============================================	
		letterGrade = calculateLetter(classGrade);
	// Print report  ====================================================
		printResults(quizHigh, quizLow, examHigh, examLow, quizAvg, examAvg, 
							classGrade, letterGrade);
	
	// End of program =================================================
		printf("\nThe program has successfully ended\n");
    return 0;
}// End of Main Overall  ====================================================

/*  
	=======================================================
   ||	Function Name: importAndCalculateData												||
   ||======================================================||
   ||	Function Description:																				||
   ||		o Calculates highest, lowest, average and class grades					||
   ||======================================================||
   ||	Inputs: 																									||
   ||		o Reads quizez and exams from file, alongside the empty highs, 		||
   ||			lows and averages.																			||
   ||======================================================||
   ||	Outputs: 																									||
   ||       o returns void; reads input data using pass by reference			        ||
   ||======================================================||
   ||	Date: 22 March 2023 - 27 March 2023													||
	=======================================================
*/
void importAndCalculateData(char* filename, int* quizHigh, int* quizLow, 
												int* examHigh, int* examLow, float* quizAvg, 
												float* examAvg, float* classGrade) 
{
    int quiz1 = 0, quiz2 = 0, quiz3 = 0; //can declare vairables in sequence if same type!
	int exam1 = 0, exam2 = 0;
    int quizTotal = 0, examTotal = 0;
    int numStudents = 0;
    float quizPercent = 0.6, examPercent = 0.4;

    FILE* spIN = fopen(filename, "r");
    if (spIN == NULL) 
	{
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }// if spIN

	while (fscanf(spIN, "%d,%d,%d,%d,%d", &quiz1, &quiz2, &quiz3, &exam1, &exam2) != EOF) 
	{
		// Find quizHigh =================================================
			if (quiz1 > *quizHigh) 
			{
				*quizHigh = quiz1;
			}// if quizHign1
			if (quiz2 > *quizHigh) 
			{
				*quizHigh = quiz2;
			}// if quizHign2
			if (quiz3 > *quizHigh) 
			{
				*quizHigh = quiz3;
			}// if quizHign3 
			
		// Find quizLow =================================================
			if (quiz1 < *quizLow) 
			{
				*quizLow = quiz1;
			}// if quizLow1
			if (quiz2 < *quizLow) 
			{
				*quizLow = quiz2;
			}// if quizLow2
			if (quiz3 < *quizLow) 
			{
				*quizLow = quiz3;
			}// if quizLow3
		// Find examHigh ================================================
			if (exam1 > *examHigh)
			{
				*examHigh = exam1;
			}// if examHigh1
			if (exam2 > *examHigh) 
			{
				*examHigh = exam2;
			}// if examHigh2
		// Find quizLow =================================================
			if (exam1 < *examLow) 
			{
				*examLow = exam1;
			}// if examLow1
			if (exam2 < *examLow) 
			{
				*examLow = exam2;
			}// if examLow2

		// Calculate quiz and exam totals, plus keep track of student total
			quizTotal += quiz1 + quiz2 + quiz3;
			examTotal += exam1 + exam2;
			numStudents++;
		}// while fscanf
		
	// Calculate quiz and exam averages ===================================
		*quizAvg = (float) quizTotal / (numStudents * 3);
		*examAvg = (float) examTotal / (numStudents * 2);
	// Calculate class overall grade  =======================================
		*classGrade = (*quizAvg * quizPercent) + (*examAvg * examPercent);
	// Close file		
		fclose(spIN);
}// importAndCalculateData

/*  
	=======================================================
   ||	Function Name: calculateLetter																||
   ||======================================================||
   ||	Function Description:																				||
   ||		o Calculates class lettergrade 															||
   ||======================================================||
   ||	Inputs: 																									||
   ||		o Class overall grade																			||
   ||======================================================||
   ||	Outputs: 																									||
   ||       o returns char; returns leter grade value									        ||
   ||======================================================||
   ||	Date: 22 March 2023 																				||
	=======================================================
*/
char calculateLetter(float classGrade)
{
	if (classGrade >= 90) 
	{
		return 'A';
	}	else if (classGrade >= 80) 
		{
			return 'B';
		} 	else if (classGrade >= 70) 
			{
				return 'C';
			} 	else 
				{
					return 'F';
				}

}// calculateLetter

/*  
	=======================================================
   ||	Function Name: printResults																	||
   ||======================================================||
   ||	Function Description:																				||
   ||		o Prints highest, lowest, averages and overall grades						||
   ||======================================================||
   ||	Inputs: 																									||
   ||		o All highest, lowest, averages and overall grades	for quizzes 			||
   || 			and exams.																						||
   ||======================================================||
   ||	Outputs: 																									||
   ||       o returns void; only prints data 													        ||
   ||======================================================||
   ||	Date: 23 March 2023 																				||
	=======================================================
*/
void printResults(int quizHigh, int quizLow, int examHigh, int examLow, float quizAvg,
							float examAvg, float classGrade, char letterGrade) 
{
	printf("Quiz Highest: %d\n", quizHigh);
	printf("Quiz Lowest: %d\n", quizLow);
	printf("Exam Highest: %d\n", examHigh);
	printf("Exam Lowest: %d\n", examLow);
	printf("Overall quiz average: %.2f\n", quizAvg);
	printf("Overall exam average: %.2f\n", examAvg);
	printf("Overall class grade: %.2f (%c)\n", classGrade, letterGrade);
}// printResults