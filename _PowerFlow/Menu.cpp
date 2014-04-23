#include "Menu.h"


Menu::Menu(RenderWindow & window, GameState & gameState) : 
_window(window), _gameState(gameState), _menuMode(Start)
{
}

void Menu::SetTextures(Texture & start, Texture & menu, Texture & level, Texture & instructions, Texture & about)
{
	_Start.setTexture(start);
	_Menu.setTexture(menu);
	_Instructions.setTexture(instructions);
	_About.setTexture(about);
	_Level.setTexture(level);
}

void Menu::DrawMenu()
{
	switch (_menuMode)
	{
	case Start:
		_window.draw(_Start);
		_window.display();
		return;
		break;

	case MenuOptions:
		_window.draw(_Menu);
		_window.display();
		return;
		break;

	case Level:
		_window.draw(_Level);
		_window.display();
		return;
		break;

	case Instructions:
		_window.draw(_Instructions);
		_window.display();
		return;
		break;

	case About:
		_window.draw(_About);
		_window.display();
		return;
		break;

	default:
		cout << endl << "Invalid Menu mode!" << endl;
		return;
		break;
	}
}