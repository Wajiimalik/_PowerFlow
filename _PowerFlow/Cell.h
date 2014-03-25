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

	ObjectState _cellState;
	ObjectType _objectType;

public:
	ConnectionType _connectionType;
	ConnectionPosition _connectionPosition;

	Objects *_ptrObjects;
	Connections_Object *_ptrConnection;

public:
	Cell();
	void SetCell(int inLeft, int inTop);
	void CalculateCoords();

	void SetObjectType(char inType);
	void SetConnectionType(char inType);
	void SetConnectionPostion(int inPos);

	void SetLit();
	void SetUnLit();

	void MoveObjectOfCell();

	void SetIndexOfThisCell(int index);
	int GetIndexOfThisCell();

	ObjectType GetObjectType();
	ConnectionType GetConnectiontype();
	ConnectionPosition GetConnectionPosition();

	int GetLeftOfCell();
	int GetTopOfCell();
};

//#endif /* CELL_H */
