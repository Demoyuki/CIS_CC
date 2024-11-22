/*	Write a program that changes a temperature reading from Fahrenheit to
		Celsius using the following formula:
			Celsius = (100 / 180) * (Fahrenheit - 32)
		You should prompt the user to enter a Fahrenheit temperature. It then 
		calculates the equivelent Celsius temperature and displays the results 
		as shown below:
			Enter the temerature in Fahrenheit: 98.6
			Fahrenheit temperature is: 98.6
			Celsius temperature is:    37.0
	Filename: lab33.c
	Written by: Dan Guilmette
	Date: February 1st, 2023
*/
#include <stdio.h>

int main (void)
{
	// Local Definitions
	float fahrenheit = 0.0;
	float celsius = 0.0;
		
	// Statements
	// user prompt for Fahrenheit
	printf("\nEnter the temperature in Fahrenheit: ");
	// get Fahrenheit temperature from user
	scanf("%f", &fahrenheit);
	// calculate Celsius temperature
	celsius = (100.0 / 180.0) * (fahrenheit - 32);
	// display results
	printf("\nFahrenheit temperature is: %6.1f", fahrenheit);
	printf("\nCelsius temperature is:    %6.1f", celsius);

	// end of program message
	printf("\nThis ends the program\n");
	
	return 0;
} // end of main