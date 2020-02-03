#include "Sudoku.h"

void insertNumber(sudoku *s, int row_index, int col_index, int number)
{
	if(row_index < BOARD_HEIGTH && col_index < BOARD_WIDTH)
	{
		s->board[row_index][col_index] = number;
	}
}

int getNumber(sudoku *s, int row_index, int col_index)
{
	if(row_index < BOARD_HEIGTH && col_index < BOARD_WIDTH)
	{
		return s->board[row_index][col_index];
	}
	return 0;
}

void fillBoard(sudoku *s)
{
	srand(time(NULL));

	for(int i = 0; i < BOARD_HEIGTH; ++i)
		for(int j = 0; j < BOARD_WIDTH; ++j)
			insertNumber(s, i, j, 0);

	for(int k = 0; k < 27; ++k)
	{
		insertNumber(s, (rand() % 10), (rand() % 10), (1 + rand() % 9));
	}
}

void printBoard(sudoku *s)
{
	for(int i = 0; i < BOARD_HEIGTH; ++i)
	{
		for(int j = 0; j < BOARD_WIDTH; ++j)
		{
			printf("%i\t", getNumber(s, i, j));
		}
		printf("\n");
		printf("\n");
	}
	printf("\n");
}

int checkRow(sudoku *s, int row_index)
{
	int prod = 1l;
	int r = 0;
	for(int j = 0; j < BOARD_WIDTH; ++j)
	{
		prod *= getNumber(s, row_index, j);
	}
	prod == CHECK_VAL ? r = 1 : 0;
	return r;
}

int checkCol(sudoku *s, int col_index)
{
	int prod = 1l;
	int r = 0;
	for(int i = 0; i < BOARD_HEIGTH; ++i)
	{
		prod *= getNumber(s, i, col_index);
	}
	prod == CHECK_VAL ? r = 1 : 0;
	return r;
}

int checkBlock(sudoku *s, int block_index)
{
	int i0, j0;
	int prod = 1l;
	int r = 0;
	switch(block_index)
	{
		case BLOCK0: i0 = 0; j0 = 0; break;
		case BLOCK1: i0 = 0; j0 = 3; break;
		case BLOCK2: i0 = 0; j0 = 6; break;

		case BLOCK3: i0 = 3; j0 = 3; break;
		case BLOCK4: i0 = 3; j0 = 0; break;
		case BLOCK5: i0 = 3; j0 = 3; break;

		case BLOCK6: i0 = 6; j0 = 0; break;
		case BLOCK7: i0 = 6; j0 = 3; break;
		case BLOCK8: i0 = 6; j0 = 6; break;

		default: return 0;
	}

	for(int i = i0; i < i0+3; ++i)
	{
		for(int j = j0; j < j0+3; ++j)
		{
			prod *= getNumber(s, i, j);
		}
	}
	prod == CHECK_VAL ? r = 1 : 0;
	return r;
}
