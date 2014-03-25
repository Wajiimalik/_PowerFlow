#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "DataBase.h"
#include "Board.h"
#include "Cell.h"
#include "Objects.h"


class Game
{
public:
public:
	Game(RenderWindow & window);
	
	Board * _board;

	bool Run();

	RenderWindow & _window;


private:
	//level no would be assigned to this "_levelNo" from menu object
	int _levelNo;

	void Initialize();

	void UnloadContent();

	void Draw(RenderWindow & window);
};

#endif /* GAME_H */