#pragma once

#include <iostream>
#include <string>

#include "DataBase.h"
#include "Board.h"
#include "Cell.h"
#include "Objects.h"


class Game
{
public:
	Game(RenderWindow & window);
	bool Run();

	RenderWindow & _window;

private:
	//level no would be assigned to this "_levelNo" from menu object
	Board * _board;
	int _levelNo;

	GameState _gameState;

	Texture factory;
	Texture house;

	int _mouseX;
	int _mouseY;

	void Initialize();
	void Draw();
	bool ProcessEvents();

	bool GameOver();

	void LoadContent();
	void UnloadContent();
};
