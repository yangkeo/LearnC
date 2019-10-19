#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "game.h"


void meun(void)
{
	printf("**************************************************************\n");
	printf("********                1、Play                      *********\n");
	printf("********                0、Exit                      *********\n");
	printf("**************************************************************\n");
}

void PlayGame(void)
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(show, ROWS, COLS, '*');
	

	DisplayMine(show, ROW, COL);
	SetMine(mine, ROW, COL);
	//DisplayMine(mine, ROW, COL);
	FindMine(show, mine, ROW, COL);
}

int main(void)
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		meun();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			PlayGame();
			break;
		case 2:
			printf("退出游戏...");
			break;
		}
	} while (input);

	printf("\n");
	system("pause");
	return 0;
}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	while (scanf("%d %d", &m, &n) != EOF)
//	{
//		int count = 0;
//		while (m)
//		{
//			count += m % n;
//			m /= n;
//		}
//
//		int arr[32] = {0};
//		int i = 0;
//
//		while (count)
//		{
//			arr[i] = count%n;
//			i++;
//			count /= n;
//		}
//
//		while (--i >= 0)
//		{
//			if (arr[i] < 10)  //十进制内
//				printf("%d", arr[i]);
//			else
//				printf("%c", arr[i] - 10 + 'A');
//		}
//		printf("\n");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}