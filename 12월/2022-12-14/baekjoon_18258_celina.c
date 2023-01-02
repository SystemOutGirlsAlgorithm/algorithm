#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 2000001

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

int back(queue* q) {
	if (empty(q))
		return -1;
	else
		return q->data[q->rear];
}



int main() {

	char com[6];
	int n, z;
	queue q ;

	scanf("%d", &n); //명령의 수 

	init(&q);

	for (int i = 0; i < n; i++) {
		scanf("%s", com); //명령어 입력 받음 ~

		if (strcmp(com, "push") == 0) {
			scanf("%d", &z);  //큐에 넣을 숫자 입력 받음 
			push(&q, z);
		}

		else if (strcmp(com, "pop") == 0) {
			printf("%d\n", pop(&q));
		}

		else if (strcmp(com, "size") == 0) {
			printf("%d\n", size(&q));
		}

		else if (strcmp(com, "empty") == 0) {
			printf("%d\n", empty(&q));
		}

		else if (strcmp(com, "front") == 0) {
			printf("%d\n", front(&q));
		}

		else if (strcmp(com, "back") == 0) {
			printf("%d\n", back(&q));
		}
	}
}

