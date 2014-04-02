#include "Game.h"

Game::Game(RenderWindow & window) : _window(window), _levelNo(1), _gameState(Selection), _mouseX(0), _mouseY(0) {}

bool Game::Run()
{
	Initialize();
	Draw();

	while (_window.isOpen())
	{
		if (ProcessEvents() == true)
		{
			int i;
			for (i = 0; i < ROW*COL; i++)
			{
				if (_board->Cells[i].GetClickedCell(_mouseX, _mouseY))
				{
					_board->Cells[i]._ptrConnection->MoveObject();
					break;
				}
			}
			Draw();
		}
	}
	
	return true;
}



void Game::Initialize() 
{
	_board = new Board(_levelNo);
}



void Game :: Draw()
{
	_board->DrawBoard(_window);
}



bool Game :: ProcessEvents()
{
	Event event;

	while (_window.pollEvent(event))
	{
		//if window is closed "X"
		if (event.type == Event :: Closed)
		{
			UnloadContent();
			_window.close();
		}

		//if user has clicked on board
		if (event.type == Event :: MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse :: Left)
			{
				_mouseX = event.mouseButton.x;
				_mouseY = event.mouseButton.y;
				
				if (_mouseX > 50 && _mouseX < (50 + (120 * 5)) && _mouseY > 50 && _mouseY < (50 + (120 * 5)))
				{
					return true;
				}
				else return false;
			}
		}
	}
	return false;
}



void Game::UnloadContent()
{
	delete _board;
}