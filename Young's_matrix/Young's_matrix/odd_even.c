#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverseArr(int* arr, int sz)
{
	int start = 0;
	int end = sz - 1;
	while (start < end)
	{
		while (arr[start] % 2 != 0 && start < end)
			start++;
		while (arr[end] % 2 == 0 && start < end)
			end--;
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	reverseArr(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	printf("\n");
	system("pause");
	return 0;
}