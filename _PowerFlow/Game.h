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
	RenderWindow & _window;

	bool Run();
};

#endif /* GAME_H */