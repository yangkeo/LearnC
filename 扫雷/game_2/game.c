#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

void InitBoard(char board[ROWS][ROWS], int rows, int cols, char str)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = str;
		}
	}
}

void DisplayMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n"); 
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row + 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < col + 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	InitBoard(mine, ROWS, COLS, '0');
	while (count)
	{
		x = rand() % (ROW + 1);
		y = rand() % (COL + 1);
		if (x > 0 && y > 0)
		{
			if (mine[x][y] != '1')
			{
				mine[x][y] = '1';
				count--;
			}
		}		
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] + mine[x + 1][y - 1] + mine[x][y - 1] + mine[x - 1][y - 1] - 8 * '0';
}

void MyGetMineCount(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int count = GetMineCount(mine, x, y);
	if (count == 0)
	{
		show[x][y] = ' ';
		if (x - 1 > 0 && x - 1 <= ROW && y > 0 && y <= COL && show[x - 1][y] == '*')
			MyGetMineCount(mine, show, x - 1, y);	
		if (x - 1 > 0 && x - 1 <= ROW && y + 1 > 0 && y + 1 <= COL && show[x - 1][y + 1] == '*')
			MyGetMineCount(mine, show, x - 1, y + 1);		
		if (x > 0 && x <= ROW && y + 1 > 0 && y + 1 <= COL && show[x][y + 1] == '*')
			MyGetMineCount(mine, show, x, y + 1);		
		if(x + 1 > 0 && x + 1 <= ROW && y + 1 > 0 && y + 1 <= COL && show[x + 1][y + 1] == '*')
			MyGetMineCount(mine, show, x + 1, y + 1);		
		if (x + 1 > 0 && x + 1 <= ROW && y > 0 && y <= COL && show[x + 1][y] == '*')
			MyGetMineCount(mine, show, x + 1, y);		
		if (x + 1 > 0 && x + 1 <= ROW && y - 1 > 0 && y - 1 <= COL && show[x + 1][y - 1] == '*')
			MyGetMineCount(mine, show, x + 1, y - 1);	
		if (x > 0 && x <= ROW && y - 1 > 0 && y - 1 <= COL && show[x][y - 1] == '*')
			MyGetMineCount(mine, show, x, y - 1);	
		if (x - 1> 0 && x - 1 <= ROW && y - 1 > 0 && y - 1 <= COL && show[x - 1][y - 1] == '*')
			MyGetMineCount(mine, show, x - 1, y - 1);		
	}
	else
	{
		show[x][y] = count + '0';
	}
}

void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int flag = 0;
	int first = 0;
	while (flag < row * col - EASY_COUNT)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			while(mine[x][y] == '1' && first == 0)
			{
				SetMine(mine, ROW, COL);
			}
			first++;
			if (mine[x][y] == '1')
			{
				printf("你被炸死了！");
				DisplayMine(mine, ROW, COL);
				break;
			}
			else
			{
				MyGetMineCount(mine, show, x, y);
				DisplayMine(show, ROW, COL);
				flag++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入:>");
		}
		if (flag == row * col - EASY_COUNT)
		{
			printf("恭喜你，排雷成功！共用了%d步", first);
			DisplayMine(mine, ROW, COL);
			break;
		}
	}	
}