#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <object.hpp>
#include <sprite.hpp>

class Script : Object
{
private: 
    SDL_Renderer* render;
    TTF_Font* font;
    
    std::vector<Sprite*> sprites;

    std::string name;
    std::string spriteName;
protected:
    void initBackground(const json& mem);
    void importFromJson();
public:
    Script(SDL_Renderer* render, TTF_Font* f);
    ~Script();
    
    void linking(std::string name);

    void highlight(int index);
    void unhighlight(int index);

    void rendering();
};

#endif 
