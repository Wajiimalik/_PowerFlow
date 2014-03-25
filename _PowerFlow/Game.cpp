#include "Game.h"

Game::Game(RenderWindow & window) : _window(window) {}

bool Game::Run()
{
	//Initialize();

	//LoadContent();
	int levelNo = 1;
	//Board gameBoard(levelNo);

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

		_window.display();
	}
	
	return true;
}

void Game::LoadContent() {}

void Game::UnloadContent() {}

void Game::Draw(RenderWindow & window) {}