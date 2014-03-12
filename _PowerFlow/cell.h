#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

#include "objects.h"
using namespace std;

class Cell
{
private:
	int _left;
	int _right;
	int _top;
	int _bottom;
	int _indexOfThisCell;
	Co_Ordinates _midPoint;

	Co_Ordinates _coordAOfConnection;
	Co_Ordinates _coordBOfConnection;
	Co_Ordinates _coordCOfConnection;

	ObjectState _cellState;
	ObjectType _objectType;
	ConnectionType _connectionType;
	ConnectionPosition _connectionPosition;
	Objects *_ptrObjects;
	Connections_Object *_ptrConnection;

public:
	Cell() { _cellState = UnLit; }

	void DrawCell() {}

	void GetClickedCell(int mouseX, int mouseY) {}
	
	void SetCell(int inLeft, int inRight, int inTop, int inBottom)
	{
		_left = inLeft;
		_right = inRight;
		_top = inTop;
		_bottom = inBottom;
	}

	void SetObjectType(char inType)
	{
		switch(inType)
		{
		case 'F':
			_objectType = Factory;
			_ptrObjects = new Factory_Object;
			this->SetLit();
			_ptrObjects->DrawObject();
			break;
		case 'H':
			_objectType = House;
			_ptrObjects = new House_Object;
			_ptrObjects->DrawObject();
			break;
		case 'C':
			_objectType = Connection;
			break;
		default:
			cout << "InValid Object Type" << endl;
			break;
		}
	}

	void SetLit()
	{
		_cellState = Lit;
		//set also object state of object
	}

	void SetUnLit()
	{
		_cellState = UnLit;
	}

	//not in set object type method b/c these connections will be in each cell
	void SetConnectionType(char inType)
	{
		switch (inType)
		{
		case 'L':
			_connectionType = L_Shaped;
			_ptrConnection = new L_ShapedConnection;
			_ptrConnection->DrawObject();
			this->SetCoordOfConnections();
			break;
		case 'T':
			_connectionType = T_Shaped;
			_ptrConnection = new T_ShapedConnection;
			_ptrConnection->DrawObject();
			this->SetCoordOfConnections();
			break;
		case 'S':
			_connectionType = Straight;
			_ptrConnection = new StraightConnection;
			_ptrConnection->DrawObject();
			this->SetCoordOfConnections();
			break;
		case 'M':
			_connectionType = Mini;
			_ptrConnection = new MiniConnection;
			_ptrConnection->DrawObject();
			this->SetCoordOfConnections();
			break;
		default:
			cout << "InValid Connection Type" << endl;
			break;
		}
	}

	void SetConnectionPostion(int inPos)
	{
		switch (inPos)
		{
		case 1:
			_connectionPosition = Pos1;
			break;
		case 2:
			_connectionPosition = Pos2;
			break;
		case 3:
			_connectionPosition = Pos3;
			break;
		case 4:
			_connectionPosition = Pos4;
			break;
		default:
			cout << "InValid ConnectionPosition" << endl;
		}
	}

	//GET METHODS FOR COORD
	void SetCoordOfConnections()
	{
		_coordAOfConnection = _ptrConnection->GetCoordAOfConnection();
		_coordBOfConnection = _ptrConnection->GetCoordBOfConnection();
		_coordCOfConnection = _ptrConnection->GetCoordCOfConnection();
	}

	Co_Ordinates GetCoordAOfConnection()
	{
		return _coordAOfConnection;
	}

	Co_Ordinates GetCoordBOfConnection()
	{
		return _coordBOfConnection;
	}

	Co_Ordinates GetCoordCOfConnection()
	{
		return _coordCOfConnection;
	}

	//we have get clicked cell
	void MoveObjectOfCell()
	{
		_ptrConnection->MoveObject();
		this->SetCoordOfConnections();
	}

	void SetIndexOfThisCell(int index)
	{
		_indexOfThisCell = index;
	}

	int GetIndexOfThisCell()
	{
		return _indexOfThisCell;
	}

	ObjectType GetObjectType()
	{
		return _objectType;
	}

	ConnectionType GetConnectiontype()
	{
		return _connectionType;
	}

	ConnectionPosition GetConnectionPosition()
	{
		return _connectionPosition;
	}

	int GetLeftOfCell()
	{
		return _left;
	}

	int GetRightOfCell()
	{
		return _right;
	}

	int GetTopOfCell()
	{
		return _top;
	}

	int GetBottomOfCell()
	{
		return _bottom;
	}

	int GetPosOfConnection()
	{
	}
};

#endif /* CELL_H */