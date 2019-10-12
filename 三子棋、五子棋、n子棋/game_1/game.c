#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

//������ʾ
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}

//�ж������Ƿ�����
static int CheckFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//�ж��Ƿ��ʤ
char CheckWin(char board[ROW][COL], int row, int col, int mode)
{
	int i = 0;
	int j = 0;
	int flag= 0;
	int mode_1 = 0;

	//�ж������
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}

	//�ж������
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[j][i];
			}
		}
		flag = 0;		
	}

	//���Խ���(45�����)���ϰ벿�� 
	for (mode_1 = mode - 1; mode_1 < col; mode_1++)
	{
		for (i = 0, j = mode_1; j > 0; i++, j--)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	
	//���Խ��ߣ�45����ȣ����°벿��
	for (mode_1 = 1; mode_1 < col - mode + 1; mode_1++)
	{
		for (i = row - 1, j = mode_1; j <col; i--, j++)
		{
			if (board[i][j] == board[i - 1][j + 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}

	//���Խ���(135�����)���ϰ벿�� 
	for (mode_1 = 0; mode_1 < col - mode + 1; mode_1++)
	{
		for (i = 0, j = mode_1; j < col; i++, j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	
	//���Խ���(135�����)���°벿�� 
	for (mode_1 = mode - 1; mode_1 < col - 1; mode_1++)
	{
		for (i = row - 1, j = mode_1; j > 0; i--, j--)
		{
			if (board[i][j] == board[i - 1][j - 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	
	if (CheckFull(board, row, col) == 0)  
	{
		//����
		return 'c';
	}
	//ƽ��
	return 'q';
}

//��Ҳ���
void GamerPlay(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
		    {
			printf("�ѱ�ռ�ã�����������:>");
		    }
		}
		else
		{
			printf("����Ƿ�������������:>");
		}
	}	
}

//���Բ���
void computerPlay(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������;>\n");
	while (1)
	{
		x = rand() % (row + 1);
		y = rand() % (col + 1);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}