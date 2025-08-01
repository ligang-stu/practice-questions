#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 9
#define col 9
#define rows row+2
#define cols col+2
#define Mine_Num row

//游戏菜单
void menu();
//初始化棋盘
void	initbroad(char(*broad)[rows], int r, int c, char set);
//打印棋盘
void	Printbroad(char (*broad)[rows], int r, int c);

//布置雷
void	setborad(char(*broad)[rows], int r, int c);

//排查雷
void findmine(char minebroad[][rows], char showbroad[][rows], int r, int c);


