//Author: Frank Dong
//Purpose: To create a the functions which will calculate the multiplication, division, addition and difference
//		   of a 2 complex numbers.
//Date: Nov 30, 2016

#include <stdio.h> 
#include <stdlib.h>
#include "operation_function.h"

/*
Name: Frank Dong
Date: Nov 29, 2016
Purpose: Multiply function which will calculate the multiplication of 2 complex numbers
Input: complex_tag c1 & complex_tag c2
Output: value (Complex_type)
*/
Complex_type multiply(struct complex_tag c1, struct complex_tag c2)
{
	//Declaration of return variable
	Complex_type value;

	//Multiplication Calculation
	value.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
	value.imaginary = c2.real * c1.imaginary + c1.real * c2.imaginary;

	return value;
}

/*
Name: Frank Dong
Date: Nov 29, 2016
Purpose: Divide function which will calculate the division of 2 complex numbers
Input: complex_tag *c1, complex_tag *c2, complex_tag *result
Output: -2 (if error) or 0 | calculated value is returned through pointer
*/
int divide(struct complex_tag *c1, struct complex_tag *c2, struct complex_tag *result)
{
	//If a2^2 + b2^2 = 0 return error
	if (c2->real * c2->real + c2->imaginary * c2->imaginary == 0)
	{
		return -2;
	}

	//Else division calculation and return 0
	result->real = (c1->real * c2->real + c1->imaginary * c2->imaginary) / (c2->real * c2->real + c2->imaginary * c2->imaginary);
	result->imaginary = (c2->real * c1->imaginary - c1->real * c2->imaginary) / (c2->real * c2->real + c2->imaginary * c2->imaginary);
	return 0;
}

/*
Name: Frank Dong
Date: Nov 29, 2016
Purpose: add and subtract function which will calculate the addition and difference of 2 complex numbers
Input: complex_tag c1, complex_tag c2, complex_tag **sum, & complex_tag **diff
Output: -1 (if error) or 0 | calculated values is returned through pointers
*/
int add_and_sub(struct complex_tag c1, struct complex_tag c2, struct complex_tag **sum, struct complex_tag **diff)
{
	//Set *sum and *diff equalled to (typecast) allocation of memory size of complex_tag
	*sum = (struct complex_tag *)malloc(sizeof(struct complex_tag));
	*diff = (struct complex_tag *)malloc(sizeof(struct complex_tag));

	//If memory cannot be allocated, print error and return -1
	if (sum == 0 || diff == 0)
	{
		printf("Error memory allocation error");
		return -1;
	}

	//Sum and difference calculation
	(*sum)->real = c1.real + c2.real;
	(*sum)->imaginary = c1.imaginary + c2.imaginary;
	(*diff)->real = c1.real - c2.real;
	(*diff)->imaginary = c1.imaginary - c2.imaginary;
	return 0;
}
