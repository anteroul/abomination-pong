//
// Created by valiant on 7.10.2021.
//

#ifndef SIGMAPONG_STRUCTS_H
#define SIGMAPONG_STRUCTS_H

typedef struct {
    SDL_Point pos;
    SDL_Rect r;
} Racket;

typedef struct {
    SDL_Point speed;
    SDL_Rect r;
} Ball;

#endif //SIGMAPONG_STRUCTS_H
