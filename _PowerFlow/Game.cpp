#include "Game.h"

Game::Game(RenderWindow & window) 
: _window(window), _levelNo(1), _gameState(Selection), _mouseX(0), _mouseY(0) 
{
	LoadContent(); 

	_menu = new Menu(_window, _gameState);
	_menu->SetTextures(start, menu, level, instructions, about);

	//it will be shown once at the start of game so it is in game constructor
	_menu->DrawMenu();
	//_window.display();
}

bool Game::Run()
{
	while (_window.isOpen())
	{
		switch (_gameState)
		{
		case Selection:
			_window.clear(Color::Black);
			ProcessEvents();
			break;

		case Playing:
			_window.clear(Color::Black);
			_board->DrawLevelbar(_window);

			if (ProcessEvents() == true)	//returns true only if gameState is in Playing mode
			{
				int i;
				for (i = 0; i < ROW*COL; i++)
				{
					if (_board->Cells[i].GetClickedCell(_mouseX, _mouseY))
					{
						_board->Cells[i]._ptrConnection->MoveConnection();
						_board->DrawBoard(_window);

						if (GameOver()) //break from for loop
							break;

						break;
					}
				}

				if (_gameState == Win)	//break case and restart switch loop
					break;
			}

			break; //break from case without any condition

		case Transition:
			_window.clear(Color::Black);
			ProcessEvents();
			break;

		case Win:
			ProcessEvents();
			break;
		}
	}
	return true;
}

void Game ::  PlayGame()
{
	_gameState = Playing;
	Initialize(); //Initilize all data from file 
	//_window.clear();
	//_board->DrawLevelbar(_window);
	_board->DrawBoard(_window);
	Run();	//again run in Playing mode
}

void Game::Initialize() 
{
	_board = new Board(_levelNo);
	_board->SetTexture(level1, level2, level3, level4, level5);

	//setting textures of house and factory
	for (int i = 0; i < ROW*COL; i++)
	{
		if (_board->Cells[i]._objectType == Factory)
			_board->Cells[i]._ptrObjects->SetTexture(factory, factory);

		if (_board->Cells[i]._objectType == House)
			_board->Cells[i]._ptrObjects->SetTexture(house, houseUnLit);
	} 

	_board->DrawLevelbar(_window);
}

void Game::LitDraw()
{
	for (int i = 0; i < ROW*COL; i++)
	{
		_board->Cells[i]._cellState = Lit;
	}
	_board->DrawBoard(_window);
	_window.display();
}

bool Game :: ProcessEvents()
{
	Event event;

	while (_window.pollEvent(event))
	{
		if (_menu->_menuMode == MenuOptions)	
			_menu->DrawMenu();


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
						//_menu->DrawMenu();
						_menu->_menuMode = MenuOptions;
						break;

					case MenuOptions:
						_menu->DrawMenu();	//It has 4 options

						//LEVEL
						if (_mouseX > 132 && _mouseX < 446 + 132 && _mouseY > 222 && _mouseY < 230 + 222)
						{
							_menu->_menuMode = Level;
							_menu->DrawMenu();
						}

						//INSTRUCTIONS
						if (_mouseX > 597 && _mouseX < 154 + 597 && _mouseY > 219 && _mouseY < 234 + 219)
						{
							_menu->_menuMode = Instructions;
							_menu->DrawMenu();
						}

						//ABOUT
						if (_mouseX > 132 && _mouseX < 338 + 132 && _mouseY > 469 && _mouseY < 141 + 469)
						{
							_menu->_menuMode = About;
							_menu->DrawMenu();
						}

						//EXIT
						if (_mouseX > 489 && _mouseX < 264 + 489 && _mouseY > 469 && _mouseY < 143 + 469)
						{
							_window.close();
							exit(1);
						}
						break;	//case break

					case Level:	
						//there are total  5 levels/options that a user can select
						//LEVEL1
						if (_mouseX > 313 && _mouseX < 313 + 260 && _mouseY > 195 && _mouseY < 195 + 60)
						{
							_levelNo = 1;
							PlayGame();
						}

						//LEVEL2
						if (_mouseX > 313 && _mouseX < 313 + 264 && _mouseY > 289 && _mouseY < 289 + 60)
						{
							_levelNo = 2;
							PlayGame();
						}

						//LEVEL3
						if (_mouseX > 313 && _mouseX < 313 + 270 && _mouseY > 383 && _mouseY < 383 + 60)
						{
							_levelNo = 3;
							PlayGame();
						}

						//LEVEL4
						if (_mouseX > 313 && _mouseX < 313 + 274 && _mouseY > 477 && _mouseY < 477 + 60)
						{
							_levelNo = 4;
							PlayGame();
						}

						//LEVEL5
						if (_mouseX > 313 && _mouseX < 313 + 274 && _mouseY > 571 && _mouseY < 571 + 60)
						{
							_levelNo = 5;
							PlayGame();
						}

						//no break here b/c it also has a Back button same like in Instructioins
						//and about windows at same position so same code for these 3

					
					case Instructions:
					case About:
						//back button
						if (_mouseX > 25 && _mouseX < 25 + 140 && _mouseY > 620 && _mouseY < 620 + 50)
						{
							_menu->_menuMode = MenuOptions;
							_menu->DrawMenu();
						}
						break;
					}

				case Playing:
					//If user has clicked OnBoard then return true (:
					if (_mouseX > 50 && _mouseX < (50 + (120 * 5)) && _mouseY > 50 && _mouseY < (50 + (120 * 5)))
					{
						return true;
					}

					//Quit button
					if (_mouseX > 690 && _mouseX < 690 + 170 && _mouseY > 612 && _mouseY < 612 + 50)
					{
						_gameState = Selection;
						_menu->_menuMode = MenuOptions;
						_menu->DrawMenu();

						break;
					}
					else return false;	//if user has clicked on board

				case Transition:
					//if clicked on back button
					if (_mouseX > 25 && _mouseX < 25 + 140 && _mouseY > 620 && _mouseY < 620 + 50)
					{
						_gameState = Selection;
						_menu->_menuMode = MenuOptions;
						_menu->DrawMenu();
					}
					//if clicked on next button
					if (_mouseX > 735  && _mouseX < 735 + 140 && _mouseY > 624 && _mouseY < 624 + 50)
					{
						//_gameState = Playing;
						ChangeLevelNo();
						_window.clear();
						PlayGame();
					}
					break;

				case Win:
					if (_mouseX > 25 && _mouseX < 25 + 140 && _mouseY > 620 && _mouseY < 620 + 50)
					{
						_gameState = Selection;
						_menu->_menuMode = MenuOptions;
						_menu->DrawMenu();
					}
					break;
				}
			}
		}
	}
	return false; //if no event happening then back to while loop of Run() 
}

void Game :: ChangeLevelNo()
{
	switch (_levelNo)
	{
	case 1:
		_levelNo = 2;
		break;

	case 2:
		_levelNo = 3;
		break;

	case 3:
		_levelNo = 4;
		break;

	case 4:
		_levelNo = 5;
		break;
	}
}

bool Game ::GameOver()
{
	int count = 0;
	
	for (int i = 0; i < ROW * COL; i++)
	{	
		//compares solved and unsolved positions of all coonnections after each click in playing mode
		if (_board->Cells[i]._ptrConnection->_itsPosition != _board->Cells[i]._ptrConnection->_solvedPosition)
		{
			count++;
		}
	}

	if (count == 0)
	{
		LitDraw();
		_window.display();
		sleep(seconds(2));

		switch (_levelNo)
		{
		case 1:
			_gameState = Transition;
			_window.draw(Transition1);
			_window.display();
			break;

		case 2:
			_gameState = Transition;
			_window.draw(Transition2);
			_window.display();
			break;

		case 3:
			_gameState = Transition;
			_window.draw(Transition3);
			_window.display();
			break;

		case 4:
			_gameState = Transition;
			_window.draw(Transition4);
			_window.display();
			break;

		case 5:
			_gameState = Win;
			_window.draw(_GameOver);
			_window.display();
			break;
		}

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


	level1.loadFromFile("Pic\\Level1.png");
	level2.loadFromFile("Pic\\Level2.png");
	level3.loadFromFile("Pic\\Level3.png");
	level4.loadFromFile("Pic\\Level4.png");
	level5.loadFromFile("Pic\\Level5.png");


	transition1.loadFromFile("Pic\\Transition1.png");
	Transition1.setTexture(transition1);

	transition2.loadFromFile("Pic\\Transition2.png");
	Transition2.setTexture(transition2);

	transition3.loadFromFile("Pic\\Transition3.png");
	Transition3.setTexture(transition3);

	transition4.loadFromFile("Pic\\Transition4.png");
	Transition4.setTexture(transition4);

	gameOver.loadFromFile("Pic\\GameOver.png");
	_GameOver.setTexture(gameOver);
}
