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

	bool Run();

	RenderWindow & _window;


private:
	void LoadContent();

	void UnloadContent();

	void Draw(RenderWindow & window);
};

#endif /* GAME_H */