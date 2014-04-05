#include "Game.h"

Game::Game(RenderWindow & window) 
	: _window(window), _levelNo(1), _gameState(Selection), _mouseX(0), _mouseY(0) {}


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
					_board->Cells[i]._ptrConnection->MoveConnection();
					//_board->Cells[i].DrawCell(_window);
					Draw();
					GameOver();
					break;
				}
			}

			if (_gameState == Win)
			{
				cout << "GAME OVER! ";
				CircleShape c(100);
				_window.draw(c);
				_window.display();
				break;
			}
		}
	}
	
	return true;
}

void Game::Initialize() 
{
	LoadContent();
	_board = new Board(_levelNo);
	for (int i = 0; i < ROW*COL; i++)
	{
		if (_board->Cells[i]._objectType == Factory)
			_board->Cells[i]._ptrObjects->SetTexture(factory);

		if (_board->Cells[i]._objectType == House)
			_board->Cells[i]._ptrObjects->SetTexture(house);
	}
	
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

bool Game ::GameOver()
{
	int count = 0;
	
	for (int i = 0; i < ROW * COL; i++)
	{
		if (_board->Cells[i]._ptrConnection->_itsPosition != _board->Cells[i]._ptrConnection->_solvedPosition)
		{
			count++;
		}
	}
		if (count == 0)
		{
			UnloadContent();
			_gameState = Win;
			return true;
		}
		return false;
}

void Game :: LoadContent()
{
	factory.loadFromFile("Pic\\Factory.png");

	house.loadFromFile("Pic\\House.png");
}

void Game::UnloadContent()
{
	delete _board;
}