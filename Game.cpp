//
// Created by valiant on 4.10.2021.
//

#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playerTex;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {

    SDL_Init(SDL_INIT_EVERYTHING);

    int flags = 0;

    playerTex = TextureManager::LoadTexture("Assets/player.png", renderer);

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if (window)
        {
            printf("SDL window created.\n");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 25, 255);
            printf("Renderer initialized.\n");
        }
        windowShouldClose = false;
    }
    else {
        printf("Fatal error!\n");
        windowShouldClose = true;
    }
}

void Game::update() {
    render();
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    printf("Game cleaned.\n");
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            windowShouldClose = true;
            break;
        default:
            break;
    }

    // TODO: Controls

    if (event.key.keysym.sym == SDLK_ESCAPE)
    {
        windowShouldClose = true;
    }
}