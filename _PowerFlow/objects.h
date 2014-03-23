#ifndef OBJECTS_H
#define OBJECTS_H


#include "datastructures.h"

//abstract class for all objects
class Objects
{
protected:
	ObjectState _objectState;

public:
	//Constructor initialize with unLit as at the start only one connection would be Lit
	Objects() { _objectState = UnLit; }

	virtual void DrawObject() = 0;

	void SetLit() { _objectState = Lit; }
	void SetUnLit() { _objectState = UnLit; }
};


//Factory Object
class Factory_Object : public Objects
{
private:

public:
	void DrawObject() override
	{
		cout << "Darwing Factory" << endl;
	}

	~Factory_Object() {}
};


//House Object
class House_Object : public Objects
{
private:
public:
	void DrawObject() override
	{
		cout << "Darwing House" << endl;
	}
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
	RectangleShape line;


public:
	virtual void MoveObject() = 0;

	void CalculateRefPoint()
	{
		_ref_Coord.SetX((_d_Coord.GetX() + _b_Coord.GetX()) / 2);
		_ref_Coord.SetY((_a_Coord.GetY() + _c_Coord.GetY()) / 2);
	}

	void DrawUp()
	{
		line.setSize(Vector2f(6, -(120 / 2 + 1)));
		line.setFillColor(Color::Blue);
		line.setPosition(_ref_Coord.GetX(), _ref_Coord.GetY());
		window.draw(line);
	}

	void DrawRight()
	{
		line.setSize(Vector2f((120 / 2 + 1), 6));
		line.setFillColor(Color::Blue);
		line.setPosition(_ref_Coord.GetX(), _ref_Coord.GetY());
		window.draw(line);
	}

	void DrawDown()
	{
		line.setSize(Vector2f(6, (120 / 2 + 1)));
		line.setFillColor(Color::Blue);
		line.setPosition(_ref_Coord.GetX(), _ref_Coord.GetY());
		window.draw(line);
	}

	void DrawLeft()
	{
		line.setSize(Vector2f(-(120 / 2 + 1), 6));
		line.setFillColor(Color::Blue);
		line.setPosition(_ref_Coord.GetX(), _ref_Coord.GetY());
		window.draw(line);
	}

	void SetConnectionPosition(ConnectionPosition c)
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
	void MoveObject() override {}
	void DrawObject() override
	{
		cout << "Darwing L_ShapedConnection" << endl;
	}
};

class T_ShapedConnection : public Connections_Object
{
private:
public:
	void MoveObject() override {}
	void DrawObject() override
	{
		cout << "Darwing T_ShapedConnection" << endl;
	}
};

class StraightConnection : public Connections_Object
{

private:
public:
	void MoveObject() override {}
	void DrawObject() override
	{
		cout << "Darwing Straight Connection" << endl;
	}
};

class MiniConnection : public Connections_Object
{
private:
public:
	void MoveObject() override {}
	void DrawObject() override
	{
		cout << "Darwing Mini Connection" << endl;
	}
};

#endif /* OBJECTS_H */