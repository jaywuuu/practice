/* simple queue */

#include <iostream>
#include "queue.h"

void init_queue(Queue *q) {
	q->front = NULL;
	q->last = NULL;
	q->size = 0;
}

void enqueue(Queue *q, int value) {
	QueueNode *qnode = (QueueNode*)malloc(sizeof(QueueNode));
	qnode->value = value;
	qnode->next = NULL;
	if (q->size == 0) {
		q->front = qnode;
	}
	else {
		q->last->next = qnode;
	}
	q->last = qnode;
	q->size++;
}

int dequeue(Queue *q) {
	int retval = q->front->value;
	QueueNode *front = q->front;
	q->front = q->front->next;

	free(front);
	q->size--;

	return retval;
}

void free_queue(Queue *q) {
	for (int i = 0; i < q->size; i++) {
		dequeue(q);
	}
}