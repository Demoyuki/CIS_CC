/*	This  program creates a customer bill for a company that sells five different
		products: TV, VCR, Remote Controller, CD Player, and Tape Recorder.
		The program reads in the quantity of each piece of equipment purchased,
		then calculates the cost of each item, the subtotal, and the total cost after
		sales tax. It will then output the bill in a formatted output that is clear to read.
	Filename: assign03guilmette.c
	Written by: Dan Guilmette
	Date: 31 January 2023
*/

#include <stdio.h>

// Declarations==============================================
#define	UNIT_PRICE_TV 				400.00
#define	UNIT_PRICE_VCR 				220.00
#define	UNIT_PRICE_REMOTE 			35.20
#define	UNIT_PRICE_CD 				300.00
#define	UNIT_PRICE_TAPE_RECORDER	150.00
#define	SALES_TAX 					0.0825;		// 8.25% 

int main (void)
{
	// Local Declarations=========================================
	int soldTV			= 0;		// Number of TVs sold
	int soldVCR 		= 0; 		// Number of VCRs sold
	int soldRemote 		= 0; 		// Number of Remotes sold
	int soldCD 			= 0; 		// Number of CD players sold
	int soldTape	 	= 0;		// Number of Tape Recorders sold

	float totalPriceTV 			= 0.0; 	// Holds price * number sold of TVs
	float totalPriceVCR 		= 0.0; 	// Holds price * number sold of VCRs
	float totalPriceRemote 		= 0.0; 	// Holds price * number sold of Remotes
	float totalPriceCD 			= 0.0; 	// Holds price * number sold of CD players
	float totalPriceTape 		= 0.0; 	// Holds price * number sold of Tape Recorders

	float subtotal 		= 0.0; 		// Holds price before taxes applied
	float taxDue 		= 0.0; 		// Holds calculated tax
	float finalTotal 	= 0.0; 		// Holds subtotal + tax
	
	
	// Statements==========================================================
	
	// Read in how many units were sold for each piece of equipment
	printf("How Many TVs Were Sold? ");
	scanf(" %d", &soldTV);
	printf("How Many VCRs Were Sold? ");
	scanf(" %d", &soldVCR);
	printf("How Many Remote Controllers Were Sold? ");
	scanf(" %d", &soldRemote);
	printf("How Many CDs Were Sold? ");
	scanf(" %d", &soldCD);
	printf("How Many Tape Recorders Were Sold? ");
	scanf(" %d", &soldTape);
	
	// Calculate the cost of each item.
	totalPriceTV 		= UNIT_PRICE_TV * soldTV;
	totalPriceVCR 		= UNIT_PRICE_VCR * soldVCR;
	totalPriceRemote	= UNIT_PRICE_REMOTE * soldRemote;
	totalPriceCD		= UNIT_PRICE_CD * soldCD;
	totalPriceTape		= UNIT_PRICE_TAPE_RECORDER * soldTape;
	
	// Calculate the subtotal and sales tax
	subtotal = totalPriceCD + totalPriceRemote + totalPriceTV + totalPriceTape + totalPriceVCR;
	taxDue = subtotal * SALES_TAX;
	
	// Calculate the total cost after sales tax is added to the subtotal
	finalTotal	= subtotal + taxDue;
	
	
	// Output the results 
	
	// Print Report Header
	printf("\n\nQTY     DESCRIPTION     UNIT PRICE    TOTAL PRICE");
	printf("\n---     -----------     ----------    -----------\n");
	// Print the report
	printf("%-7d TV%24.2f%14.2f\n", soldTV, UNIT_PRICE_TV, totalPriceTV);
	printf("%-7d VCR%23.2f%14.2f\n", soldVCR, UNIT_PRICE_VCR, totalPriceVCR);
	printf("%-7d REMOTE CTRLR%14.2f%14.2f\n", soldRemote, UNIT_PRICE_REMOTE, totalPriceRemote);
	printf("%-7d CD PLAYER%17.2f%14.2f\n", soldCD, UNIT_PRICE_CD, totalPriceCD);
	printf("%-7d TAPE RECORDER%13.2f%14.2f\n", soldTape, UNIT_PRICE_TAPE_RECORDER, totalPriceTape);
	printf("                                       ---------\n");
	printf("                         SUBSTOTAL%14.2f\n", subtotal);
	printf("                         TAX%20.2f\n", taxDue);
	printf("                         TOTAL%18.2f\n\n", finalTotal);
	
	return 0;
} //main
