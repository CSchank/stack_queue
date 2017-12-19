#include <stdio.h>
#include "queue.h"

#define N 100


int main(){
	for (int i = 0; i < N; i++)
		enqueue(i);

	for(int i = 0; i < N / 2; i++)
		printf("%d\n", dequeue());

	for (int i = 0; i < N/4; i++)
		enqueue(i);

	for(int i = 0; i < 3*N/4; i++)
		printf("%d\n", dequeue());
}