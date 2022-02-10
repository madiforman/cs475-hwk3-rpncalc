/*
 ============================================================================
 Name        : Stack.h - Linked List based stack structure
 Author      : Madison Sanchez-Forman
 Version     : 2.9.22
 Description : uses a stack of doubles to build and evaluate RPN expressions
 ============================================================================
 */
#include <stdlib.h>
#ifndef STACK_H_
#define STACK_H_

int node_count;                     /*increments/decrements with push and pop*/
typedef struct stack stack;
/*typedef to make referencing simpler in the rest of code*/

struct stack
{
    double data; 
    struct stack *next;
};



void push(stack **head, double val)
{
stack *node = malloc(sizeof(stack));
node->data=val;
node->next=*head;
*head=node;
node_count++;
}

double pop(stack **head)
{
    stack *temp=*head;
    double val=temp->data;
    *head=temp->next;
    free(temp);
    node_count--;
    return val;
}

int size(){
return node_count;
} 
void evaluate(char c, stack **head){
    double result, op2;
    switch(c){
        case '+':
            result = pop(head) + pop(head);
            break;
        case '*':
            result = pop(head) * pop(head);
            break;
        case '-':
            op2 = pop(head);
            result = (pop(head)-op2);
            break;
        case '/':
            op2 = pop(head);
            if(op2== 0){
                printf("Error: divide-by-zero.\n");
                result = NAN;
                break;
            } else{
                result = pop(head)/op2;
                break;
            }
        default:
        printf("Error: operator %c unrecognized. \n", c);
        result = NAN;
        break;
    }
    push(head, result);
}



#endif /* STACK_H_ */
