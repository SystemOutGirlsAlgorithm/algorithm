#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 500001

typedef struct queue {
	int data[SIZE];
	int front_, rear;
}queue;

void init(queue* q) {
	q->rear = -1;
	q->front_ = -1;
}

void push(queue* q, int num) {
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = num;
}

int pop(queue* q) {
	if (empty(q))
		return -1;
	else
		q->front_ = (q->front_ + 1) % SIZE;
	    return q->data[q->front_];
}

int size(queue* q) {
	if (empty(q))
		return 0;
	else
		return q->rear - q->front_;
}

int empty(queue* q) {
	return (q->front_ == q->rear);
}

int front(queue* q) {
	if (empty(q))
		return -1;
	else
		return q->data[q->front_ + 1%SIZE];
}

int main() {

	int n ;
	int z = 0;
	queue q ;

	scanf("%d", &n);

	init(&q);

	for (int i = 1; i <= n; i++) {
		push(&q, i); 
	}

	while (!empty(&q)) {
		z= pop(&q);
		if (empty(&q)) {
			break;
		}
		z = pop(&q);
		push(&q, z);
	}

	printf("%d\n", z);
	
	return 0;
}

