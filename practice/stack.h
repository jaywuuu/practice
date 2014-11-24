#ifndef STACK_H_
#define STACK_H_

typedef struct tagStackNode {
	int value;
	int min;
	tagStackNode *next;
} StackNode;

typedef struct tagStack {
	int size;
	StackNode *top;
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void free_stack(Stack *stack);
int stack_min(Stack *);

#endif
