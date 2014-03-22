#ifndef DATABASE_H
#define DATABASE_H

#include "datastructures.h"

class DataBase
{
private:
	char ObjectsType[ROW * COL];
	char connectionType[ROW * COL];
	int solvedPuzzle[ROW * COL];
	int unSolvedPuzzle[ROW * COL];

	PuzzleState PuzzleState;

public:
	//method for test program //in end this part would be removed
	void AssigningValuesToFactoryHouses()
	{
		ObjectsType[16] = 'F'; ObjectsType[0] = 'H'; ObjectsType[3] = 'H'; ObjectsType[4] = 'H';
		ObjectsType[8] = 'H'; ObjectsType[17] = 'H'; ObjectsType[18] = 'H'; ObjectsType[20] = 'H';

		for (int i = 0; i < 25; i++)
		{
			if (ObjectsType[i] != 'H' && ObjectsType[i] != 'F')
			{
				ObjectsType[i] = 'C';
			}
		}
	}

	//2nd array telling the connection type
	//method for test program //in end this part would be removed
	void AssigningValuesToConnectionType()
	{
		connectionType[0] = 'M';
		connectionType[3] = 'M'; connectionType[4] = 'M'; connectionType[8] = 'M';
		connectionType[16] = 'M'; connectionType[17] = 'M'; connectionType[18] = 'M'; connectionType[20] = 'M';

		connectionType[1] = 'L'; connectionType[15] = 'L'; connectionType[24] = 'L';

		connectionType[2] = 'S'; connectionType[5] = 'S'; connectionType[7] = 'S'; connectionType[9] = 'S';
		connectionType[12] = 'S'; connectionType[19] = 'S'; connectionType[21] = 'S'; connectionType[23] = 'S';


		connectionType[6] = 'T'; connectionType[10] = 'T'; connectionType[11] = 'T';
		connectionType[13] = 'T'; connectionType[14] = 'T'; connectionType[22] = 'T';
	}

	//3rd array and the main array. UnSolved puzzle would be compared by this at every move
	//method for test program //in end this part would be removed
	void AssigningValuesToSolvedPuzzle()
	{
		solvedPuzzle[0] = 4; solvedPuzzle[1] = 2; solvedPuzzle[2] = 1; solvedPuzzle[3] = 2; solvedPuzzle[4] = 4;

		solvedPuzzle[5] = 2; solvedPuzzle[6] = 4; solvedPuzzle[7] = 1; solvedPuzzle[8] = 2; solvedPuzzle[9] = 2;

		solvedPuzzle[10] = 4; solvedPuzzle[11] = 3; solvedPuzzle[12] = 1; solvedPuzzle[13] = 1; solvedPuzzle[14] = 2;

		solvedPuzzle[15] = 1; solvedPuzzle[16] = 2; solvedPuzzle[17] = 4; solvedPuzzle[18] = 3; solvedPuzzle[19] = 2;

		solvedPuzzle[20] = 1; solvedPuzzle[21] = 1; solvedPuzzle[22] = 3; solvedPuzzle[23] = 2; solvedPuzzle[24] = 4;

	}

	//4rth array having values of unsolved puzzle that would changed by user to make it solve
	//method for test program //in end this part would be removed
	void AssigningValuesToUnSolvedPuzzle()
	{
		unSolvedPuzzle[0] = 2; unSolvedPuzzle[1] = 1; unSolvedPuzzle[2] = 1; unSolvedPuzzle[3] = 1; unSolvedPuzzle[4] = 3;

		unSolvedPuzzle[5] = 1; unSolvedPuzzle[6] = 1; unSolvedPuzzle[7] = 2; unSolvedPuzzle[8] = 1; unSolvedPuzzle[9] = 1;

		unSolvedPuzzle[10] = 1; unSolvedPuzzle[11] = 4; unSolvedPuzzle[12] = 1; unSolvedPuzzle[13] = 3; unSolvedPuzzle[14] = 4;

		unSolvedPuzzle[15] = 2; unSolvedPuzzle[16] = 4; unSolvedPuzzle[17] = 3; unSolvedPuzzle[18] = 2; unSolvedPuzzle[19] = 2;

		unSolvedPuzzle[20] = 2; unSolvedPuzzle[21] = 1; unSolvedPuzzle[22] = 2; unSolvedPuzzle[23] = 1; unSolvedPuzzle[24] = 2;

	}

public:
	DataBase() {  }

	void LoadDataBase(int levelNo)
	{
		this->AssigningValuesToConnectionType();
		this->AssigningValuesToFactoryHouses();
		this->AssigningValuesToSolvedPuzzle();
		this->AssigningValuesToUnSolvedPuzzle();
		//assigns value from filing to these 4 params //(set method)
	}

	char GetObjectType(int index)
	{
		return ObjectsType[index];
	}

	char GetConnectionType(int index)
	{
		return connectionType[index];
	}

	int GetSolvedPuzzle(int index)
	{
		return solvedPuzzle[index];
	}

	int GetUnSolvedPuzzle(int index)
	{
		return unSolvedPuzzle[index];
	}
};

#endif /* DATABASE_H */