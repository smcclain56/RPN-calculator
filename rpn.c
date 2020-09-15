/**
Implemenations of RPM algorithm 
*/

#include "rpn.h"
#include "stack.h"
#include <ctype.h>
#include <string.h>

/**
This method tokenizes the string into its components and pushes the digits onto the stack.
Then preforms the specified operands on the poped digits and pushes the answer back
onto the stack. 
@param char[] str the string you want to tokenize
*/
double RPN(char str[])
{
	struct Stack stack;
	initStack(stack);
	double result = -1;
	//we want our possible delimiters to be a space, tab or newline
 	char delim[] = " \n\t";
  
    // Returns first token 
    char *token = strtok(str, delim); 

    // Keep making tokens while one of the delimiters present in str[]. 
    while (token != NULL) { 
    	//check if token is digit or operand
    	if(isdigit(token[0])){
    		//if its a digit push it on the stack
    		push(atof(&token[0]), &stack);
    	}
    	else if(ispunct(token[0])){
    		//if its an operand check is stack is large enough to pop 2 elements
    		if(stack.size<2){
    			printf("Error: not enough operands\n\n");
    			return -1;
    		}
    		else{
    			//pop two operands off the stack
    			double num1, num2;
    			num1 = pop(&stack);
    			num2 = pop(&stack);

    			if(token[0] == '+'){
    				result = addition(num1,num2);
    			} else if(token[0] == '-'){
    				result = subtraction(num1,num2);
    			} else if(token[0] == '*'){
    				result = multiplication(num1,num2);
    			} else if(token[0] == '/'){
    				result = division(num1,num2);
    			} else{
    				printf("Error: invalid operator entered.\n\n");
    				return -1;
    			}
    		push(result, &stack);
    		}
    	}
        token = strtok(NULL, delim);
    } 

    //if stack size is still greater than 1: generator error
    if(stack.size > 1){
    	//count number of operators or operands
    	int i = 0, numOperators = 0, numOperands =0;
    	//pop off remaining frames and increment our counters
    	while(i<stack.size){
    		if(isdigit(pop(&stack))){
    			numOperands++;
    		}else if(ispunct(pop(&stack))){
    			numOperators++;
    		}
    	}

    	//determine if too many operators or operands
    	if(numOperands >= numOperators){
    		printf("Error: too many operands entered.\n\n");
    		return -1;
    	} else if(numOperands<numOperators){
    		printf("Error: insufficient operands\n\n");
    		return -1;
    	} else{
    		return -1;
    	}

    }else{
    	//otherwise pop the last frame from stack and thats the result
    	return(pop(&stack));
    }
    return -1;
}

double addition(double num1, double num2){
	return num1+num2;
}

double subtraction(double num1, double num2){
	return num2-num1;
}

double multiplication(double num1, double num2){
	return num1*num2;
}

double division(double num1, double num2){
	if(num1 == 0){
		printf("Error: Divide-by-zero\n\n");
		return -1;
	}else{
		return num2/num1;
	}
}