//
// Created by valiant on 27.10.2021.
//

#ifndef SIGMAPONG_TEXT_H
#define SIGMAPONG_TEXT_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "string"

class Text {
public:
    Text(const std::string &font_path, int font_size, const std::string &msg, const SDL_Color &color, SDL_Renderer* renderer);
    void Display(int x, int y, SDL_Renderer* renderer) const;
    static SDL_Texture* LoadFont(const std::string &font_path, int font_size, const std::string &msg, const SDL_Color &color, SDL_Renderer* renderer);
private:
    SDL_Texture* _text_texture = nullptr;
    mutable SDL_Rect _text_rect;
};


#endif //SIGMAPONG_TEXT_H
