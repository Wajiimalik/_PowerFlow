#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

#include "datastructures.h"
#include "Cell.h"
using namespace std;

class Board
{
private:
	int _cellNo;	//index of cell
	PuzzleState _puzzleState;

public:
	Cell Cells[ROW * COL];	//objects of cell (25 in number)

public:
	Board()
	{
		_cellNo = 0;
		_puzzleState = UnSolved;
	}

	void DrawBoard()
	{
		//draw grid line
		//draw cell call
		_cellNo++;
	}

	bool CheckCellsState()
	{
		//compares coord of connection to check lit or unlit
		//then call cell setlit
	}

	bool CheckPuzzleState()
	{
		//if solved then game over
	}
};

#endif /* BOARD_H */