//
// Created by valiant on 7.10.2021.
//

#ifndef SIGMAENGINE_STRUCTS_H
#define SIGMAENGINE_STRUCTS_H

struct {
    SDL_Point pos;
    SDL_Rect r;
};

struct {
    SDL_Point speed;
    SDL_Rect r;
};

struct {
    SDL_Texture* sprite;
    SDL_Point pos;
};

#endif //SIGMAENGINE_STRUCTS_H
