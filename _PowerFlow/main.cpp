#include <iostream>
#include <string>

#include "datastructures.h"
#include "board.h"
using namespace std;

int main()
{
	DataBase DataBase;

	int levelNo = 1;
	DataBase.LoadDataBase(levelNo);

	Board Board;
	for (int i = 0; i < ROW*COL; i++)
	{
		cout << "Index # " << i << endl;
		Board.Cells[i].SetIndexOfThisCell(i);
		Board.Cells[i].SetObjectType( DataBase.GetObjectType(i) );
		Board.Cells[i].SetConnectionType( DataBase.GetConnectionType(i) );
		Board.Cells[i].SetConnectionPostion(DataBase.GetUnSolvedPuzzle(i));
	}

	for (int i = 0; i < ROW*COL; i++)
	{
		cout << "Index # " << Board.Cells[i].GetIndexOfThisCell() << endl;
		cout << "Object Type: " << Board.Cells[i].GetObjectType() << endl;
		cout << "Connection Type: " << Board.Cells[i].GetConnectiontype() << endl;
		cout << "Connection Position: " << Board.Cells[i].GetConnectionPosition() << endl<<endl;
	}

	return 0;
}