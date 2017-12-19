#include <stdio.h>
#include "stack.h"

#define N 100


int main(){
	for (int i = 0; i < N; i++)
		push(i);

	for(int i = 0; i < N; i++)
		printf("%d\n", pop());
}