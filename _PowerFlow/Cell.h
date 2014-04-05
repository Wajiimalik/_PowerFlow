#pragma once

#include "DataBase.h"
#include "Objects.h"


class Cell
{
	int _left;
	int _top;
	int _indexOfThisCell;
	Co_Ordinates _midPoint;

	RectangleShape _rectangle;

	ConnectionPosition _connectionPosition;

public:
	ObjectState _cellState;
	ObjectType _objectType;

	Objects *_ptrObjects;
	Connections_Object *_ptrConnection;

private:
	void CalculateCoords();
	void LitAllObjects();

public:
	Cell();
	void SetCell(int inLeft, int inTop);

	void SetObjectType(char inType);
	void SetConnectionType(char inType);


	void DrawCell(RenderWindow & window);
	bool GetClickedCell(int mouseX, int mouseY);

	void SetIndexOfThisCell(int index);
	int GetIndexOfThisCell();

};

