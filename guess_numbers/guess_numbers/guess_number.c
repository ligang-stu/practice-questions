#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu() {
	printf("\n");
	printf("**************************\n");
	printf("******** 1. play *********\n");
	printf("******** 0. exit *********\n");
	printf("**************************\n");
	printf("\n");
}

void game() {
	int chance = 5;
	int ans = rand() % 100 + 1;
	int guess = 0;
	
	while (chance) {
		printf("��������Ҫ�µ����֣�");
		scanf("%d", &guess);
		chance--;
		if (guess == ans)
		{
			printf("��ϲ�����ˣ���Ϸ��������ȷ������%d\n", ans);
			break;
		}
		else if(guess < ans)
		{
			printf("�ش����,��µ�С�ˣ��㻹�� %d �λ���\n",chance);
		}else
			printf("�ش����,��µĴ��ˣ��㻹�� %d �λ���\n", chance);
		if (chance == 0)
			printf("��Ĳ����������ù⣬��Ϸʧ��!\n");

	}
}

int main() {
	srand((unsigned int) time(NULL));
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