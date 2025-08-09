#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int type;

typedef struct {

	type* data;
	size_t capacity;
	size_t size;
	size_t front;
	size_t rear;
}Queue;

//初始化队列
void initQueue(Queue* queue,size_t capacity) 
{
	queue->data = (type*)malloc(sizeof(type) * capacity);
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
}

//入队
void enQueue(Queue* queue,type element)
{
	if (queue->size == queue->capacity)
	{
		printf("队内元素已满，%d无法入队\n",element);
		return 1;
	}
	printf("元素 %d 入队\n", element);
	queue->data[queue->rear] = element;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->size++;
}

//出队
void exitQueue(Queue* queue,type* num)
{
	if (queue->size == 0) {
		return 1;
	}
	*num = queue->data[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;

	printf("元素 %d 出队\n", *num);
}

//显示队列
void PrintQueue(Queue* queue) {
	int i = 0;
	printf("队元素个数为：%zu\n",queue->size);
	if(queue->size !=0 )
		printf("队元素为：");
	size_t tmp = queue->front;
	for (i = 0; i < queue->size; i++) {
		printf("%d ",queue->data[tmp]);
		tmp = (tmp + 1) % queue->capacity;
	}
	printf("\n \n");
		
}

//销毁队列
void destoryQueue(Queue* queue)
{
	free(queue->data);
	queue->data = NULL;
	queue->size = 0;
	queue->capacity = 0;
}
int main() {
	Queue queue;
	
	type num = 0;
	initQueue(&queue, 4);
	enQueue(&queue, 100);
	enQueue(&queue, 200);
	enQueue(&queue, 300);
	enQueue(&queue, 400);
	enQueue(&queue, 500);

	PrintQueue(&queue);

	exitQueue(&queue,&num);
	exitQueue(&queue, &num);

	PrintQueue(&queue);

	enQueue(&queue, 1);
	enQueue(&queue, 2);

	PrintQueue(&queue);

	destoryQueue(&queue);


	return 0;
}