//Author: Frank Dong
//Purpose: To create a program which will calculate the multiplication, division, addition and difference
//		   of a 2 complex numbers.
//Date: Nov 30, 2016

#include <stdio.h> 
#include <stdlib.h>
#include "operation_function.h"

int main(int argc, char *argv[])
{
	//Variable declaration
	struct complex_tag c1;
	struct complex_tag c2;
	Complex_type mutiplyValue;
	struct complex_tag *divideValue = malloc((sizeof(struct complex_tag)));
	struct complex_tag *sumValue;
	struct complex_tag *diffValue;

	//Checks to see if there are valid amount of arguments
	if (argc != 5)
	{
		printf("Invalid number of arguments! (Exactly 4 arugments please)");
		exit (-1);
	}

	//Assigns each argument to a variable
	c1.real = atof(argv[1]);
	c1.imaginary = atof(argv[2]);
	c2.real = atof(argv[3]);
	c2.imaginary = atof(argv[4]);

	//Display the numbers user has entered
	printf("The first complex number you have entered is: %f + i(%f) \n", c1.real, c1.imaginary);
	printf("The second complex number you have entered is: %f + i(%f) \n", c2.real, c2.imaginary);
	printf("\n");

	//Calls multipy function and displays results
	mutiplyValue = multiply(c1, c2);
	printf("Multiplication: %f + i(%f) \n", mutiplyValue.real, mutiplyValue.imaginary);

	//If divide function produces error, return error message. Else display results
	if (divide(&c1, &c2, divideValue) == -2)
	{
		printf("Error in division \n");
	}
	else
	{
		divide(&c1, &c2, divideValue);
		printf("Division: %f + i(%f) \n", divideValue->real, divideValue->imaginary);
	}

	//Calls the add and subtract function, and displays results
	add_and_sub(c1, c2, &sumValue, &diffValue);
	printf("Addition: %f + i(%f) \n", sumValue->real, sumValue->imaginary);
	printf("Difference: %f + i(%f) \n", diffValue->real, diffValue->imaginary);
	printf("============================================================== \n");
	printf("\n");

	return 0;
}
