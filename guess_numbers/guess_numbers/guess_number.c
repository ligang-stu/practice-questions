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
		printf("请输入你要猜的数字：");
		scanf("%d", &guess);
		chance--;
		if (guess == ans)
		{
			printf("恭喜你答对了，游戏结束。正确数字是%d\n", ans);
			break;
		}
		else if(guess < ans)
		{
			printf("回答错误,你猜的小了，你还有 %d 次机会\n",chance);
		}else
			printf("回答错误,你猜的大了，你还有 %d 次机会\n", chance);
		if (chance == 0)
			printf("你的猜数机会已用光，游戏失败!\n");

	}
}

int main() {
	srand((unsigned int) time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择是否开始游戏，按1开始游戏，按0退出游戏：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}