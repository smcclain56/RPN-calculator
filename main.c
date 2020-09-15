/**
Prompt the user for an RPN expression, evaluate the expression and print the result. You may assume that an expression can be no longer than 
100 characters long. Operators and operands may be separated by a space, a tab or a newline.
@author Sarah McClain
@date 2/12/19
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "rpn.h"

int main(void){
	char str[MAX_INPUT_LEN];
 	char boolean = 'y';
 	char readline[26];
 	double result;

 	while(boolean == 'y'){
 		printf("Enter an equation (in RPN)\n");

 		fgets(str, MAX_INPUT_LEN, stdin);

 		int ln = strlen(str)-1;
		if(str[ln] == '\n')
			str[ln] = '\0';

 		//HOW TO GET RID OF TRAILING NEWLINE CHARACTER????

 		//call rpn calculator on string
 		result = RPN(str);

 		if(result != -1){
 			printf("%0.3f\n\n", result);
 		}

 		printf("Evaluate another expression? (y/n): ");
 		if(fgets(readline, sizeof(readline), stdin) == NULL){
 			printf("Something went wrong with input. \n");
 			return 0;
 		}
 		boolean = readline[0];
 		//set boolean to userInputted value
 		if(boolean == 'n'){
 			printf("Exiting...\n");
 			return 0;
 		}
 	}
 	//printf("Exiting...\n");
 	return 0;

 }



