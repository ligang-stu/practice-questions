#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int type;

typedef struct {
	type* data;
	size_t capacity;
	size_t size;
}Stack;

void initStack(Stack* stack, size_t capacity)
{
	stack->data = (type*)malloc(sizeof(type));
	stack->capacity = 1;
	stack->size = 0;
}

void pushStack(Stack* stack, type element)
{
	if (stack->capacity == stack->size)
	{
		stack->capacity *= 2;
		type* tmp = (type*)realloc(stack->data, sizeof(type) * stack->capacity);
		if (tmp == NULL)
		{
			perror("ѹջʧ��");
			return 1;
		}
		stack->data = tmp;
	}
	stack->data[stack->size] = element;
	stack->size++;
}

void popStack(Stack* stack)
{
	if (stack->size == 0)
	{
		return 1;
	}
	stack->size--;
}

void destoryStack(Stack* stack) {
	free(stack->data);
	stack->size = 0;
	stack->capacity = 0;
}

void PrintStack(Stack* stack) {
	printf("\nջ�ĳ���Ϊ��%zd", stack->size);
	printf("\nջ��Ԫ��Ϊ��");
	for (size_t i = 0; i < stack->size; i++) {
		printf("%d ", stack->data[i]);
	}
}
int main() {
	Stack stack;
	initStack(&stack, 3);
	pushStack(&stack, 100);
	pushStack(&stack, 200);
	pushStack(&stack, 300);
	pushStack(&stack, 400);

	PrintStack(&stack);

	popStack(&stack);
	PrintStack(&stack);

	destoryStack(&stack);
	return 0;
}