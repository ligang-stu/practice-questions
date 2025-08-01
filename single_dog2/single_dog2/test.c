#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//题目：
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.


//解析思路：把 5 和 6 分在两个不同的组， 各自的组在分别异或处理就能找到 5 和 6。
//	分组思路：1.把数组中所有的数进行异或，得到的结果就是 --> 5^6 --> 0101 ^ 0110 --> 0011
//			  2.将异或结果依次向右移 i(0-31)位，右移后的结果与 1 进行 & 操作，如果得到 1 说明 5 和 6 在 i位不同，记录i位。
//			  3.根据 记录的i位，将数组中每个元素右移 i 位 进行分组。

void find_dog(int* arr,int n) {
	int single1 = 0;  
	int single2 = 0;
	int i = 0;
	int tmp = 0;
	int k = 0;
	for (i = 0;i < n;i++) 
	{
		tmp ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((tmp >> i) & 1) == 1)
		{
			k = i;
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (((arr[i] >> k) & 1) == 1)
			single1 ^= arr[i];
		else
			single2 ^= arr[i];
	}
	
	printf("单身狗分别是 %d 和 %d",single1,single2);
}

int main() {
	int arr[] = {1,2,3,4,5,1,2,3,4,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	find_dog(arr,n);
	return 0;
}