#pragma once
//#ifndef DATABASE_H
//#define DATABASEH


#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

#define ROW 5
#define COL 5

#define CELL_LENGTH 120

enum ObjectType { Factory, House, Connection };
enum ConnectionType { L_Shaped, T_Shaped, Straight, Mini };
enum ConnectionPosition { Pos1, Pos2, Pos3, Pos4 };
enum ObjectState { Lit, UnLit };
enum GameState { Selection, Level1, Level2, Win };
enum PuzzleState { Solved, UnSolved };


typedef ObjectType ObjectType;
typedef ConnectionType ConnectionType;
typedef ConnectionPosition ConnectionPosition;
typedef ObjectState ObjectState;
typedef GameState GameState;
typedef PuzzleState PuzzleState;


class Co_Ordinates
{
	int _x;
	int _y;

public:
	Co_Ordinates();

	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

	bool operator == (Co_Ordinates c);

};


class DataBase
{
	char ObjectsType[ROW * COL];
	char connectionType[ROW * COL];
	int solvedPuzzle[ROW * COL];
	int unSolvedPuzzle[ROW * COL];

public:
	//method for test program //in end this part would be removed
	void AssigningValuesToFactoryHouses();
	void AssigningValuesToConnectionType();
	void AssigningValuesToSolvedPuzzle();
	void AssigningValuesToUnSolvedPuzzle();

	void LoadDataBase(int levelNo);

	char GetObjectType(int index);
	char GetConnectionType(int index);
	int GetSolvedPuzzle(int index);
	int GetUnSolvedPuzzle(int index);
};
//#endif /* DATABASE_H */