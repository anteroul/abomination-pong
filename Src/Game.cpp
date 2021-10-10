//
// Created by valiant on 4.10.2021.
//

#include "Game.h"
#include "structs.h"
#include "TextureManager.h"
#include "GameManager.h"

// Global variables:
bool pause, ballDirection;
int playerOneScore, playerTwoScore;

Racket player;
Racket opponent;
Ball ball;
SDL_Texture *backgroundTexture = nullptr;
SDL_Rect screenRect;


Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {

    SDL_Init(SDL_INIT_EVERYTHING);

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

    player.pos.x = 100;
    player.pos.y = height / 2 - 20;
    player.r.x = player.pos.x;
    player.r.y = player.pos.y;
    player.r.w = 20;
    player.r.h = 80;

    opponent.pos.x = width - 100;
    opponent.pos.y = height / 2 - 20;
    opponent.r.x = opponent.pos.x;
    opponent.r.y = opponent.pos.y;
    opponent.r.w = 20;
    opponent.r.h = 80;

    ball.speed = {5, 5};
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

        // TODO: Improve opponent AI

        // AI (disabled):

        /*
        if (ball.r.y > opponent.r.y)
            opponent.pos.y += 7;
        else
            opponent.pos.y -= 7;
        */

        // Ball collision with players:
        if (ball.r.x == player.r.x + player.r.w && ball.r.y >= player.r.y - 20 && ball.r.y <= player.r.y + 100) {
            ball.speed.x *= -1;
            ball.speed.y = (ball.r.x - player.pos.x) / (player.r.w / 2) * 5;
        }

        if (ball.r.x == opponent.r.x - opponent.r.w && ball.r.y >= opponent.r.y - 20 &&
            ball.r.y <= opponent.r.y + 100) {
            ball.speed.x *= -1;
            ball.speed.y = (ball.r.x - opponent.pos.x) / (opponent.r.w / 2) * 5;
        }

        if (player.pos.y < 0)
            player.pos.y = 0;
        if (player.pos.y + player.r.h > screenRect.h)
            player.pos.y = screenRect.h - player.r.h;


    } else {
        player.pos.y = screenRect.h / 2 - 20;
        opponent.pos.y = screenRect.h / 2 - 20;
    }

    opponent.r.x = opponent.pos.x;
    opponent.r.y = opponent.pos.y;

    render();
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Draw Background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &screenRect);

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
    switch (event.type) {
        case SDL_QUIT:
            windowShouldClose = true;
            break;
        case SDL_KEYDOWN:
            if (pause) {
                ballDirection = GameManager::SetDirection();
                pause = false;
            }
            break;
        default:
            break;
    }

    if (state[SDL_SCANCODE_UP])
        opponent.r.y = opponent.pos.y -= 10;
    if (state[SDL_SCANCODE_DOWN])
        opponent.r.y = opponent.pos.y += 10;
    if (state[SDL_SCANCODE_W])
        player.r.y = player.pos.y -= 10;
    if (state[SDL_SCANCODE_S])
        player.r.y = player.pos.y += 10;

    if (event.key.keysym.sym == SDLK_ESCAPE) {
        windowShouldClose = true;
    }
}