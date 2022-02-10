/*
 ============================================================================
 Name        : Reverse Polish Notation Calculator
 Author      : Madison Sanchez-Forman
 Version     : 2.9.22
 Description : Evaluates input RPN expressions using stack based structure
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */
/**
 * @brief Returns 1/0 if input char is a valid operator [+,-,*,/]
 * 
 * @param c possible operator
 * @return int - returns 1 if operator found 0 if not
 */
int is_operator(char c){
	if(c=='+' ||c=='-'||c=='/'||c=='*')
	{ return 1; } 
	else { return 0;}
}

/**
 * @brief prompt user if they would like to continue evaluating expressions
 * 
 * @return char - first index of users response
 */
char get_menu_option(){
	char resp[MAX_EQ_LEN];
	printf("Evaluate another? (y/n): ");
	fgets(resp, sizeof(resp),stdin);
	return resp[0]; 			/*since only valid responses are 'y'/'n', we only ever care about the first index */
}

/**
 * @brief parse and evaluate does the bulk of stack manipulation and expression evaluation
 * 
 */
void parse_and_evaluate(){
  char eqn[MAX_EQ_LEN];
  char *token;
  int flag = 0; 				/*used for error handling*/
  stack *head = NULL;
  printf("Evaluate an equation (in RPN): \n");
  fgets(eqn, sizeof(eqn), stdin);

  token = strtok(eqn, " \t");  	/*break expression up by whitespace*/
  while(token!=NULL){
	if(isalnum(*token)){        /*if is alphanumeric*/
		double num = atof(token);
		push(&head, num);				/*convert and push on stack*/
	}else if(is_operator(*token)){
		if(size()<2){			
			printf("Error: insufficient operands. \n");
			flag = 1;
		} else {
			 evaluate(*token, &head); 			/*evaluate will solve whatevers on the stack if size is less than two*/
			}
	} else if(!is_operator(*token)){ 	/*if is operator didnt return true, then its not a valid operator*/
		printf("Error: operator %c unrecognized. \n", *token);
		flag = 1;
		break;
	} 
	token = strtok(NULL, " ");
  } 

  if(flag==1){ /*if another error previously went off*/
  flag = 0; 
  }else {
	double result = pop(&head); /*result will be NaN if something went wrong in evaluate*/
    if(size()>1 && !isnan(result)){
	printf("Error: too many operands entered.\n");
	} else if(!isnan(result)){
	printf("%lf\n", result);	
	} 
  }
  

}
int main()
{ 
  //char eqn[MAX_EQ_LEN];
  char c;
  //double result = 0;
  //int flag = 0;
  do{
	parse_and_evaluate();
	c = get_menu_option();
	switch(c){
		case 'y':
		break;
		case 'n':
		printf("Exiting...\n");
		break;
		default: 
		printf("Uknown option %c. Try again. \n", c);
	}
  }while(c!='n');
  return 0;
  }
