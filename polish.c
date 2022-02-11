/*
 ===================================================================================
 Name        : Polish.c
 Author      : Madison Sanchez-Forman
 Version     : 2.11.22
 Description : Algorithm for parsing an RPN expression. Uses evaluate() from
 stack.c to perform arithmetic. In main user entry will be passed to rpn_calculator()
 ====================================================================================
 */
#include "stack.h"
#include "polish.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * @brief Returns 1/0 if input char is a valid operator [+,-,*,/]
 * 
 * @param c possible operator
 * @return int - returns 1 if operator found 0 if not
 */
int is_operator(char c)
{
	if(c=='+' ||c=='-'||c=='/'||c=='*')
    {  return 1; } 
    else {  return 0;  }
}
/**
 * @brief parse and evaluate does the bulk of stack manipulation and expression evaluation
 * 
 */
void rpn_calculator(char eqn[]){
  char *token;
  int flag = 0; 				                /*used for error handling*/
  stack *head = NULL;

  token = strtok(eqn, " \t");  	                /*break expression up by whitespace and tabs*/
  while(token!=NULL){
	if(isalnum(*token)){                        /*if is alphanumeric(so it doesnt crash if user accidentally enters a letter instead of num)*/
		double num = atof(token);
		push(&head, num);				        /*convert to double and push on stack*/
	}else if(is_operator(*token)){
		if(size(head)<2){			
			printf("Error: insufficient operands. \n");
			flag = 1;
		} else {
			evaluate(&head,*token); 	        /*evaluate will solve top two items on stack*/
			}
	} else if(!is_operator(*token)){ 	        /*if is operator didnt return true, then its not a valid operator*/
		printf("Error: operator %c unrecognized. \n", *token);
        pop(&head);                             /*clear stack*/
        pop(&head);
		flag = 1;
	} 
	token = strtok(NULL, " ");
  } 
  if(size(head)>1 && flag!=1){                  /*if theres more than one answer on the stack, and another flag HAS NOT gone off*/
	printf("Error: too many operands entered.\n");
	flag = 1; 
  }
  if(flag==1){ 							        /*if another error previously went off*/
  flag = 0;                                     /*reset flag and end*/
  } else {                                      /*else pop final result*/
	double result = pop(&head);		            /*if something went wrong in evaluate (i.e. div by 0) result will be NAN*/
    if(!isnan(result)){                         /*if its not, print result and terminate*/
	printf("%lf\n", result);
	} 
  }
}
