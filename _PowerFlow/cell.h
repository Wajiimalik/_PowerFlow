#ifndef CELL_H
#define CELL_H


#include "datastructures.h"
#include "objects.h"

class Cell
{
private:
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
	Cell() { _cellState = UnLit; }


	void SetCell(int inLeft, int inTop)
	{
		_left = inLeft;
		_top = inTop;
	}

	void CalculateCoords()
	{
		//MidOfA
		_ptrConnection->Set_a_Coord(_left + (CELL_LENGTH / 2), _top);

		//MidOfB
		_ptrConnection->Set_b_Coord(_left + CELL_LENGTH, _top + (CELL_LENGTH / 2));

		//MidofC
		_ptrConnection->Set_c_Coord(_left + (CELL_LENGTH / 2), _top + CELL_LENGTH);

		//MidofD
		_ptrConnection->Set_d_Coord(_left, _top + (CELL_LENGTH / 2));

		//MidPt
		_ptrConnection->CalculateRefPoint();
		_midPoint = _ptrConnection->GetRefPt();
	}

	void SetObjectType(char inType)
	{
		switch (inType)
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

	//not in set object type method b/c these connections will be in each cell
	void SetConnectionType(char inType)
	{
		switch (inType)
		{
		case 'L':
			_connectionType = L_Shaped;
			_ptrConnection = new L_ShapedConnection;

			this->CalculateCoords();

			cout << endl << "Print left: " << _left << " top: " << _top << endl;
			_ptrConnection->SetConnectionsPosition(_connectionPosition);
			_ptrConnection->DrawObject();
			break;
		case 'T':
			_connectionType = T_Shaped;
			_ptrConnection = new T_ShapedConnection;
			this->CalculateCoords();
			_ptrConnection->SetConnectionsPosition(_connectionPosition);
			_ptrConnection->DrawObject();
			break;
		case 'S':
			_connectionType = Straight;
			_ptrConnection = new StraightConnection;
			this->CalculateCoords();
			_ptrConnection->SetConnectionsPosition(_connectionPosition);
			_ptrConnection->DrawObject();
			break;
		case 'M':
			_connectionType = Mini;
			_ptrConnection = new MiniConnection;
			this->CalculateCoords();
			_ptrConnection->SetConnectionsPosition(_connectionPosition);
			_ptrConnection->DrawObject();
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

	void SetLit()
	{
		_cellState = Lit;
		//set also object state of object
	}

	void SetUnLit()
	{
		_cellState = UnLit;
	}

	//we have get clicked cell
	void MoveObjectOfCell()
	{
		_ptrConnection->MoveObject();
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

	int GetTopOfCell()
	{
		return _top;
	}
};

#endif /* CELL_H */