/*
 ============================================================================
 Name        : PolishSol.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	// char eqn[MAX_EQ_LEN];	 // string to store the input RPN expression
	// char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"

	// /* TODO */

	// printf("Exiting...\n");
	// return 0;
	initalize();
	push(11.0);
	push(40);
	printf("The top is: %lf \n", get_top());
	return 0;
}
