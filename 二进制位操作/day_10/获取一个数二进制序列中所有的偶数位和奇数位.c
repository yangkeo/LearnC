#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n = 0;
	int arr[32] = { 0 };
	int i = 0;
	int count = 0;
	scanf("%d", &n);
	while (n)
	{
		arr[i++] = n % 2;
		n >>= 1;
		count++;
	}
	printf("偶数位:");
	for (i = count - 1; i >= 0; i -= 2)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("奇数位:");
	for (i = count - 2; i >= 0; i -= 2)
	{
		printf("%d", arr[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}

