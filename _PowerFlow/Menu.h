#pragma once

#include "database.h"

class Menu
{
	Sprite _Start;
	Sprite _Menu;
	Sprite _Level;
	Sprite _Instructions;
	Sprite _About;

public:
	GameState & _gameState;
	MenuMode _menuMode;
	RenderWindow & _window;

public:
	Menu(RenderWindow & window, GameState & gameState);
	void SetTextures(Texture & start, Texture & menu, Texture & level, Texture & instructions, Texture & about);
	

	void DrawMenu();
};