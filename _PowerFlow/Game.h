#pragma once

#include <iostream>
#include <string>

#include "DataBase.h"
#include "Menu.h"
#include "Board.h"
#include "Cell.h"
#include "Objects.h"


class Game
{
public:
	Game(RenderWindow & window);
	bool Run();

	RenderWindow & _window;

	void GiveGameToGame(Game * h)
	{
		_game = h;
	}

	
	~Game() {}
private:
	//level no. would be assigned to this "_levelNo" from menu object
	Menu * _menu;
	Board * _board;
	int _levelNo;
	Game * _game;

	GameState _gameState;

	Texture factory;
	Texture house;
	Texture houseUnLit;

	Texture start;
	Texture menu;
	Texture instructions;
	Texture about;
	Texture level;

	Texture transition1;
	Texture transition2;
	Texture transition3;
	Texture transition4;

	Texture level1;
	Texture level2;
	Texture level3;
	Texture level4;
	Texture level5;

	Sprite Transition1;
	Sprite Transition2;
	Sprite Transition3;
	Sprite Transition4;

	Texture gameOver;
	Sprite _GameOver;

	int _mouseX;
	int _mouseY;

	void PlayGame();
	void Initialize();

	void LitDraw();
	bool ProcessEvents();

	void ChangeLevelNo();
	bool GameOver();

	void LoadContent();
	void UnloadContent();
};
