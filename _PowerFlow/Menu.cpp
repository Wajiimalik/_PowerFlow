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

void Menu :: Display_StartScreen()
{
	_window.draw(_Start);
}

void Menu :: Display_MenuScreen()
{
	_window.draw(_Menu);
}

void Menu :: Display_LevelScreen()
{
	_window.draw(_Level);
}

void Menu :: Display_InstructionsScreen()
{
	_window.draw(_Instructions);
}

void Menu :: Display_AboutScreen()
{
	_window.draw(_About);
}

void Menu::DrawMenu()
{
	switch (_menuMode)
	{
	case Start:
		Display_MenuScreen();
		_window.display();
		return;
		break;

	case MenuOptions:
		Display_MenuScreen();
		_window.display();
		return;
		break;

	case Level:
		Display_LevelScreen();
		_window.display();
		return;
		break;

	case Instructions:
		Display_InstructionsScreen(); 
		_window.display();
		return;
		break;

	case About:
		Display_AboutScreen();
		_window.display();
		return;
		break;

	default:
		cout << endl << "Invalid Menu mode!" << endl;
		return;
		break;
	}
}

MenuMode Menu :: GetMenuMode()
{
	return _menuMode;
}