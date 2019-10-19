#ifndef GAME_H
#define GAME_H

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 80

void DisplayMine(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void InitBoard(char board[ROWS][ROWS], int rows, int cols, char str);
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);

#endif