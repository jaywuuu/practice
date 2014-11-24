#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct tagQueueNode {
	int value;
	tagQueueNode *next;
} QueueNode;

typedef struct tagQueue {
	int size;
	QueueNode *front;
	QueueNode *last;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void free_queue(Queue *q);

#endif