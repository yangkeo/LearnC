#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int *arr, int sz)
{
	int tmp = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		tmp ^= arr[i];
	}
	return tmp;
}

int find2(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = i + 1; j < sz; j++)
		{
			tmp = arr[i] ^ arr[j];
			if (tmp == 0)
			{
				arr[i] = 0;
				arr[j] = 0;
			}
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (arr[i] != 0)
			return arr[i];
	}
	return -1;
}

int main(void)
{
	int arr[7] = {5, 4, 5, 1, 6 ,4 , 6};
	int sz = sizeof(arr) / sizeof(arr[0]);

	printf("%d出现了一次\n", find(arr, sz));

	printf("\n");
	system("pause");
	return 0;
}


