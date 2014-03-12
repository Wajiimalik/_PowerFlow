#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <iostream>

using namespace std;

//abstract class for all objects
class Objects
{
protected:
	ObjectState _objectState;
public:
	Objects() { _objectState = UnLit; }
	virtual void DrawObject() = 0;
	void SetLit() { _objectState = Lit; }
	void SetUnLit() { _objectState = UnLit; }
};

//Factory Object
class Factory_Object: public Objects
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
	ConnectionPosition _connectioNPosition;
	Co_Ordinates _coordA;
	Co_Ordinates _coordB;
	Co_Ordinates _coordC;
public:
	virtual void MoveObject() = 0;
	Co_Ordinates GetCoordAOfConnection() { return _coordA; }
	Co_Ordinates GetCoordBOfConnection() { return _coordB; }
	Co_Ordinates GetCoordCOfConnection() { return _coordC; }
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