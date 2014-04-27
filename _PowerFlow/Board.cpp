#include "Board.h"
#include "DataBase.h"

Board::Board(int levelNo) : _puzzleState(UnSolved), _levelNo(levelNo)
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

void Board :: SetTexture(Texture & l1, Texture & l2, Texture & l3, Texture & l4, Texture & l5)
{
	Level1.setTexture(l1);
	Level2.setTexture(l2);
	Level3.setTexture(l3);
	Level4.setTexture(l4);
	Level5.setTexture(l5);

	Level1.setPosition(680, 40);
	Level2.setPosition(680, 40);
	Level3.setPosition(680, 40);
	Level4.setPosition(680, 40);
	Level5.setPosition(680, 40);

}

void Board::DrawLevelbar(RenderWindow & window)
{
	switch (_levelNo)
	{
	case 1:
		window.draw(Level1);
		break;

	case 2:
		window.draw(Level2);
		break;

	case 3:
		window.draw(Level3);
		break;

	case 4:
		window.draw(Level4);
		break;

	case 5:
		window.draw(Level5);
		break;
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
