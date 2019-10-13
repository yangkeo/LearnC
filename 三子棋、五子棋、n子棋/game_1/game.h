#ifndef GAME_H
#define GAME_H

#define ROW 11
#define COL 11
#define MODE 7

void DisplayBoard(char board[ROW][COL], int row, int col);
void GamerPlay(char board[ROW][COL], int row, int col);
void computerPlay(char board[ROW][COL], int row, int col);
char CheckWin(char board[ROW][COL], int row, int col, int mode);

#endif