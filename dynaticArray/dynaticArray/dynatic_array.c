#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int type;

typedef struct {
    type* data; //ָ��������ǿ�����
    int size;  //���鵱ǰ�ĳ���
    int capacity; //�����������
}Dynatic_array;

//��ʼ������
void initarray(Dynatic_array* p, size_t n) {
    p->capacity = n;
    p->size = 0;
    p->data = (type*)malloc(p->capacity * sizeof(type));
}

//�������Ԫ��
void add_element(Dynatic_array* p, type element) {
    if (p->size < p->capacity) {
        p->data[p->size] = element;
        p->size++;
    }
    else
    {
        printf("����������������������������\n");
    }
}

//��ָ��λ�ò���Ԫ��
void insert_element(Dynatic_array* p, int index, type element) {
    if (index > p->size) {
        printf("����ĳ���λ%d����ѡ�����ķ�Χ����\n", p->size);
        return 1;
    }
    for (int i = p->size - 1; i >= index; i--)
    {
        p->data[i + 1] = p->data[i];
    }
    p->data[index] = element;
    p->size++;
}

//������ĩβ����Ԫ��
void end_insert_element(Dynatic_array* p, type element) {
    p->data[p->size] = element;
    p->size++;
}

//ɾ��ָ��λ�õ�����Ԫ��
void delete_element(Dynatic_array* p, int index) {
    for (int i = index; i < p->size - 1; i++) {
        p->data[i] = p->data[i + 1];
    }
    p->size--;
}

//ɾ��ĩβ������Ԫ��
void end_delete_element(Dynatic_array* p) {
    p->size--;
}

//��������
void expandarray(Dynatic_array* p, size_t capacity) {
    type* tmp = NULL;
    tmp = (type*)realloc(p->data, (capacity + p->capacity) * sizeof(type));
    if (tmp == NULL) {
        printf("������ڴ�̫���ˣ��ڴ治�㣬�޷����䣡");
        return 1;
    }
    p->data = tmp;
    p->capacity = capacity + p->capacity;
}

//��������
void destoryarray(Dynatic_array* p) {
    p->capacity = 0;
    p->size = 0;
    free(p->data);
    p->data = NULL;
}

//��ӡ��������
void Printf(Dynatic_array* p) {
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->data[i]);
    }
}


int main() {
    Dynatic_array da;

    //��ʼ������
    initarray(&da, 5);

    //�������Ԫ��
    add_element(&da, 0);
    add_element(&da, 2);
    add_element(&da, 4);

    //��ָ��λ�ò���Ԫ��
    insert_element(&da, 1, 1);


    //��������
    expandarray(&da, 5);

    //������������Ԫ��
    add_element(&da, 5);
    add_element(&da, 6);

    //������ĩβ����Ԫ��
    end_insert_element(&da, 7);



    //ɾ��ָ��λ�õ�����Ԫ��
    delete_element(&da, 0);

    //ɾ��ĩβ������Ԫ��
    end_delete_element(&da);

    insert_element(&da, 11, 3);

    //��ӡ��������
    Printf(&da);

    //��������
    destoryarray(&da);

    return 0;
}