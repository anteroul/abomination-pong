//
// Created by valiant on 4.10.2021.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
}

GameObject::~GameObject() {

}

void GameObject::Update() {
    xPos = 0;
    yPos = 0;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = xPos;
    destRect.w = yPos;
    destRect.x = srcRect.w * 2;
    destRect.y = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
