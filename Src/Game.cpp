//
// Created by valiant on 4.10.2021.
//

#include "Game.h"
#include "string"
#include "structs.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "Text.h"

// Enable two-player mode if set to false
bool soloEnabled = true;

// Global variables:
bool pause, ballDirection;
int playerOneScore, playerTwoScore;

Racket p1;
Racket p2;
Ball ball;
SDL_Rect screenRect;
SDL_Texture *backgroundTexture = nullptr;

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if (window) {
            printf("SDL window created.\n");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 25, 255);
            printf("Renderer initialized.\n");
        }
        windowShouldClose = false;
    } else {
        printf("Fatal error!\n");
        windowShouldClose = true;
    }


    // Init values:

    screenRect = {0, 0, width, height};

    p1.pos.x = 100;
    p1.pos.y = height / 2 - 20;
    p1.r.x = p1.pos.x;
    p1.r.y = p1.pos.y;
    p1.r.w = 20;
    p1.r.h = 80;

    p2.pos.x = width - 100;
    p2.pos.y = height / 2 - 20;
    p2.r.x = p2.pos.x;
    p2.r.y = p2.pos.y;
    p2.r.w = 20;
    p2.r.h = 80;

    ball.speed = {10, 5};
    ball.r.x = width / 2;
    ball.r.y = height / 2;
    ball.r.w = 20;
    ball.r.h = 20;

    backgroundTexture = TextureManager::LoadTexture("Assets/background.png", renderer);

    playerOneScore = 0;
    playerTwoScore = 0;

    pause = true;

}

void Game::update() {

    // Game logic:
    if (!pause) {
        if (!ballDirection) {
            ball.r.x -= ball.speed.x;
            ball.r.y -= ball.speed.y;
        } else {
            ball.r.x += ball.speed.x;
            ball.r.y += ball.speed.y;
        }

        // Ball collision with walls:
        if (ball.r.y < 0)
            ball.speed.y *= -1;
        if (ball.r.y > screenRect.h - 20)
            ball.speed.y *= -1;

        // Score logic:
        if (ball.r.x < -20) {
            ball.r.x = screenRect.w / 2;
            ball.r.y = screenRect.h / 2;
            playerTwoScore++;
            printf("P2: %d\n", playerTwoScore);
            printf("P1: %d\n", playerOneScore);
            pause = true;
        }
        if (ball.r.x > screenRect.w) {
            ball.r.x = screenRect.w / 2;
            ball.r.y = screenRect.h / 2;
            playerOneScore++;
            printf("P2: %d\n", playerTwoScore);
            printf("P1: %d\n", playerOneScore);
            pause = true;
        }

        // AI:
        if (soloEnabled) {
            if (ball.r.y > p1.r.y)
                p1.pos.y += 7;
            else
                p1.pos.y -= 7;
        }


        // Ball collision with players:
        if (ball.r.x == p1.r.x + p1.r.w && ball.r.y >= p1.r.y - 20 && ball.r.y <= p1.r.y + 100) {
            ball.speed.x *= -1;
            ball.speed.y = (ball.r.y - p1.pos.y + 60) / (p1.r.h / 2) * 3;
        }

        if (ball.r.x == p2.r.x - p2.r.w && ball.r.y >= p2.r.y - 20 && ball.r.y <= p2.r.y + 100) {
            ball.speed.x *= -1;
            ball.speed.y = (ball.r.y - p2.pos.y + 60) / (p2.r.h / 2) * 3;
        }

        if (p1.pos.y < 0)
            p1.pos.y = 0;
        if (p1.pos.y + p1.r.h > screenRect.h)
            p1.pos.y = screenRect.h - p1.r.h;

        if (p2.pos.y < 0)
            p2.pos.y = 0;
        if (p2.pos.y + p2.r.h > screenRect.h)
            p2.pos.y = screenRect.h - p2.r.h;


    } else {
        p1.pos.y = screenRect.h / 2 - 20;
        p2.pos.y = screenRect.h / 2 - 20;
        ball.speed = {10, 5};
    }

    p1.r.x = p1.pos.x;
    p1.r.y = p1.pos.y;
    p2.r.x = p2.pos.x;
    p2.r.y = p2.pos.y;

    render();
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Draw Background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &screenRect);

    // Draw Player
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &p1.r);

    // Draw Opponent
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &p2.r);

    // Draw Ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball.r);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    printf("Game cleaned.\n");
}

void Game::handleEvents() {

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            windowShouldClose = true;
            break;
        case SDL_KEYDOWN:
            if (pause) {
                if (state[SDL_SCANCODE_SPACE]) {
                    ballDirection = GameManager::SetDirection();
                    pause = false;
                }
            }
            break;
        default:
            break;
    }

    // Red player controls:
    if (state[SDL_SCANCODE_UP])
        p2.r.y = p2.pos.y -= 10;
    if (state[SDL_SCANCODE_DOWN])
        p2.r.y = p2.pos.y += 10;
    // Blue player controls:
    if(!soloEnabled) {
        if (state[SDL_SCANCODE_W])
            p1.r.y = p1.pos.y -= 10;
        if (state[SDL_SCANCODE_S])
            p1.r.y = p1.pos.y += 10;
    }

    if (event.key.keysym.sym == SDLK_ESCAPE) {
        windowShouldClose = true;
    }
}