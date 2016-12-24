//Author: Frank Dong
//Purpose: To create a program which will calculate the multiplication, division, addition and difference
//		   of a 2 complex numbers.
//Date: Nov 30, 2016

#ifndef OPERATION_FUNCTION
#define OPERATION_FUNCTION

//Declare complex_tag structure
struct complex_tag
{
	double real;
	double imaginary;
};

//Delcare Complex_type type
typedef struct
{
	double real;
	double imaginary;
} Complex_type;

//Functions
Complex_type multiply(struct complex_tag c1, struct complex_tag c2);
int divide(struct complex_tag *c1, struct complex_tag *c2, struct complex_tag *result);
int add_and_sub(struct complex_tag c1, struct complex_tag c2, struct complex_tag **sum, struct complex_tag **diff);

#endif
