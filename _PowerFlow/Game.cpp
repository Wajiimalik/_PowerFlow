#include "Game.h"

Game::Game(RenderWindow & window) : _window(window), _levelNo(1) {}

bool Game::Run()
{
	Initialize();
	Draw();

	while (_window.isOpen())
	{
		Event event;

		while (_window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				_window.close();
			}
		}
		_window.clear(Color::Black);
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

void Game::UnloadContent() {}