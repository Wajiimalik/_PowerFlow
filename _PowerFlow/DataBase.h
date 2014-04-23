#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

#define ROW 5
#define COL 5

#define CELL_LENGTH 120
#define CONNECTION_SIZE 8

enum ObjectType { Factory, House, Connection };
enum ConnectionType { L_Shaped, T_Shaped, Straight, Mini };
enum ConnectionPosition { Pos1, Pos2, Pos3, Pos4 };
enum ObjectState { Lit, UnLit };
enum GameState { Selection, Playing, Transition, Win };
enum MenuMode { Start, MenuOptions, Level, Instructions, About };
enum PuzzleState { Solved, UnSolved };


typedef ObjectType ObjectType;
typedef ConnectionType ConnectionType;
typedef ConnectionPosition ConnectionPosition;
typedef ObjectState ObjectState;
typedef GameState GameState;
typedef MenuMode MenuMode;
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

	int _levelNo;


private: //methods
	//method for test program //in end this part would be removed
	void AssigningValuesToFactoryHouses();
	void AssigningValuesToConnectionType();
	void AssigningValuesToSolvedPuzzle();
	void AssigningValuesToUnSolvedPuzzle();

	void AssigningValuesToFactoryHouses(int a,char c);
	void AssigningValuesToConnectionType(int a,char c);
	void AssigningValuesToSolvedPuzzle(int a,char c);
	void AssigningValuesToUnSolvedPuzzle(int a,char c);

public:
	void SetLevelNo(int level);

	void LoadDataBase();
	char GetObjectType(int index);
	char GetConnectionType(int index);
	int GetSolvedPuzzle(int index);
	int GetUnSolvedPuzzle(int index);
};
