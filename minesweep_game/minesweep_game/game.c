#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��ʼ������
void	initbroad(char(*broad)[rows], int r, int c,char set) {
	int i = 0;
	for (i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			broad[i][j] = set;
		}
	}
}

//��ӡ����
void	Printbroad(char (*broad)[rows], int r, int c) {
	printf("----------ɨ����Ϸ--------\n");
	for (int i = 0; i <= r; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= r; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= c; j++)
		{
			printf("%c ",broad[i][j]);
		}
		printf("\n");
	}
}

//������
void	setborad(char(*broad)[rows], int r, int c) {
	int x = 0; 
	int y = 0;
	int mine_num = Mine_Num;

	while (mine_num) 
	{
		x = rand() % r + 1;
		y = rand() % c + 1;
		if (broad[x][y] == '0')
		{
			broad[x][y] = '1';
			mine_num--;
		}
	}
}


int countMine(char broad[][rows], int x,int y)
{
	int i = 0;
	int num = 0;
	for (i = -1; i <= 1; i ++)
	{
		for(int j = -1;j <= 1;j++ )
			num += broad[x + i][y + j];
	}
	return	num - 8 *'0';
}
//�Ų���
void findmine(char minebroad[][rows],char showbroad[][rows] ,int r, int c) {
	int x, y;
	int win = row * col - Mine_Num;
	while (win)
	{
		printf("������Ҫ�Ų��λ�ã�");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c) {
			if (minebroad[x][y] == '0')
			{
				showbroad[x][y] = countMine(minebroad, x, y) ;
				Printbroad(showbroad, row, col);

			}
			else
			{
				printf("��ȵ���������Ϸʧ��,�������׵ķֲ����\n");
				Printbroad(minebroad, row, col);
				break;
			}
			win--;
		}
		else
		{
			printf("���������������������");
		}
	}
	if (!win)
	{
		printf("\n");
		printf("��ϲ���������е��ף���Ϸʤ�����������׵ķֲ����\n");
		Printbroad(minebroad, row, col);
	}

}


