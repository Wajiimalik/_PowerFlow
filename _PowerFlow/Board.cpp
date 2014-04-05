#include "Board.h"
#include "DataBase.h"

Board::Board(int levelNo) : _puzzleState(UnSolved)
{
	DataBase.SetLevelNo(levelNo);
	DataBase.LoadDataBase();

	//giving values to members "_left" and "_top" of each cell
	for (int i = 50, index = 0; i <= 530; i += 120)
	{
		for (int j = 50; j <= 530; j += 120, index++)
		{
			Cells[index].SetCell(j, i);
		}
	}

	//passing data loaded from dataBase to rest objects
	for (int i = 0; i < ROW*COL; i++)
	{
		Cells[i].SetIndexOfThisCell(i);
		Cells[i].SetObjectType(DataBase.GetObjectType(i));
		Cells[i].SetConnectionType(DataBase.GetConnectionType(i));
		Cells[i]._ptrConnection->SetConnectionPosition(DataBase.GetUnSolvedPuzzle(i));
		Cells[i]._ptrConnection->SetSolvedConnectionPosition(DataBase.GetSolvedPuzzle(i));
	}

}

void Board :: DrawBoard(RenderWindow & window)
{
	//drawing grid and assigning values to cell params
	for (int index = 0; index < ROW * COL ; index++)
	{
		Cells[index].DrawCell(window);
	}

	window.display();
}
