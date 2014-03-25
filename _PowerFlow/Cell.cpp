
#include "Cell.h"

	Cell :: Cell() 
	{ 
		_cellState = UnLit; 
	}


	void Cell :: SetCell(int inLeft, int inTop)

	{
		_left = inLeft;
		_top = inTop;
	}

	void Cell :: CalculateCoords()
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

	void Cell :: SetObjectType(char inType)
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
	void Cell :: SetConnectionType(char inType)
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

	void Cell :: SetConnectionPostion(int inPos)
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

	void Cell :: SetLit()
	{
		_cellState = Lit;
		//set also object state of object
	}

	void Cell :: SetUnLit()
	{
		_cellState = UnLit;
	}

//we have get clicked cell
		void Cell :: MoveObjectOfCell()
	{
		_ptrConnection->MoveObject();
	}

	void Cell :: SetIndexOfThisCell(int index)
	{
		_indexOfThisCell = index;
	}

	int Cell :: GetIndexOfThisCell()
	{
		return _indexOfThisCell;
	}

	ObjectType Cell :: GetObjectType()
	{
		return _objectType;
	}

	ConnectionType Cell :: GetConnectiontype()
	{
		return _connectionType;
	}

	ConnectionPosition Cell :: GetConnectionPosition()
	{
		return _connectionPosition;
	}

	int Cell :: GetLeftOfCell()
	{
		return _left;
	}

	int Cell :: GetTopOfCell()
	{
		return _top;
	}