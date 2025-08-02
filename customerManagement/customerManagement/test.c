#define _CRT_SECURE_NO_WARNINGS
#include "manage.h"

int number = 0;

void menu()
{
	printf("\n------------客户信息管理系统------------");
	printf("\n            1 添加客户");
	printf("\n            2 修改客户");
	printf("\n            3 删除客户");
	printf("\n            4 客户列表");
	printf("\n            5 退    出");
	printf("\n            请选择（1-5）：");


}

int  main() {
	int input = 0;

	do {
		menu();
		scanf("%d", &input);
		switch (input) {
			case 1:
				add();
				break;
			case 2:
				modify();
				break;
			case 3:
				del();
				break;
			case 4:
				list();
				break;
			case 5:
				input = 0;
				printf("退出系统！");
				break;
			default:
				printf("\n请选择1-5以内的数字!");
				break;

		}

	} while (input);

	return 0;
}