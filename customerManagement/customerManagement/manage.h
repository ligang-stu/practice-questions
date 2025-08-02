#pragma once
#include <stdio.h>

typedef struct Customer {
	int id;
	char name[20];
	char gender[2];
	int age;
	char tel[12];
	char email[50];

}p;

p custmoer[50];
extern int number;
void add();
void list();
void del();
void modify();