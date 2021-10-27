//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAPONG_TEXTUREMANAGER_H
#define SIGMAPONG_TEXTUREMANAGER_H
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
};


#endif //SIGMAPONG_TEXTUREMANAGER_H
