#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

int contents[100];
int *left = contents;
int *right = contents;
int is_full = 0;
int is_empty = 1;

static void *circinc(int **p);
static void check_if_full();
static void check_if_empty();
static void queue_empty();
static void queue_full();

void enqueue(int n){
	*right = n;
	if (is_full)
		queue_full();
	else
		circinc(&right);
	check_if_full();
	is_empty = 0; //obviously it can't be empty if we just added something
}

int dequeue(){
	int n = *left;
	if (is_empty)
		queue_empty();
	else
		circinc(&left);
	check_if_empty();
	is_full = 0; //obviously it can't be full if we just removed something
	return n;
}

//increment in a circular fashion
static void *circinc(int **p){
	if(*p + 1 == contents + QUEUE_SIZE){
		*p = contents;
	}else{
		(*p)++;
	}
}

//check if it's full when enqueuing
static void check_if_full(){
	if (left == right)
		is_full = 1;
	else
		is_full = 0;
}

//check if it's empty when dequeuing
static void check_if_empty(){
	if (left == right)
		is_empty = 1;
	else
		is_empty = 0;
}

//print errors
static void queue_empty(){
	fprintf(stderr, "Error: Cannot dequeue from empty queue.\n");
	exit(EXIT_FAILURE);
}

static void queue_full(){
	fprintf(stderr, "Error: Cannot enqueue full queue.\n");
	exit(EXIT_FAILURE);
}