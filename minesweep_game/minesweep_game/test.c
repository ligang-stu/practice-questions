#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("\n");
	printf("---------��Ϸ�˵�---------\n");
	printf("**************************\n");
	printf("******** 1. play *********\n");
	printf("******** 0. exit *********\n");
	printf("**************************\n");
	printf("\n");
}

void game() {

	char minebroad[rows][cols] = { 0 };
	char showbroad[rows][cols] = { 0 };
	//��ʼ������
	initbroad(minebroad,rows,cols,'0');
	initbroad(showbroad, rows, cols, '*');
	
	//������
	setborad(minebroad, row, col);
	
	//��ӡ����
	Printbroad(showbroad, row, col);

	//Printbroad(minebroad, row, col);
	
	//�Ų���
	findmine(minebroad,showbroad,row,col);

}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ���Ƿ�ʼ��Ϸ����1��ʼ��Ϸ����0�˳���Ϸ��");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}