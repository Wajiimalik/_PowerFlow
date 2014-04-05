#pragma once

#include "Cell.h"

//abstract class for factory and house
class Objects
{
protected:
	Co_Ordinates _ref_Coord;

public:
	ObjectState _objectState;

	Objects() { _objectState = UnLit; }

	void SetRefCoord(Co_Ordinates c)
	{
		_ref_Coord = c;
	}

	virtual void SetTexture(Texture & t, Texture & v) = 0;

	virtual void DrawObject(RenderWindow & window) = 0;
};


//Factory Object
class Factory_Object : public Objects
{
private:
	Sprite _Factory;

public:
	Factory_Object()
	{
		_objectState = Lit;
	}

	 void SetTexture(Texture & factory, Texture & v) override
	{
		_Factory.setTexture(factory);
		_Factory.setPosition(float(_ref_Coord.GetX() -40), float(_ref_Coord.GetY() - 45 ));
	}

	void DrawObject(RenderWindow & window) override
	{
		
		window.draw(_Factory);
	}

	~Factory_Object() {}
};


//House Object
class House_Object : public Objects
{
private:
	Sprite _HouseLit;
	Sprite _HouseUnLit;

public:
	House_Object()
	{
		_objectState = UnLit;
	}

	void SetTexture(Texture & houseLit, Texture & houseUnLit) override
	{
		_HouseLit.setTexture(houseLit);
		_HouseUnLit.setTexture(houseUnLit);

		_HouseLit.setPosition(float(_ref_Coord.GetX() - 32), float(_ref_Coord.GetY() - 40));
		_HouseUnLit.setPosition(float(_ref_Coord.GetX() - 32), float(_ref_Coord.GetY() - 40));
	}

	void DrawObject(RenderWindow & window) override
	{
		if (_objectState == Lit)
		{
			window.draw(_HouseLit);
		}
		if (_objectState == UnLit)
		{
			window.draw(_HouseUnLit);
		}
	}

	~House_Object() {}
};



//Connections Object (abstract class)
class Connections_Object
{
protected:
	Co_Ordinates _ref_Coord;

	Co_Ordinates _a_Coord;
	Co_Ordinates _b_Coord;
	Co_Ordinates _c_Coord;
	Co_Ordinates _d_Coord;
	
	RectangleShape _line;	//for drawing
	
public:
	ObjectState _objectState;
	ConnectionPosition _itsPosition;
	ConnectionPosition _solvedPosition;

	ConnectionType _connectionType;

protected:
	void DrawUp(RenderWindow & window)
	{
		_line.setSize(Vector2f(CONNECTION_SIZE, -(CELL_LENGTH / 2)));
		window.draw(_line);
	}

	void DrawRight(RenderWindow & window)
	{
		_line.setSize(Vector2f((CELL_LENGTH / 2), CONNECTION_SIZE));
		window.draw(_line);
	}

	void DrawDown(RenderWindow & window)
	{
		_line.setSize(Vector2f(CONNECTION_SIZE, (CELL_LENGTH / 2)));
		window.draw(_line);
	}

	void DrawLeft(RenderWindow & window)
	{
		_line.setSize(Vector2f(-(CELL_LENGTH / 2), CONNECTION_SIZE));
		window.draw(_line);
	}

public:
	Connections_Object() { _objectState = UnLit; }

	virtual void DrawObject(RenderWindow & window) = 0;

	void MoveConnection()
	{
		switch (_itsPosition)
		{
		case Pos1:
			_itsPosition = Pos2;
			break;

		case Pos2:
			if (_connectionType == Straight)
				_itsPosition = Pos1;
			else
				_itsPosition = Pos3;

			break;

		case Pos3:
			_itsPosition = Pos4;
			break;

		case Pos4:
			_itsPosition = Pos1;
			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
			break;
		}
	}

	void DrawLitOrUnlit()
	{
		if (_objectState == Lit)
		{
			
			_line.setFillColor(Color::Yellow);
		}
		else
		{
			_line.setFillColor(Color::Blue);
		}
		_line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY()));
	}

	void CalculateRefPoint()
	{
		_ref_Coord.SetX((_d_Coord.GetX() + _b_Coord.GetX()) / 2);
		_ref_Coord.SetY((_a_Coord.GetY() + _c_Coord.GetY()) / 2);
	}

	void SetConnectionPosition(int inPos)
	{
		switch (inPos)
		{
		case 1:
			_itsPosition = Pos1;
			break;
		case 2:
			_itsPosition = Pos2;
			break;
		case 3:
			_itsPosition = Pos3;
			break;
		case 4:
			_itsPosition = Pos4;
			break;
		default:
			cout << "InValid ConnectionPosition" << endl;
		}
	}

	void SetSolvedConnectionPosition(int inPos)
	{
		switch (inPos)
		{
		case 1:
			_solvedPosition = Pos1;
			break;
		case 2:
			_solvedPosition = Pos2;
			break;
		case 3:
			_solvedPosition = Pos3;
			break;
		case 4:
			_solvedPosition = Pos4;
			break;
		default:
			cout << "InValid ConnectionPosition" << endl;
		}
	}

	void Set_a_Coord(int x, int y)
	{
		_a_Coord.SetX(x);
		_a_Coord.SetY(y);
	}

	void Set_b_Coord(int x, int y)
	{
		_b_Coord.SetX(x);
		_b_Coord.SetY(y);
	}

	void Set_c_Coord(int x, int y)
	{
		_c_Coord.SetX(x);
		_c_Coord.SetY(y);
	}

	void Set_d_Coord(int x, int y)
	{
		_d_Coord.SetX(x);
		_d_Coord.SetY(y);
	}


	Co_Ordinates GetRefPt()
	{
		return _ref_Coord;
	}
};

//devived types of connection
class L_ShapedConnection : public Connections_Object
{
public:
	void DrawObject(RenderWindow & window) override
	{
		this->DrawLitOrUnlit();

		switch (_itsPosition)
		{
		case Pos1:
			this->DrawUp(window);
			this->DrawRight(window);
			break;

		case Pos2:
			this->DrawRight(window);
			this->DrawDown(window);
			break;

		case Pos3:
			this->DrawLeft(window);
			this->DrawDown(window);
			break;

		case Pos4:
			this->DrawLeft(window);

			//b/c of a error in drawing it is hard coded
			_line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY() + 8));
			_line.setSize(Vector2f(CONNECTION_SIZE, -(CELL_LENGTH / 2 + 8)));

			window.draw(_line);
			
			//this->DrawUp(window);
			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
		}
	}
};

class T_ShapedConnection : public Connections_Object
{
public:
	void DrawObject(RenderWindow & window) override
	{
		this->DrawLitOrUnlit();

		switch (_itsPosition)
		{
		case Pos1:
			this->DrawLeft(window);
			this->DrawRight(window);
			this->DrawDown(window);
			break;

		case Pos2:
			this->DrawUp(window);
			this->DrawDown(window);
			this->DrawLeft(window);
			break;

		case Pos3:
			this->DrawUp(window);
			this->DrawLeft(window);
			this->DrawRight(window);
			break;

		case Pos4:
			this->DrawDown(window);
			this->DrawUp(window);
			this->DrawRight(window);
			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
		}
	}
};

class StraightConnection : public Connections_Object
{
public:
	void DrawObject(RenderWindow & window) override
	{
		this->DrawLitOrUnlit();

		switch (_itsPosition)
		{
		case Pos1:
			this->DrawLeft(window);
			this->DrawRight(window);
			break;

		case Pos2:
			this->DrawUp(window);
			this->DrawDown(window);
			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
		}
	}
};

class MiniConnection : public Connections_Object
{
public:
	void DrawObject(RenderWindow & window) override
	{
		this->DrawLitOrUnlit();

		switch (_itsPosition)
		{
		case Pos1:
			this->DrawUp(window);
			break;

		case Pos2:
			this->DrawRight(window);
			break;

		case Pos3:
			this->DrawDown(window);
			break;

		case Pos4:
			this->DrawLeft(window);
			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
		}
	}
};
