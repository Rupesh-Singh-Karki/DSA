// C program to illustrate macros
#include <stdio.h>

// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))  //condition ? expression_if_true : expression_if_false;
//? ternary conditional operator

// Driver Code
int main()
{

	// Given two number a and b
	int a = 18;
	int b = 76;

	printf("Minimum value between"
		" %d and %d is %d\n",
		a, b, min(a, b));

	return 0;
}
