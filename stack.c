#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *top = contents;

static int is_full();
static int is_empty();
static void stack_overflow();
static void stack_underflow();

void clear_stack(){
	top = contents;
}

void push(int n){
	if (is_full()){
		stack_overflow();
	}else{
		top++;
		*top = n;
	}
}

int pop(){
	if (is_empty()){
		stack_underflow();
	}else{
		int n = *top;
		top--;
		return n;
	}
}

//check if full or empty
static int is_full(){
	return top == contents + STACK_SIZE;
}

static int is_empty(){
	return top == contents;
}

//print errors
static void stack_overflow(){
	fprintf(stderr, "Error: Stack overflow.\n");
	exit(EXIT_FAILURE);
}

static void stack_underflow(){
	fprintf(stderr, "Error: Stack underflow.\n");
	exit(EXIT_FAILURE);
}