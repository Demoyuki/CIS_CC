/* Creates a customer's bill for a carpet company when given the 
		- length and width of the carpet in feet
		- the carpet price per square foot
		- the percent discount for each customer
	Filename: assign04guilmette.c
	Written by: Dan Guilmette
	Date: February 6th, 2023
*/
#include <stdio.h>

// Function Declarations ====================================================================
void getData(int* pRoomLength, int* pRoomWidth, int* custDiscount, float* pCostPerSqFt);
void calculateValues(int roomLength, int roomWidth, int custDiscount, float costPerSqFt, int* pRoomArea, float* pCarpetCost, 
									float* pLaborCost,	float* pInstalledPrice, float* pDiscountTotal, float* pSubTotal, float* pTotalPrice, float* pTax);
void calculateInstalledPrice(int roomLength, int roomWidth, float costPerSqFt, int* pRoomArea, float* pCarpetCost, 
												float* pLaborCost,	float* pInstalledPrice);
void calculateSubtotal( float* pSubTotal, float custDiscount, float* pDiscountTotal, float* pInstalledPrice);
void calculateTotal( float* pSubTotal, float* pTax, float* pTotalPrice);
void printMeasurements( int roomLength, int roomWidth, int roomArea );
void printCharges( float costPerSqFt, float carpetCost, float laborCost, float installedPrice, int custDiscount, float discountTotal, 
							float subTotal, float tax, float totalPrice );
void printBill( int roomLength, int roomWidth, int roomArea, float costPerSqFt, float carpetCost, float laborCost, float installedPrice, int custDiscount, 
					float discountTotal, float subTotal, float tax, float totalPrice );						
// end function declarations ==================================================================

// Global Declarations
#define	LABOR_COST	0.35
#define 	TAX_RATE		0.085	// rate = 8.5%

int main (void)
{

	// Local Definitions
	int roomLength = 0;
	int roomWidth = 0;
	int custDiscount = 0;
	float costPerSqFt = 0.0;
	int roomArea = 0.0;
	float carpetCost = 0.0;
	float laborCost = 0.0;
	float installedPrice = 0.0;
	float discountTotal = 0.0;
	float subTotal = 0.0;
	float totalPrice = 0.0;
	float tax = 0.0;
		
	// Statements
	getData(&roomLength, &roomWidth, &custDiscount, &costPerSqFt);
	calculateValues(roomLength, roomWidth, custDiscount, costPerSqFt, &roomArea, &carpetCost, 
									&laborCost,	&installedPrice, &discountTotal, &subTotal, &totalPrice, &tax);
	printBill( roomLength, roomWidth, roomArea, costPerSqFt, carpetCost, laborCost, installedPrice, custDiscount, 
				discountTotal, subTotal, tax, totalPrice );
	
	// end of program
	printf("The program has successfully ended\n");
	
	return 0;
} // end of main

/* =================================================================================
	Function Name: getData
	Function Description: asks the user for the length and width of the carpet, the carpet price per square foot, 
		and the percent discount for the customer.
	Inputs: the address of the four variables
	Outputs: none - the values are changed using pass-by-reference
	Date: February 6th, 2023
====================================================================================*/
void getData(int* pRoomLength, int* pRoomWidth, int* pCustDiscount, float* pCostPerSqFt)
{
	printf("Please enter the room length (ex: 5): ");
	scanf(" %d", pRoomLength);
	printf("Please enter the room width (ex: 5): ");
	scanf(" %d", pRoomWidth);
	printf("Please enter the customer discount (ex: 10): ");
	scanf(" %d", pCustDiscount);
	printf("Please enter the cost per square foot (ex: 4.79): ");
	scanf(" %f", pCostPerSqFt);
	return;
}// getData

/* =================================================================================
	Function Name: calculateValues
	Function Description: This function calls 4 other functions to perform all calculations. Since other functions 
		will display the results, we need to pass-by-reference all the calculater variables.
	Inputs: See function declaration
	Outputs: none - the values are changed using pass-by-reference
	Date: February 6th, 2023
====================================================================================*/
void calculateValues(int roomLength, int roomWidth, int custDiscount, float costPerSqFt, int* pRoomArea, float* pCarpetCost, 
										float* pLaborCost,	float* pInstalledPrice, float* pDiscountTotal, float* pSubTotal, float* pTotalPrice, float* pTax)
{
	calculateInstalledPrice(roomLength, roomWidth, costPerSqFt, pRoomArea, pCarpetCost, 
												pLaborCost,	pInstalledPrice);

	calculateSubtotal( pSubTotal, custDiscount, pDiscountTotal, pInstalledPrice);
	calculateTotal( pSubTotal, pTax, pTotalPrice);
	
	return;
}// calculateValues

/* =================================================================================
	Function Name: calculateInstalledPrice
	Function Description: calculates the area, carpet cost, labor cost, and installed price
	Inputs: See function declaration
	Outputs: none - the values are changed using pass-by-reference
	Date: February 6th, 2023
====================================================================================*/
void calculateInstalledPrice(int roomLength, int roomWidth, float costPerSqFt, int* pRoomArea, float* pCarpetCost, 
												float* pLaborCost,	float* pInstalledPrice)
{
	// calculate area
	*pRoomArea = roomLength * roomWidth;
	// calculate carpet costs
	*pCarpetCost = *pRoomArea * costPerSqFt;
	// calculate labor costs
	*pLaborCost = LABOR_COST * *pRoomArea;
	// calculate installed price (materials + labor)
	*pInstalledPrice = *pCarpetCost + *pLaborCost;	
	return;
}// calculateInstalledPrice


/* =================================================================================
	Function Name: calculateSubtotal
	Function Description: uses the installed proce and teh discount to calculate the order subtotal
	Inputs: customer discount and installed price
	Outputs: returns the subtotal with the applied discount
	Date: February 6th, 2023
====================================================================================*/
void calculateSubtotal( float* pSubTotal, float custDiscount, float* pDiscountTotal, float* pInstalledPrice)
{
	*pDiscountTotal = (custDiscount / 100) * (*pInstalledPrice);
	*pSubTotal = *pInstalledPrice - *pDiscountTotal;
		
	return;
}// calculateSubtotal

/* =================================================================================
	Function Name: calculateTotal
	Function Description: calculates the total tax and the total price
	Inputs: customer discount and installed price
	Outputs: none - the values are changed using pass-by-reference
	Date: February 6th, 2023
====================================================================================*/
void calculateTotal( float* pSubTotal, float* pTax, float* pTotalPrice)
{
	// calculate tax
	*pTax = TAX_RATE * (*pSubTotal);
	// calculate total price
	*pTotalPrice = *pTax + *pSubTotal;
	
	return;
}// calculateSubtotal

/* =================================================================================
	Function Name: printMeasurements
	Function Description: displays the order measurements
	Inputs: room length, width, and area
	Outputs: none
	Date: February 6th, 2023
====================================================================================*/
void printMeasurements( int roomLength, int roomWidth, int roomArea )
{
	printf("\n                MEASUREMENTS                \n");
	printf("\nLength                           %3d ft", roomLength);
	printf("\nWidth                            %3d ft", roomWidth);
	printf("\nArea                             %3d square ft\n\n", roomArea);
	
	return;
}// printMeasurements

/* =================================================================================
	Function Name: printCharges
	Function Description: displays the various order charges
	Inputs: see function header
	Outputs: none
	Date: February 6th, 2023
====================================================================================*/
void printCharges( float costPerSqFt, float carpetCost, float laborCost, float installedPrice, int custDiscount, float discountTotal, 
							float subTotal, float tax, float totalPrice )
{
	printf("\n                  CHARGES                   \n");
	printf("\nDESCRIPTION  COST/SQ.FT.      CHARGE ");
	printf("\n-----------  -----------  -----------");
	printf("\nCarpet         %6.2f        $%7.2f", costPerSqFt, carpetCost);
	printf("\nLabor            0.35         %7.2f", laborCost);
	printf("\n                          -----------");
	printf("\nINSTALLED PRICE              $%7.2f", installedPrice);
	printf("\nDiscount           %2d%%        %7.2f", custDiscount, discountTotal);
	printf("\n                          -----------");
	printf("\nSUBTOTAL                     $%7.2f", subTotal);
	printf("\nTax                           %7.2f", tax);
	printf("\nTOTAL                        $%7.2f", totalPrice);
	printf("\n\n");
	
	return;
}	// printCharges

/* =================================================================================
	Function Name: printBill
	Function Description: displays order measurements and charges
	Inputs: see function header
	Outputs: none
	Date: February 6th, 2023
====================================================================================*/
void printBill( int roomLength, int roomWidth, int roomArea, float costPerSqFt, float carpetCost, float laborCost, float installedPrice, int custDiscount, 
					float discountTotal, float subTotal, float tax, float totalPrice )	
{
	printMeasurements( roomLength, roomWidth, roomArea );
	
	printCharges( costPerSqFt, carpetCost, laborCost, installedPrice, custDiscount, discountTotal, subTotal, tax, totalPrice );
	
	return;
}// printBill	