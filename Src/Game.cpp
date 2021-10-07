//
// Created by valiant on 4.10.2021.
//

#include "Game.h"
#include "structs.h"
#include "TextureManager.h"

// Global variables:
GameObject player;
GameObject opponent;
GameObject ball;
SDL_Texture* backgroundTexture = nullptr;
SDL_Rect screenRect;


Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {

    SDL_Init(SDL_INIT_EVERYTHING);

    int flags = 0;

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


    // Init values:

    screenRect = {0, 0, width, height};

    player.r.x = 100;
    player.r.y = height / 2 - 20;
    player.r.w = 20;
    player.r.h = 80;

    opponent.r.x = width - 100;
    opponent.r.y = height / 2 - 20;
    opponent.r.w = 20;
    opponent.r.h = 80;

    ball.r.x = width / 2;
    ball.r.y = height / 2;
    ball.r.w = 20;
    ball.r.h = 20;

    backgroundTexture = TextureManager::LoadTexture("Assets/background.png", renderer);
}

void Game::update() {
    render();
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Draw Background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &screenRect);

    // Draw Player
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &player.r);

    // Draw Opponent
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &opponent.r);

    // Draw Ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball.r);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    printf("Game cleaned.\n");
}

void Game::handleEvents() {

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

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

    if(state[SDL_SCANCODE_UP])
        player.r.y -= 10;
    if(state[SDL_SCANCODE_DOWN])
        player.r.y += 10;

    if (event.key.keysym.sym == SDLK_ESCAPE)
    {
        windowShouldClose = true;
    }
}