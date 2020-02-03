#include "Sudoku.h"

int main(int argc, char *argv[])
{
	sudoku mainSudoku;
	fillBoard(&mainSudoku);
	printBoard(&mainSudoku);
	if(checkRow(&mainSudoku, 1))
		puts("Row 1 is correct");
	else
		puts("Row 1 is wrong");

	if(checkCol(&mainSudoku, 1))
		puts("Col 1 is correct");
	else
		puts("Col 1 is wrong");

	if(checkBlock(&mainSudoku, 0))
		puts("Block 0 is correct");
	else
		puts("Block 0 is wrong");

	return 0;
}
