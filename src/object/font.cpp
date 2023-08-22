#include <object.hpp>
#include <iostream>

void Object::setFont(TTF_Font* f)
{
    font = f;
    textToTexture();
}

void Object::setText(std::string t)
{
    text = t;
    textToTexture();
}

void Object::addText(std::string t)
{
    text += t;
    textToTexture();
}

void Object::addCharacter(char c)
{
    text += c;
    textToTexture();
}

void Object::removeCharacter()
{
    if (text.size() > 0)
        text.pop_back();
    textToTexture();
}

void Object::removeCharacter(int n)
{
    if(n == 0) return ;
    if(text.size() <= n) text.clear();
    else text.erase(text.end() - n, text.end());
    textToTexture();
}

void Object::textToTexture()
{
    if(font == nullptr) return ;
    if(color == nullptr) return ;
    if(render == nullptr) return ;
    if(texture != nullptr) 
    { 
        SDL_DestroyTexture(texture);
    }
    texture = nullptr;

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), *color);

    if(surface == nullptr) return ;

    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    fitTheTexture();
}

std::string Object::getText()
{
    return text;
}

int Object::getSize()
{
    return text.size();
}
