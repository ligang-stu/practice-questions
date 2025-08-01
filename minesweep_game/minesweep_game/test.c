#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("\n");
	printf("---------游戏菜单---------\n");
	printf("**************************\n");
	printf("******** 1. play *********\n");
	printf("******** 0. exit *********\n");
	printf("**************************\n");
	printf("\n");
}

void game() {

	char minebroad[rows][cols] = { 0 };
	char showbroad[rows][cols] = { 0 };
	//初始化棋盘
	initbroad(minebroad,rows,cols,'0');
	initbroad(showbroad, rows, cols, '*');
	
	//布置雷
	setborad(minebroad, row, col);
	
	//打印棋盘
	Printbroad(showbroad, row, col);

	//Printbroad(minebroad, row, col);
	
	//排查雷
	findmine(minebroad,showbroad,row,col);

}
int main() {
	srand((unsigned int)time(NULL));
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