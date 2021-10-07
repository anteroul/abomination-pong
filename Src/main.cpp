// v0.0.3

#include "SDL.h"
#include "Game.h"
#define FPS 60

Game* game = nullptr;

int main(int argc, char* argv[]) {

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    unsigned int frameTime;

    game = new Game();

    game->init("Sigma Engine", 400, 400, 800, 600, false);

    while (!game->windowShouldClose)
    {
        frameStart = SDL_GetTicks();

        game->update();
        game->handleEvents();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);

    }

    // Clean up
    game->clean();
    SDL_Quit();
    return 0;
}