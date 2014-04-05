#pragma once

#include "database.h"
#include "Cell.h"


class Board
{
	DataBase DataBase;
	PuzzleState _puzzleState;

public:
	Cell Cells[ROW * COL];

public:
	Board(int levelNo);

	void DrawBoard(RenderWindow & window);
};
