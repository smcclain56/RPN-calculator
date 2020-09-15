#This is the Makefile for the program

all : main.c stack.o rpn.o
	gcc -Wall main.c stack.o rpn.o

stack.o : stack.h stack.c
	gcc -Wall -c stack.c 

rpn.o : rpn.h rpn.c
	gcc -Wall -c rpn.c 

clean: 
	rm -f a.out *.o 