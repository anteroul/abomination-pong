// v0.0.1.5

#include "SDL.h"
#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {

    game = new Game();

    game->init("Sigma Engine", 0, 0, 1280, 720, false);

    while (!game->windowShouldClose)
    {
        game->update();
        game->handleEvents();
    }

    // Clean up
    game->clean();
    SDL_Quit();
    return 0;
}