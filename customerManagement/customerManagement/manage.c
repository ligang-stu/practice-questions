#define _CRT_SECURE_NO_WARNINGS
#include "manage.h"

void add()
{
	if (number == 50)
	{
		printf("客户已满，无法添加。");
		return;
	}
	printf("\n--------------添加客户--------------");
	custmoer[number].id = number+1;
	printf("\n姓名：");
	scanf("%s", custmoer[number].name);
	getchar();
	
	printf("\n性别：");
	scanf("%s", custmoer[number].gender);
	getchar();

	printf("\n年龄：");
	scanf("%d", &custmoer[number].age);
	getchar();
	
	printf("\n电话：");
	scanf("%s", custmoer[number].tel);
	getchar();
	
	printf("\n邮箱：");
	scanf("%s", custmoer[number].email);
	getchar();

	number++;
	
	printf("\n--------------添加完成--------------\n");
}

void list() {
	printf("\n--------------客户列表--------------");
	printf("\n编号\t姓名\t性别\t年龄\t电话\t邮箱");
	for (int i = 0; i < number;i++) {
		printf("\n%d\t%s\t%s\t%d\t%s\t%s",custmoer[i].id, custmoer[i].name, custmoer[i].gender, custmoer[i].age, custmoer[i].tel, custmoer[i].email);
	}
	printf("\n");
}

void del() {
	printf("\n--------------删除客户--------------");
	int id;
out:printf("\n请输入要删除客户的id(-1退出):");
	scanf("%d",&id);
	getchar(); // 清除缓存区
	if (id == -1)
	{
		return 0;
	}
	if (id > number || id <= 0)
	{
		printf("编号不存在，请重新输入");
		goto out;
	}
	char ch;
	printf("\n确认是否删除（Y/N）：");
	scanf("%c", &ch);
	getchar(); // 清除缓存区
	if (ch == 'Y' || ch == 'y')
	{
		int index = id - 1;
	
		
		for (int i = index; i < number - 1; i++)
		{
			custmoer[i] = custmoer[i + 1];
			custmoer[i].id--;
		}
		number--;
		printf("\n--------------删除成功--------------\n");
	}
	else
		printf("\n你放弃了删除！\n");
}


void edit(int id)
{
		int index = id -1;
		// 定义字符串存储输入缓冲区
		char input[20];
		// 修改姓名
		printf("\n 姓名(%s):", custmoer[index].name);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input,"%s", custmoer[index].name);
		}
		// 修改性别
		printf("\n 性别(%s):", custmoer[index].gender);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].gender);
		}
		// 修改年龄
		printf("\n 年龄(%d):", custmoer[index].age);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%d", &custmoer[index].age);
		}
		// 修改电话
		printf("\n 电话(%s):", custmoer[index].tel);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].tel);
		}
		// 修改邮箱
		printf("\n 邮箱(%s):", custmoer[index].email);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].email);
		}
		printf("\n---------------修改完成---------------\n");
}
void modify() {
	printf("\n--------------修改客户--------------");
	int id;
out:printf("\n请选择修改客户的编号（-1退出）：");
	scanf("%d", &id);
	getchar();

	if (id == -1)
		return 0;
	if (id > number || id <= 0)
	{
		printf("编号不存在，请重新输入");
		goto out;
	}
	edit(id);
}