//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAENGINE_TEXTUREMANAGER_H
#define SIGMAENGINE_TEXTUREMANAGER_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "iostream"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
	static SDL_Texture* CreateTextureFromText(TTF_Font* font, std::string text, SDL_Color color, SDL_Renderer *ren);
};


#endif //SIGMAENGINE_TEXTUREMANAGER_H
