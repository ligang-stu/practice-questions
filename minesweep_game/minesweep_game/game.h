#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 9
#define col 9
#define rows row+2
#define cols col+2
#define Mine_Num row

//��Ϸ�˵�
void menu();
//��ʼ������
void	initbroad(char(*broad)[rows], int r, int c, char set);
//��ӡ����
void	Printbroad(char (*broad)[rows], int r, int c);

//������
void	setborad(char(*broad)[rows], int r, int c);

//�Ų���
void findmine(char minebroad[][rows], char showbroad[][rows], int r, int c);


