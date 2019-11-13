#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int find_num(int **arr, int row, int col, int key, int *px, int *py)
{
	//从右上角开始查找
	int startx = 0;
	int starty = col - 1;
	while (startx < row && starty >= 0)
	{
		if (arr[startx][starty] < key)
			startx++;
		else if (arr[startx][starty] > key)
			starty--;
		else
		{
			*px = startx;
			*py = starty;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}

int recursive_find_num(int **arr, int row, int col, int key, int *px, int *py, int startx, int starty)
 {
	if (startx < row && starty >= 0)
	{
		if (arr[startx][starty] == key)
		{
			*px = startx;
			*py = starty;
			return 1;
		}
		else if (arr[startx][starty] < key)
			return recursive_find_num(arr, row, col, key, &px, &py, startx + 1, starty);
		else
			return recursive_find_num(arr, row, col, key, &px, &py, startx, starty - 1);
	}
	return -1;
}

int main()
{
	int row = 0;
	int col = 0;
	int key = 0;
	int px = 0;
	int py = 0;
	printf("请输入行数与列数:>");
	scanf("%d %d", &row, &col);
	int **arr = (int **)malloc(sizeof(int *) * row);
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * col);
		printf("请输入第%d行:>", i + 1);
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	printf("请输入要查找的数:>");
	scanf("%d", &key);
	find_num(arr, row, col, key, &px, &py);
	if (recursive_find_num(arr, row, col, key, &px, &py, 0, col - 1) != -1) //从右上角开始查找
		printf("px = %d, py = %d\n", px, py);
	else
		printf("未找到\n");

	for (int i = 0; i < col; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;

	printf("\n");
	system("pause");
	return 0;
}