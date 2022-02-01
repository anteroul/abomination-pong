//
// Created by valiant on 7.10.2021.
//

#ifndef SIGMAENGINE_STRUCTS_H
#define SIGMAENGINE_STRUCTS_H

typedef struct {
    SDL_Point pos;
    SDL_Rect r;
} Racket;

typedef struct {
    SDL_Point speed;
    SDL_Rect r;
} Ball;

typedef struct {
    SDL_Texture* sprite;
    SDL_Point pos;
} PowerUp;

#endif //SIGMAENGINE_STRUCTS_H