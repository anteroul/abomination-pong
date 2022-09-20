//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAENGINE_GAME_H
#define SIGMAENGINE_GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen, bool twoPlayerMode);
	void update();
	void render();
	void clean();
	void handleEvents();
	bool windowShouldClose{};
private:
	SDL_Window *window{};
	SDL_Renderer *renderer{};
};


#endif //SIGMAENGINE_GAME_H
