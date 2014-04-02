#pragma once
//#ifndef CELL_H
//#define CELL_H

#include "DataBase.h"
#include "Objects.h"


class Cell
{
	int _left;
	int _top;
	int _indexOfThisCell;
	Co_Ordinates _midPoint;

	RectangleShape _rectangle;

	ObjectState _cellState;
	ObjectType _objectType;


	ConnectionType _connectionType;
	ConnectionPosition _connectionPosition;

public:
	Objects *_ptrObjects;
	Connections_Object *_ptrConnection;

public:
	Cell();
	void SetCell(int inLeft, int inTop);
	void CalculateCoords();

	void SetObjectType(char inType);
	void SetConnectionType(char inType);
	void SetConnectionPostion(int inPos);

	void LitAllObjects();

	void DrawCell(RenderWindow & window /*, RectangleShape & rectangle */);
	bool GetClickedCell(int mouseX, int mouseY);

	void SetIndexOfThisCell(int index);
	int GetIndexOfThisCell();

	//extras
	ObjectType GetObjectType();
	ConnectionType GetConnectiontype();
	ConnectionPosition GetConnectionPosition();

	int GetLeftOfCell();
	int GetTopOfCell();
};

//#endif /* CELL_H */
