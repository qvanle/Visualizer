#include <object.hpp>

void Object::setFont(TTF_Font* f)
{
    font = f;
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
    if(texture != nullptr) SDL_DestroyTexture(texture);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), *color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
}
