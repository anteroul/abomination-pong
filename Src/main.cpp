#include "SDL2/SDL.h"
#include "Game.h"

#define FPS 60

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	unsigned int frameTime;

	game = new Game();

	game->init("Pong", 400, 200, 1280, 720, false, true);

	// Game loop:
	while (!game->windowShouldClose)
	{
		frameStart = SDL_GetTicks();

		game->update();
		game->handleEvents();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);

	}

	// Clean up
	game->clean();
	delete game;
	SDL_Quit();
	return 0;
}