//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAENGINE_TEXTUREMANAGER_H
#define SIGMAENGINE_TEXTUREMANAGER_H
#include "SDL.h"
#include "SDL_image.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
};


#endif //SIGMAENGINE_TEXTUREMANAGER_H
