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
* @brief ��ȡָ��λ�õ���һ���ڵ�
* @param	Linklist*list	����������
* @param	size_t index	ָ����λ��
* @return	Node*			������һ���ڵ�
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
* @brief	������ָ��λ�ò���Ԫ��
* @param	Linklist* list	����
* @param	size_t index	ָ����λ��
* @param	ype element		��Ҫ�����Ԫ��
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

//��ĩβ����Ԫ��
void insertEnd(Linklist* list, type element)
{
	insertAt(list, list->size, element);
}

/**
* @brief	������ָ��λ��ɾ���ڵ�
* @param	Linklist* list	����
* @param	size_t index	ָ����λ��
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

//ɾ��ĩβ�ڵ�
void deleteEnd(Linklist* list)
{
	deleteAt(list,list->size-1);
}

/**
* @brief	������ָ��λ���޸Ľڵ�Ԫ��
* @param	Linklist* list		����
* @param	size_t index		ָ����λ��
* @param	type new_element	�޸�Ϊ��Ԫ��
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
//��ʾ������Ϣ
void showLinklist(Linklist* list) {
	printf("\n����ĳ����� %zd \n",list->size);
	Node* current = list->head;
	printf("ÿ���ڵ�ֵ�����ǣ�");
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


//�ͷ�����
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

	printf("�������Ԫ��");
	insertEnd(&list, 100);
	insertEnd(&list, 200);
	insertEnd(&list, 300);
	showLinklist(&list);

	printf("\n��ͷ��㴦���һ��0");
	insertAt(&list,0,0);
	showLinklist(&list);
	
	printf("\n�ڵڶ����ڵ�����150������ĩβ������400");
	insertAt(&list, 2,150 );
	insertEnd(&list, 400);
	showLinklist(&list);

	printf("\nɾ��ĩβ�ڵ�");
	deleteEnd(&list);
	showLinklist(&list);
	
	printf("\n��ͷ�ڵ��ֵ�޸�Ϊ50������ĩβ�ڵ��ֵ�޸�Ϊ250");
	modifyAt(&list, 0, 50);
	modifyEnd(&list, 250);
	showLinklist(&list);

	printf("\n�ѵ�2���ڵ��ֵ�޸�Ϊ120�����ѵ������ڵ��ֵ�޸�Ϊ170");
	modifyAt(&list, 1, 120);
	modifyAt(&list, 2, 170);
	showLinklist(&list);
	

	destoryLinklist(&list);

	return 0;
}