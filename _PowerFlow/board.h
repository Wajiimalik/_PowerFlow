#ifndef BOARD_H
#define BOARD_H


#include "database.h"
#include "Cell.h"

class Board
{
private:
	DataBase DataBase;
	PuzzleState _puzzleState;

public:
	Cell Cells[ROW * COL];	//objects of cell (25 in number)

public:
	Board(int levelNo)
	{
		_puzzleState = UnSolved;
		DataBase.LoadDataBase(levelNo);
		this->DrawBoard();

		for (int i = 0; i < ROW*COL; i++)
		{
			cout << "Index # " << i << endl;
			Cells[i].SetIndexOfThisCell(i);
			Cells[i].SetObjectType(DataBase.GetObjectType(i));
			Cells[i].SetConnectionPostion(DataBase.GetUnSolvedPuzzle(i));
			Cells[i].SetConnectionType(DataBase.GetConnectionType(i));

		}
		window.display();
	}

	void DrawBoard()
	{
		RectangleShape rectangle(Vector2f(CELL_LENGTH, CELL_LENGTH));
		rectangle.setFillColor(Color::Black);
		rectangle.setOutlineThickness(1);
		rectangle.setOutlineColor(Color::White);

		//drawing grid and assigning values to cell params
		for (int i = 50, index = 0; i <= 530; i += 120)
		{
			for (int j = 50; j <= 530; j += 120, index++)
			{
				rectangle.setPosition(j, i);
				window.draw(rectangle);
				Cells[index].SetCell(j, i);
				//Cells[index].CalculateCoords();
			}
		}

		//window.display();
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