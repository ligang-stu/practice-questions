#define _CRT_SECURE_NO_WARNINGS
#include "manage.h"

int number = 0;

void menu()
{
	printf("\n------------�ͻ���Ϣ����ϵͳ------------");
	printf("\n            1 ��ӿͻ�");
	printf("\n            2 �޸Ŀͻ�");
	printf("\n            3 ɾ���ͻ�");
	printf("\n            4 �ͻ��б�");
	printf("\n            5 ��    ��");
	printf("\n            ��ѡ��1-5����");


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
				printf("�˳�ϵͳ��");
				break;
			default:
				printf("\n��ѡ��1-5���ڵ�����!");
				break;

		}

	} while (input);

	return 0;
}