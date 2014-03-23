
#include "datastructures.h"
#include "board.h"


int main()
{
	int levelNo = 1;
	Board gameBoard(levelNo);

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

		//gameBoard.DrawBoard();
	}

	//window.display();
	return 0;
}