#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int type;
typedef struct Node {
	type data;
	struct Node* next;

}Node;
typedef struct {
	Node* head;
	size_t size;
}Linklist;

//
void initLinklist(Linklist*list) {
	list->head = NULL;
	list->size = 0;
}
/**
* @brief 获取指定位置的上一个节点
* @param	Linklist*list	操作的链表
* @param	size_t index	指定的位置
* @return	Node*			返回上一个节点
*/


Node* get_pre_node(Linklist*list,size_t index) 
{
	Node* pre_node = list->head;
	for (size_t i = 1; i < index;i++) {
		pre_node = pre_node->next;
	}
	return pre_node;
}

/**
* @brief	在链表指定位置插入元素
* @param	Linklist* list	链表
* @param	size_t index	指定的位置
* @param	ype element		需要插入的元素
*/
void insertAt(Linklist* list, size_t index, type element)
{

	if (index > list->size)
		return 1;

	
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = element;
	if (index == 0)
	{
		new_node->next = list->head;
		list->head = new_node;
	}
	else
	{	
		Node* pre_node = get_pre_node(list,index);
		new_node->next = pre_node->next;
		pre_node->next = new_node;
	}
	list->size++;
}

//在末尾插入元素
void insertEnd(Linklist* list, type element)
{
	insertAt(list, list->size, element);
}

/**
* @brief	在链表指定位置删除节点
* @param	Linklist* list	链表
* @param	size_t index	指定的位置
*/
void deleteAt(Linklist* list, size_t index)
{	
	if (index >= list->size)
		return 1;
		
	Node* delete_node;
	if (index == 0)
	{
		delete_node= list->head;
		list->head = delete_node->next;
	}
	else
	{
		Node* pre_node = get_pre_node(list,index);
		delete_node = pre_node->next;
		pre_node->next = delete_node->next;
	}

	free(delete_node);
	list->size--;			
}

//删除末尾节点
void deleteEnd(Linklist* list)
{
	deleteAt(list,list->size-1);
}

/**
* @brief	在链表指定位置修改节点元素
* @param	Linklist* list		链表
* @param	size_t index		指定的位置
* @param	type new_element	修改为的元素
*/
void modifyAt(Linklist* list, size_t index, type new_element)
{
	if (index >= list->size)
		return 1;
	Node* modify_node;
	if (index == 0) 
	{
		modify_node = list->head;
		modify_node->data = new_element;
	}
	else
	{
		Node* pre_node = get_pre_node(list, index);
		modify_node = pre_node->next;
		modify_node->data = new_element;
	}

}
//显示链表信息
void showLinklist(Linklist* list) {
	printf("\n链表的长度是 %zd \n",list->size);
	Node* current = list->head;
	printf("每个节点值依次是：");
	while (current != NULL)
	{
		printf(" %d", current->data);
		current = current->next;
	}
	printf("\n");
}
void modifyEnd(Linklist*list,type new_element) {
	modifyAt(list, list->size - 1, new_element);
}


//释放链表
void destoryLinklist(Linklist* list) {
	Node* current_node = list->head;
	Node* destoty_node = NULL;
	while (current_node != NULL)
	{
		destoty_node = current_node;
		current_node = current_node->next;
		free(destoty_node);
	}
}


int main() {
	Linklist list;
	initLinklist(&list);

	printf("添加三个元素");
	insertEnd(&list, 100);
	insertEnd(&list, 200);
	insertEnd(&list, 300);
	showLinklist(&list);

	printf("\n在头结点处添加一个0");
	insertAt(&list,0,0);
	showLinklist(&list);
	
	printf("\n在第二个节点后插入150，并在末尾处插入400");
	insertAt(&list, 2,150 );
	insertEnd(&list, 400);
	showLinklist(&list);

	printf("\n删除末尾节点");
	deleteEnd(&list);
	showLinklist(&list);
	
	printf("\n把头节点的值修改为50，并把末尾节点的值修改为250");
	modifyAt(&list, 0, 50);
	modifyEnd(&list, 250);
	showLinklist(&list);

	printf("\n把第2个节点的值修改为120，并把第三个节点的值修改为170");
	modifyAt(&list, 1, 120);
	modifyAt(&list, 2, 170);
	showLinklist(&list);
	

	destoryLinklist(&list);

	return 0;
}