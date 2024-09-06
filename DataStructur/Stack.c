#include "stdio.h"

typedef struct Stack {
	int top;
	int capacity;
	int* array;
} Stack;

Stack* createStack(int capacity) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
	return stack->top == -1;
}

void push(Stack* stack, int item) {
	if (isFull(stack)) {
		return;
	}
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	return stack->array[stack->top--];
}

int peek(Stack* stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	return stack->array[stack->top];
}

int main() {
	Stack* stack = createStack(100);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d popped from stack\n", pop(stack));
	printf("Top item is %d\n", peek(stack));
	return 0;
}