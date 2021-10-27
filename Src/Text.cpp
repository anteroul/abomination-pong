//
// Created by valiant on 27.10.2021.
//

#include "Text.h"

Text::Text(const std::string &font_path, int font_size, const std::string &msg, const SDL_Color &color, SDL_Renderer* renderer) {
    _text_texture = LoadFont(font_path, font_size, msg, color, renderer);
    SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

void Text::Display(int x, int y, SDL_Renderer* renderer) const {
    _text_rect.x = x;
    _text_rect.y = y;
    SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture* Text::LoadFont(const std::string &font_path, int font_size, const std::string &msg, const SDL_Color &color, SDL_Renderer* renderer) {
    TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
    auto surface = TTF_RenderText_Solid(font, msg.c_str(), color);
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}