/**
Header file for stack.c
*/
#include "stdio.h"
#include "stdlib.h"

struct Node { 
    double data; 
    struct Node* link; 
} Node; 

struct Stack{
	struct Node *head;
	int size;
} Stack;

struct Node* top; 

void initStack(struct Stack stack);
void push(double data, struct Stack *stack);
double pop(struct Stack *stack);
int size(struct Stack *stack);