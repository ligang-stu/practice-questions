#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int type;

typedef struct {
    type* data; //指向数组的那块区域
    int size;  //数组当前的长度
    int capacity; //数组最大容量
}Dynatic_array;

//初始化数组
void initarray(Dynatic_array* p, size_t n) {
    p->capacity = n;
    p->size = 0;
    p->data = (type*)malloc(p->capacity * sizeof(type));
}

//添加数组元素
void add_element(Dynatic_array* p, type element) {
    if (p->size < p->capacity) {
        p->data[p->size] = element;
        p->size++;
    }
    else
    {
        printf("数组容量不够，请扩充数组后添加\n");
    }
}

//在指定位置插入元素
void insert_element(Dynatic_array* p, int index, type element) {
    if (index > p->size) {
        printf("数组的长度位%d，请选择合理的范围插入\n", p->size);
        return 1;
    }
    for (int i = p->size - 1; i >= index; i--)
    {
        p->data[i + 1] = p->data[i];
    }
    p->data[index] = element;
    p->size++;
}

//在数组末尾插入元素
void end_insert_element(Dynatic_array* p, type element) {
    p->data[p->size] = element;
    p->size++;
}

//删除指定位置的数组元素
void delete_element(Dynatic_array* p, int index) {
    for (int i = index; i < p->size - 1; i++) {
        p->data[i] = p->data[i + 1];
    }
    p->size--;
}

//删除末尾的数组元素
void end_delete_element(Dynatic_array* p) {
    p->size--;
}

//扩充数组
void expandarray(Dynatic_array* p, size_t capacity) {
    type* tmp = NULL;
    tmp = (type*)realloc(p->data, (capacity + p->capacity) * sizeof(type));
    if (tmp == NULL) {
        printf("扩充的内存太大了，内存不足，无法扩充！");
        return 1;
    }
    p->data = tmp;
    p->capacity = capacity + p->capacity;
}

//销毁数组
void destoryarray(Dynatic_array* p) {
    p->capacity = 0;
    p->size = 0;
    free(p->data);
    p->data = NULL;
}

//打印数组内容
void Printf(Dynatic_array* p) {
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->data[i]);
    }
}


int main() {
    Dynatic_array da;

    //初始化数组
    initarray(&da, 5);

    //添加数组元素
    add_element(&da, 0);
    add_element(&da, 2);
    add_element(&da, 4);

    //在指定位置插入元素
    insert_element(&da, 1, 1);


    //扩充数组
    expandarray(&da, 5);

    //扩充后添加数组元素
    add_element(&da, 5);
    add_element(&da, 6);

    //在数组末尾插入元素
    end_insert_element(&da, 7);



    //删除指定位置的数组元素
    delete_element(&da, 0);

    //删除末尾的数组元素
    end_delete_element(&da);

    insert_element(&da, 11, 3);

    //打印数组内容
    Printf(&da);

    //销毁数组
    destoryarray(&da);

    return 0;
}