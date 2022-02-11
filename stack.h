
#ifndef STACK_H_
#define STACK_H_

struct stack
{   
    double data; 
    struct stack *next;
};
typedef struct stack stack;                 /*typedef to make referencing simple*/
void push(stack **head, double val);
double pop(stack **head);
int size(stack *head);
void evaluate(stack **head, char c);


#endif /* STACK_H_ */
