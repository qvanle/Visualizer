#include "GLOBAL.hpp"
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

void InputBox::initOperator(const json& mem)
{
    std::string type = mem.get<std::string>();

    if(type == "INIT") op = DATA_STRUCTURES_OPERATOR::INIT;
    else if (type == "INSERT") op = DATA_STRUCTURES_OPERATOR::INSERT;
    else if (type == "DELETE") op = DATA_STRUCTURES_OPERATOR::DELETE;
    else if (type == "SEARCH") op = DATA_STRUCTURES_OPERATOR::SEARCH;
    else if (type == "TOP") op = DATA_STRUCTURES_OPERATOR::TOP;
    else if (type == "SIZE") op = DATA_STRUCTURES_OPERATOR::SIZE;
    else if (type == "FIND_COMPONENTS") op = DATA_STRUCTURES_OPERATOR::FIND_COMPONENTS;
    else if (type == "DIJKSTRA") op = DATA_STRUCTURES_OPERATOR::DIJKSTRA_SHORTEST_PATH;
    else if (type == "MINIMUM_SPANNING_TREE") op = DATA_STRUCTURES_OPERATOR::FIND_MINIMUM_SPANNING_TREE;
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
    if(mem->contains("operator"))
        initOperator((*mem)["operator"]);
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
