
#include "Game.h"

int main()
{
	RenderWindow window(VideoMode(900, 700), "POWER FLOW", Style::Titlebar);

	window.setFramerateLimit(30);
	Game *game = new Game(window);
	game->GiveGameToGame(game);
	game->Run();
	
	return 0;
}