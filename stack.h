/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */
#include <stdlib.h>
#ifndef STACK_H_
#define STACK_H_

// TODO: declaration of stack struct and its functions go here
struct node{
    double data;
    struct node *next;
};
typedef struct node node;
node *top;
int node_count;

void initalize(){
top = NULL;
}

void push(double val){
    node *temp;
    temp = malloc(sizeof(node));
    temp->data = val;
    temp->next = top;
    top = temp;
    node_count++;
}
double pop(){
node *temp;
double val;
temp = top;
val = temp -> data;
top = top->next;
free(temp);
node_count--;
return val;
}
int size(){
return node_count;
} 
double get_top(){
    return top->data;
}

#endif /* STACK_H_ */
