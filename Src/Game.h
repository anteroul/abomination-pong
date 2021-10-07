//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAENGINE_GAME_H
#define SIGMAENGINE_GAME_H
#include "SDL.h"
#include "SDL_image.h"

class Game {
public:
    Game();
    ~Game();
    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    void handleEvents();
    bool windowShouldClose{};
private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
};


#endif //SIGMAENGINE_GAME_H
