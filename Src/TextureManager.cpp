//
// Created by valiant on 4.10.2021.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *fileName, SDL_Renderer *ren)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    std::cout << fileName << " loaded." << std::endl;
    return tex;
}

SDL_Texture* TextureManager::CreateTextureFromText(TTF_Font* font, std::string text, SDL_Color color, SDL_Renderer *ren)
{
	SDL_Surface* tmpSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}