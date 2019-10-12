#define _CRT_SECURE_NO_WARNINGS
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
	char board[ROW][COL] = { 0 };
	char ret = 0;
	printf("模式为%d子棋模式，棋盘大小%d * %d\n", MODE, ROW, COL);
	memset(board, ' ', ROW * COL * sizeof(board[0][0]));	
	while (1)
	{
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL, MODE);
		if (ret != 'c')
		{
			break;
		}
		GamerPlay(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL, MODE);
		if (ret != 'c')
		{
			break;
		}
		computerPlay(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main(void)
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
		case 0:
			printf("退出游戏...");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);

	printf("\n");
	system("pause");
	return 0;
}
