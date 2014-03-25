/*
#include "Objects.h"
#include "Cell.h"

Objects :: Objects() { _objectState = UnLit; }

void Objects :: SetLit() { _objectState = Lit; }
void Objects :: SetUnLit() { _objectState = UnLit; }

///=========================================================///

void Factory_Object :: DrawObject()
{
	cout << "Darwing Factory" << endl;
}

///=========================================================///

void House_Object:: DrawObject() 
{
	cout << "Darwing House" << endl;
}

///=======================================================///

void Connections_Object :: CalculateRefPoint()
{
	_ref_Coord.SetX((_d_Coord.GetX() + _b_Coord.GetX()) / 2);
	_ref_Coord.SetY((_a_Coord.GetY() + _c_Coord.GetY()) / 2);
}

void Connections_Object :: DrawUp()
{
	line.setSize(Vector2f(6, -(120 / 2)));
	line.setFillColor(Color::Blue);
	line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY()));
	///////window.draw(line);
}

void Connections_Object :: DrawRight()
{
	line.setSize(Vector2f((120 / 2), 6));
	line.setFillColor(Color::Blue);
	line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY()));
	////////////window.draw(line);
}

void Connections_Object :: DrawDown()
{
	line.setSize(Vector2f(6, (120 / 2)));
	line.setFillColor(Color::Blue);
	line.setPosition(float(_ref_Coord.GetX()), float(_ref_Coord.GetY()));
	///////////window.draw(line);
}

void Connections_Object :: DrawLeft()
{
	line.setSize(Vector2f(-(120 / 2), 6));
	line.setFillColor(Color::Blue);
	line.setPosition(float(_ref_Coord.GetX()),float( _ref_Coord.GetY()));
	//////////window.draw(line);
}

void Connections_Object :: SetConnectionsPosition(ConnectionPosition c)
{
	_itsPosition = c;
}

void Connections_Object :: Set_a_Coord(int x, int y)
{
	_a_Coord.SetX(x);
	_a_Coord.SetY(y);
}

void Connections_Object :: Set_b_Coord(int x, int y)
{
	_b_Coord.SetX(x);
	_b_Coord.SetY(y);
}
void Connections_Object :: Set_c_Coord(int x, int y)
{
	_c_Coord.SetX(x);
	_c_Coord.SetY(y);
}
void Connections_Object :: Set_d_Coord(int x, int y)
{
	_d_Coord.SetX(x);
	_d_Coord.SetY(y);
}

Co_Ordinates Connections_Object :: GetRefPt()
{
	return _ref_Coord;
}

///===========================================================///

void L_ShapedConnection :: MoveObject() {}
void L_ShapedConnection :: DrawObject()
{

	cout << "Darwing L_ShapedConnection" << endl;
	switch (_itsPosition)
	{
	case Pos1:
		this->DrawUp();
		this->DrawRight();
		break;

	case Pos2:
		this->DrawRight();
		this->DrawDown();
		break;

	case Pos3:
		this->DrawLeft();
		this->DrawDown();
		break;

	case Pos4:
		this->DrawUp();
		this->DrawLeft();
		break;

	default:
		cout << endl << "Invalid Connection Position" << endl;
	}
}

///===============================================================///


void T_ShapedConnection::MoveObject() {}

void T_ShapedConnection :: DrawObject()
{
	cout << "Darwing T_ShapedConnection" << endl;
	switch (_itsPosition)
	{
	case Pos1:
		this->DrawLeft();
		this->DrawRight();
		this->DrawDown();
		break;

	case Pos2:
		this->DrawUp();
		this->DrawDown();
		this->DrawLeft();
		break;

	case Pos3:
		this->DrawUp();
		this->DrawLeft();
		this->DrawRight();
		break;

	case Pos4:
		this->DrawDown();
		this->DrawUp();
		this->DrawRight();
		break;

	default:
		cout << endl << "Invalid Connection Position" << endl;
	}
}

///=================================================================///

void StraightConnection :: MoveObject() {}
void StraightConnection :: DrawObject()
{
	cout << "Darwing Straight Connection" << endl;
	switch (_itsPosition)
	{
	case Pos1:
		this->DrawLeft();
		this->DrawRight();
		break;

	case Pos2:
		this->DrawUp();
		this->DrawDown();
		break;
	default:
		cout << endl << "Invalid Connection Position" << endl;
	}
}

///==================================================================///

void MiniConnection :: MoveObject() {}
void MiniConnection :: DrawObject()
{
	cout << "Darwing Mini Connection" << endl;
	switch (_itsPosition)
	{
	case Pos1:
		this->DrawUp();
		break;

	case Pos2:
		this->DrawRight();
		break;

	case Pos3:
		this->DrawDown();
		break;

	case Pos4:
		this->DrawLeft();
		break;

	default:
		cout << endl << "Invalid Connection Position" << endl;
	}
}
*/