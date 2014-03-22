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

	Co_Ordinates _midOfA;
	Co_Ordinates _midOfB;
	Co_Ordinates _midOfC;
	Co_Ordinates _midOfD;

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
	

	void SetCell(int inLeft, int inTop)
	{
		_left = inLeft;
		_top = inTop;
	}

	void CalculateCoords(RenderWindow & window)
	{
		//MidOfA
		_midOfA.SetX(_left + (CELL_LENGTH / 2));
		_midOfA.SetY(_top);

		RectangleShape testA(Vector2f(3, 3));
		testA.setFillColor(Color::Green);
		testA.setPosition(_midOfA.GetX(), _midOfA.GetY());
		window.draw(testA);

		//MidOfB
		_midOfB.SetX(_left + CELL_LENGTH);
		_midOfB.SetY(_top + (CELL_LENGTH / 2));

		RectangleShape testB(Vector2f(3, 3));
		testB.setFillColor(Color::Green);
		testB.setPosition(_midOfB.GetX(), _midOfB.GetY());
		window.draw(testB);

		//MidofC
		_midOfC.SetX(_left + (CELL_LENGTH / 2));
		_midOfC.SetY(_top + CELL_LENGTH);

		RectangleShape testC(Vector2f(3, 3));
		testC.setFillColor(Color::Green);
		testC.setPosition(_midOfC.GetX(), _midOfC.GetY());
		window.draw(testC);

		//MidofD
		_midOfD.SetX(_left);
		_midOfD.SetY(_top + (CELL_LENGTH / 2));

		RectangleShape testD(Vector2f(3, 3));
		testD.setFillColor(Color::Green);
		testD.setPosition(_midOfD.GetX(), _midOfD.GetY());
		window.draw(testD);


		//MidPt
		_midPoint.SetX((_midOfD.GetX() + _midOfB.GetX()) / 2);
		_midPoint.SetY((_midOfA.GetY() + _midOfC.GetY()) / 2);

		RectangleShape mids(Vector2f(3, 3));
		mids.setFillColor(Color::Green);
		mids.setPosition(_midPoint.GetX(), _midPoint.GetY());
		window.draw(mids);

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
		_midOfA = _ptrConnection->GetCoordAOfConnection();
		_midOfB = _ptrConnection->GetCoordBOfConnection();
		_midOfC = _ptrConnection->GetCoordCOfConnection();
		_midOfD = _ptrConnection->GetCoordDOfConnection();
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


	Co_Ordinates GetMidOfA()
	{
		return _midOfA;
	}

	Co_Ordinates GetMidOfB()
	{
		return _midOfB;
	}

	Co_Ordinates GetMidOfC()
	{
		return _midOfC;
	}

	Co_Ordinates GetMidOfD()
	{
		return _midOfD;
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

	int GetTopOfCell()
	{
		return _top;
	}
};

#endif /* CELL_H */