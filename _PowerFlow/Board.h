#pragma once

#include "database.h"
#include "Cell.h"


class Board
{
	DataBase DataBase;
	PuzzleState _puzzleState;
	int _levelNo;

	Sprite Level1;
	Sprite Level2;
	Sprite Level3;
	Sprite Level4;
	Sprite Level5;

public:
	Cell Cells[ROW * COL];

public:
	Board(int levelNo);

	void SetTexture(Texture & l1, Texture & l2, Texture & l3, Texture & l4, Texture & l5);
	void DrawLevelbar(RenderWindow & window);
	void DrawBoard(RenderWindow & window);
};
