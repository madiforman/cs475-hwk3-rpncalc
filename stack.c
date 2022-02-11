/*
 ============================================================================
 Name        : Stack.c
 Author      : Madison Sanchez-Forman
 Version     : 2.11.22
 Description : Creates dynamic stack for evaulation of expressions
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"

/**
 * @brief Push() pushes a new value from an expression onto the stack
 * 
 * @param head head of the stack
 * @param val  data to be pushed
 */
void push(stack **head, double val){
    stack* node = malloc(sizeof(stack));
    if(node == NULL){
        printf("Error: out of space\n");
    }else {
    node->data = val;
    node->next = *head;
    *head = node;  
    }    
}
/**
 * @brief pop() removes the top element from th stack and returns its data.
 * 
 * @param head head of stack
 * @return double value of node at head
 */
double pop(stack **head){
    if(*head == NULL){
        printf("Error: bottom of stack\n");
        return NAN;
    } else {
        stack* temp = *head;
        double val = temp->data;
        *head = temp->next;
        free(temp);
        return val;
    }

}
/**
 * @brief Size iterates over the stack and returns the number of elements found in the stack
 * 
 * @param head - head of the stack
 * @return int - number of elements found
 */
int size(stack *head){
    stack* current = head;
    int size = 0;
    while(current!=NULL){
        ++size;
        current = current->next;
    }
    return size;
}
/**
 * @brief Evaluate takes the two items at the top of the stack, and simplifies them based on input char (operator)
 * 
 * @param head head of the stack
 * @param c operation to be performed {+,-,*,/}
 */
void evaluate(stack **head, char c)
{
    double result, op2;
    switch (c)
    {
    case '+':
        result = pop(head) + pop(head); /*if + / *, order doesnt matter*/
        break;
    case '*':
        result = pop(head) * pop(head);
        break;
    case '-':
        op2 = pop(head);            /*remove top element first to perserve order of operations*/
        result = (pop(head) - op2);
        break;
    case '/':
        op2 = pop(head);
        if (op2 == 0)
        {
            printf("Error: divide-by-zero.\n");  /*prevent divide by zero error, return Nan as result*/
            printf("\n");
            pop(head);
            result = NAN;
            break;
        }
        else
        {
            result = pop(head) / op2;
            break;
        }
    default:
        printf("Error: operator %c unrecognized. \n", c); /*else its an unrecognized operator, return NAN*/
        result = NAN;
        break;
    }
    push(head, result);
}
