#pragma once
//#ifndef BOARD_H
//#define BOARD_H

#include "database.h"
#include "Cell.h"


class Board
{
	DataBase DataBase;
	PuzzleState _puzzleState;

	RectangleShape _rectangle;
public:
	Cell Cells[ROW * COL];

public:
	Board(int levelNo);

	void DrawBoard(RenderWindow & window);

	bool CheckCellsState();

	bool CheckPuzzleState();
};
//#endif /* BOARD_H */
