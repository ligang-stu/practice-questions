#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//题目：
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//方法1
void leftRound1(char* a, int len, int time) {
	int count = time % len;
	char tmp = 0;
	int j = 0;

	while (count)
	{
		tmp = a[0];
		for (j = 0; j < len - 1; j++)
		{
			a[j] = a[j + 1];
		}
		a[j] = tmp;
		count--;
	}
}
//方法2
void leftRound2(char* a, int len, int time) {
	char tmpArr[20] = { 0 };
	int count = time % len;
	strcpy(tmpArr, a + count);
	strncat(tmpArr, a, count);
	strcpy(a, tmpArr);
}

//方法3
void reverse(char* a, int start, int end) {
	char tmp = 0;
	while (start < end)
	{
		tmp = a[start];
		a[start] = a[end];
		a[end] = tmp;

		start++;
		end--;
	}
}
void leftRound3(char* a, int len, int time) {
	int count = time % len;
	reverse(a, 0, count - 1);
	reverse(a, count, len - 1);
	reverse(a, 0, len - 1);

}

int main() {
	char a[20] = { 0 };
	int len = 0;
	int time = 0;

	printf("请输入你要左旋的字符串：");
	scanf("%s", a);
	len = strlen(a);

	printf("请输入你要左旋的次数：");
	scanf("%d", &time);

	//leftRound1(a,len,time);
	//leftRound2(a, len, time);
	leftRound3(a, len, time);
	printf("%s", a);
	return 0;
}