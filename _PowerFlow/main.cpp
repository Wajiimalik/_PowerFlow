
#include "Game.h"

int main()
{
	
	RenderWindow window(VideoMode(900, 700), "POWER FLOW");

	Game *game = new Game(window);
	game->Run();
	
	return 0;
}