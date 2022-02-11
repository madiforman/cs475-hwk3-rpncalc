/*
 ============================================================================
 Name        : Reverse Polish Notation Calculator
 Author      : Madison Sanchez-Forman
 Version     : 2.11.22
 Description : Evaluates input RPN expressions using stack based structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 							/* maximum RPN expression input length */

/**
 * @brief prompt user if they would like to continue evaluating expressions
 * 
 * @return char - first index of users response
 */
char get_menu_option(){
	char resp[MAX_EQ_LEN];
	printf("Evaluate another? (y/n): ");
	fgets(resp, sizeof(resp),stdin);
	return resp[0]; 							/*since only valid responses are 'y'/'n', we only ever care about the first index */
}
int main()
{ 
  char eqn[MAX_EQ_LEN];
  char c;										/*user response*/
  int flag = 0;
  do{
	  if(flag==1){
		  c = get_menu_option();
		  flag = 0;
	  }
	printf("Evaluate an equation (in RPN): \n");
	fgets(eqn, sizeof(eqn), stdin);			
	rpn_calculator(eqn);
	printf("\n");				
	c = get_menu_option();
	switch(c){
		case 'y':
		break;
		case 'n':
		printf("Exiting...\n");
		break;
		default: 
		printf("Uknown option %c. Try again. \n", c);
		flag = 1;
		break;
	}
  }while(c!='n');
  return 0;

  }
