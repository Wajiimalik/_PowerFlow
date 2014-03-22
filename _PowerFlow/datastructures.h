#ifndef DATASTRUCTURE_H
#define	DATASTRUCTURE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

#define ROW 5
#define COL 5

#define CELL_LENGTH 120

enum ObjectType { Factory, House, Connection };
enum ConnectionType { L_Shaped, T_Shaped, Straight, Mini};
enum ConnectionPosition { Pos1, Pos2, Pos3, Pos4 };
enum ObjectState { Lit, UnLit };
enum GameState { Selection, Level1, Level2, Win };
enum PuzzleState { Solved, UnSolved };


typedef ObjectType ObjectType;
typedef ConnectionType ConnectionType;
typedef ObjectState ObjectState;
typedef GameState GameState;
typedef PuzzleState PuzzleState;

/*
bool StartGame(RenderWindow & window)
{
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear(Color::Black);

		RectangleShape rectangle( Vector2f(120, 120) );
		rectangle.setFillColor( Color::Black );
		rectangle.setOutlineThickness( 1.f );
		rectangle.setOutlineColor( Color::White );

		for (int i = 50; i <= 530; i += 120)
		{
			for (int j = 50; j <= 530; j += 120)
			{
				rectangle.setPosition( i, j );
				window.draw( rectangle );
			}
		}

		window.display();
	}
	return true;
}
*/

//for moves 
class Co_Ordinates
{
private:
	int _x;
	int _y;

public:
	Co_Ordinates() : _x(0), _y(0) {}

	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }

	int GetX() { return _x;  }
	int GetY() { return _y;  }

	Co_Ordinates(Co_Ordinates & c)
	{
		_x = c._x;
		_y = c._y;
	}

	bool operator == (Co_Ordinates c)
	{ 
		if (_x == c._x && _y == c._y)
		{
			return true;
		}
		return false;
	}
};

#endif	/* DATASTRUCTURE_H */

