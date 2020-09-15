/**
Contains the implementations of stack functions: push(), pop(), size(). Assume inputs are doubles
*/

#include "stack.h"

/**
Function to initialize a new stack so size=0 and head=NULL
@param Stack a stack to initialize
**/
void initStack(struct Stack stack)
{
	struct Stack newStack;
  newStack.head = NULL;
  newStack.size = 0;
  stack = newStack;

}
/**
inputs a double, allocates a new stack element, and pushes it onto the top of the stack.
@param double data to be stored in stack
@param Stack stack that is being pushed to
*/
void push(double data, struct Stack *stack)
{

	top = (struct Node*)malloc(sizeof(struct Node));

	//initialize tops data to data inputted
	top->data = data;

	// set the link of the current head of stack
	top->link = stack->head;

	//new node should be head of stack
	stack->head = top;

	//increment stack size
	stack->size++;

}	

/**
pops off the top element from the stack, returns the stored double value, and deallocates it from the heap.
@param Stack stack pointer to stack struct
@return data of top node
*/
double pop(struct Stack *stack)
{
	if(stack->head == NULL){
		//stack is empty or null stack head
		return -1;
	}
	double returnData = stack->head->data;

	//deallocate old stack head
	free(stack->head);

	//replace old stack head with the next one
	stack->head = stack->head->link;

	//decrement size of stack
	stack->size--;

	return returnData;
}

/**
returns the number of elements currently on the stack.
@return int size of stack
*/
int size(struct Stack *stack)
{
	return stack->size;
}
