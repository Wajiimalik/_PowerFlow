#pragma once
//#ifndef OBJECTS_H
//#define OBJECTS_H

//#include "DataBase.h"

#include "Cell.h"

//abstract class for all objects
class Objects
{
protected:
	Co_Ordinates _ref_Coord;

public:
	ObjectState _objectState;

	//Constructor initialize with unLit as at the start only one connection would be Lit
	Objects() { _objectState = UnLit; }

	void SetRefCoord(Co_Ordinates c)
	{
		_ref_Coord = c;
	}

	virtual void DrawObject(RenderWindow & window) = 0;
};


//Factory Object
class Factory_Object : public Objects
{
private:

public:
	void DrawObject(RenderWindow & window) override
	{
		//FOR FAHAD
	}

	~Factory_Object() {}
};


//House Object
class House_Object : public Objects
{
private:
public:
	void DrawObject(RenderWindow & window) override
	{
		//FOR FAHAD
	}

	~House_Object() {}
};



//Connections Object (abstract class)
class Connections_Object : public Objects
{
protected:
	ConnectionPosition _itsPosition;
	ConnectionPosition _solvedPosition;

	Co_Ordinates _a_Coord;
	Co_Ordinates _b_Coord;
	Co_Ordinates _c_Coord;
	Co_Ordinates _d_Coord;


	RectangleShape _line;	//for drawing
	

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
	virtual void DrawObject(RenderWindow & window) = 0;

	void MoveObject()
	{
		switch (_itsPosition)
		{
		case Pos1:
			_itsPosition = Pos2;
			break;

		case Pos2:
			_itsPosition = Pos3;
			break;

		case Pos3:
			_itsPosition = Pos4;
			break;

		case Pos4:
			_itsPosition = Pos1;
			break;

		default:
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

	void SetConnectionsPosition(ConnectionPosition c)
	{
		_itsPosition = c;
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
private:
	//for moves
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
			_line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY() + 6));
			_line.setSize(Vector2f(CONNECTION_SIZE, -(CELL_LENGTH / 2 + 6)));
			window.draw(_line);

			break;

		default:
			cout << endl << "Invalid Connection Position" << endl;
		}
	}
};

class T_ShapedConnection : public Connections_Object
{
private:
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

private:
public:
	void DrawObject(RenderWindow & window) override
	{
		this->DrawLitOrUnlit();
		switch (_itsPosition)
		{
		case Pos1:
		case Pos3:
			this->DrawLeft(window);
			this->DrawRight(window);
			break;

		case Pos2:
		case Pos4:
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
private:
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

/*
class Objects
{
protected:
ObjectState _objectState;

public:
Objects();
virtual void DrawObject() = 0;
void SetLit();
void SetUnLit();
};

//Factory Object
class Factory_Object : public Objects
{
void DrawObject() override;

~Factory_Object() {}
};

//House Object
class House_Object : public Objects
{
public:
void DrawObject() override;
~House_Object() {}
};


//Connections Object (abstract class)
class Connections_Object : public Objects
{
protected:
ConnectionPosition _itsPosition;
Co_Ordinates _a_Coord;
Co_Ordinates _b_Coord;
Co_Ordinates _c_Coord;
Co_Ordinates _d_Coord;
Co_Ordinates _ref_Coord;
RectangleShape line;	//for drawing

public:
virtual void MoveObject() = 0;
void CalculateRefPoint();
void DrawUp();
void DrawRight();
void DrawDown();
void DrawLeft();
void SetConnectionsPosition(ConnectionPosition c);
void Set_a_Coord(int x, int y);
void Set_b_Coord(int x, int y);
void Set_c_Coord(int x, int y);
void Set_d_Coord(int x, int y);
Co_Ordinates GetRefPt();

};

//devived types of connection
class L_ShapedConnection : public Connections_Object
{
public:
void MoveObject() override;
void DrawObject() override;
};

class T_ShapedConnection : public Connections_Object
{
public:
void MoveObject() override;
void DrawObject() override;
};

class StraightConnection : public Connections_Object
{
public:
void MoveObject() override;
void DrawObject() override;
};

class MiniConnection : public Connections_Object
{
public:
void MoveObject() override;
void DrawObject() override;
};

//#endif //
*/
