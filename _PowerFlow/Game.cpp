#include "Game.h"

Game::Game(RenderWindow & window) 
: _window(window), _levelNo(1), _gameState(Selection), _mouseX(0), _mouseY(0) 
{
	LoadContent(); 

	_menu = new Menu(_window, _gameState);
	_menu->SetTextures(start, menu, level, instructions, about);

	//it will be shown only one time
	_menu->Display_StartScreen();
	_window.display();
}

bool Game::Run()
{
	while (_window.isOpen())
	{
		switch (_gameState)
		{
		case Selection:
			ProcessEvents();
			break;

		case Playing:
			if (ProcessEvents() == true)
			{
				int i;
				for (i = 0; i < ROW*COL; i++)
				{
					if (_board->Cells[i].GetClickedCell(_mouseX, _mouseY))
					{
						_board->Cells[i]._ptrConnection->MoveConnection();
						Draw();
						if (GameOver())
							break;
						break;
					}
				}
				if (_gameState == Win)
					break;
			}
				break;

		case Win:
			cout << "GAME OVER! ";
			_window.display();
			_gameState = Selection;
			_menu->_menuMode = MenuOptions;
			break;

		}
		
	}
	
	return true;
}


void Game::Initialize() 
{
	_board = new Board(_levelNo);
	
	//setting textures of house and factory
	for (int i = 0; i < ROW*COL; i++)
	{
		if (_board->Cells[i]._objectType == Factory)
			_board->Cells[i]._ptrObjects->SetTexture(factory, factory);

		if (_board->Cells[i]._objectType == House)
			_board->Cells[i]._ptrObjects->SetTexture(house, houseUnLit);
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
		if (_menu->_menuMode == MenuOptions)
			_menu->DrawMenu();

		//if window is closed "X"
		if (event.type == Event::Closed)
		{
			UnloadContent();
			_window.close();
		}


		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				_mouseX = event.mouseButton.x;
				_mouseY = event.mouseButton.y;


				switch (_gameState)
				{
				case Selection:
					
					switch (_menu->_menuMode)
					{
					case Start:
						_menu->DrawMenu();
						_menu->_menuMode = MenuOptions;
						break;

					case MenuOptions:
						_menu->DrawMenu();
						//LEVEL
						if (_mouseX > 132 && _mouseX < 446 + 132 && _mouseY > 222 && _mouseY < 230 + 222)
						{
							_menu->_menuMode = Level;
							_menu->DrawMenu();
							//break;
						}

						//INSTRUCTIONS
						if (_mouseX > 597 && _mouseX < 154 + 597 && _mouseY > 219 && _mouseY < 234 + 219)
						{
							_menu->_menuMode = Instructions;
							_menu->DrawMenu();
							//break;
						}

						//ABOUT
						if (_mouseX > 132 && _mouseX < 338 + 132 && _mouseY > 469 && _mouseY < 141 + 469)
						{
							_menu->_menuMode = About;
							_menu->DrawMenu();
							//break;
						}

						//EXIT
						if (_mouseX > 489 && _mouseX < 264 + 489 && _mouseY > 469 && _mouseY < 143 + 469)
						{
							//UnloadContent();
							_window.close();
							exit(1);
						}
						break;

					case Level:
						//LEVEL1
						if (_mouseX > 313 && _mouseX < 313 + 260 && _mouseY > 195 && _mouseY < 195 + 60)
						{
							_gameState = Playing;
							Initialize();
							_window.clear();
							Draw();
							Run();
						}

						//LEVEL2
						if (_mouseX > 313 && _mouseX < 313 + 264 && _mouseY > 289 && _mouseY < 289 + 60)
						{
							_gameState = Playing;
							Initialize();
							_window.clear();
							Draw();
							Run();
						}

						//LEVEL3
						if (_mouseX > 313 && _mouseX < 313 + 270 && _mouseY > 383 && _mouseY < 383 + 60)
						{
							_gameState = Playing;
							Initialize();
							_window.clear();
							Draw();
							Run();
						}

						//LEVEL4
						if (_mouseX > 313 && _mouseX < 313 + 274 && _mouseY > 477 && _mouseY < 477 + 60)
						{
							_gameState = Playing;
							Initialize();
							_window.clear();
							Draw();
							Run();
						}

						//LEVEL5
						if (_mouseX > 313 && _mouseX < 313 + 274 && _mouseY > 571 && _mouseY < 571 + 60)
						{
							_gameState = Playing;
							Initialize();
							_window.clear();
							Draw();
							Run();
						}


					case Instructions:
					case About:
						if (_mouseX > 25 && _mouseX < 25 + 140 && _mouseY > 620 && _mouseY < 620 + 50)
						{
							_menu->_menuMode = MenuOptions;
							_menu->DrawMenu();
						}
						break;
					}
					break;


				case Playing:
					if (_mouseX > 50 && _mouseX < (50 + (120 * 5)) && _mouseY > 50 && _mouseY < (50 + (120 * 5)))
					{
						return true;
					}
					else return false;

				}
				break;
			}
			//if user has clicked on board

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
	houseUnLit.loadFromFile("Pic\\HouseUnLit.png");

	start.loadFromFile("Pic\\Start.png");
	menu.loadFromFile("Pic\\Menu.png");
	instructions.loadFromFile("Pic\\Instructions.png");
	about.loadFromFile("Pic\\About.png");
	level.loadFromFile("Pic\\Level.png");
}

void Game::UnloadContent()
{
	//delete _board;
}