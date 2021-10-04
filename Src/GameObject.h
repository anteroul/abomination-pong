//
// Created by valiant on 4.10.2021.
//

#ifndef SIGMAENGINE_GAMEOBJECT_H
#define SIGMAENGINE_GAMEOBJECT_H
#include "Game.h"

class GameObject {
public:
    GameObject(const char* textureSheet, SDL_Renderer* ren);
    ~GameObject();
    void Update();
    void Render();
private:
    int xPos, yPos;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};


#endif //SIGMAENGINE_GAMEOBJECT_H
