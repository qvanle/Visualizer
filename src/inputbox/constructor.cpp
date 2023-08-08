#include <iostream>

#include <SDL2/SDL.h>

#include <inputbox.hpp> 
#include <services.hpp>

InputBox::InputBox(SDL_Renderer* render, TTF_Font* font) : Object(render)
{
    this->font = font;
    this->render = render;
}

void InputBox::linking(std::string n) 
{
    name = n;
    importFromJson();
}

void InputBox::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::INPUTBOX_ + name + ".json");
    
    if(mem->contains("background"))
        initBackground((*mem)["background"]);

    if(mem->contains("buttons"))
        initButtons((*mem)["buttons"]);

    if(mem->contains("sprites"))
        initSprites((*mem)["sprites"]);
    
    delete mem;
}

void InputBox::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void InputBox::initButtons(const json& mem)
{
    for(auto& i : mem)
    {
        buts.push_back(new Button(render));
        if(i.contains("name")) buts.back()->linking(i["name"]);
    }
}

void InputBox::initSprites(const json& mem)
{
    for(auto& i : mem)
    {
        inputs.push_back(new Sprite(render));
        inputs.back()->setFont(font);
        if(i.contains("name")) inputs.back()->linking(i["name"].get<std::string>());
    }
}
