#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define BOARD_WIDTH 9
#define BOARD_HEIGTH 9

#define CHECK_VAL (1l*2l*3l*4l*5l*6l*7l*8l*9l)

#define BLOCK0 0
#define BLOCK1 1
#define BLOCK2 2
#define BLOCK3 3
#define BLOCK4 4
#define BLOCK5 5
#define BLOCK6 6
#define BLOCK7 7
#define BLOCK8 8

struct s_sudoku
{
	int board[BOARD_WIDTH][BOARD_HEIGTH];
};
typedef struct s_sudoku sudoku;

void insertNumber(sudoku *s, int row_index, int col_index, int number);
int getNumber(sudoku *s, int row_index, int col_index);
void fillBoard(sudoku *s);
void printBoard(sudoku *s);
int checkRow(sudoku *s, int row_index);
int checkCol(sudoku *s, int col_index);
int checkBlock(sudoku *s, int block_index);

#endif
