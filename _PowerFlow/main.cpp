#include <iostream>
//#include <string>

//#include <SFML/Graphics.hpp>
#include "datastructures.h"
#include "board.h"

using namespace sf;
using namespace std;

int main()
{
	int levelNo = 1;
	Board gameBoard(levelNo);
	
	RenderWindow window(VideoMode(900, 700), "POWER FLOW");
	//StartGame(window);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear(Color::Black);

		gameBoard.DrawBoard(window);
	}
	
	window.display();
	return 0;
}