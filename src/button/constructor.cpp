#include <iostream>
#include <button.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>

Button::Button(SDL_Renderer* render) : Object(render)
{
    this->render = render;
    status = BUTTON_STATUS::RELEASED;
}

void Button::importFromJson() 
{
    json* mem = JSON::readFile(PATH::ATB::BUTTON_ + name + ".json");
    if(mem->contains("background")) 
        initBackground((*mem)["background"]);
    if(mem->contains("sprites")) 
        initSprites((*mem)["sprites"]);
    if(mem->contains("action")) 
        initAction((*mem)["action"]);
}

void Button::initAction(const json& mem)
{
    if(mem.contains("type"))
    {
        if(mem["type"].get<std::string>() == "CHANGE_SCREEN")
            action = BUTTON_ACTION::CHANGE_SCREEN;
        else if(mem["type"].get<std::string>() == "INSERT")
            action = BUTTON_ACTION::INSERT;
        else if(mem["type"].get<std::string>() == "DELETE")
            action = BUTTON_ACTION::DELETE;
        else if(mem["type"].get<std::string>() == "INIT")
            action = BUTTON_ACTION::INIT;
        else if(mem["type"].get<std::string>() == "SEARCH")
            action = BUTTON_ACTION::SEARCH;
        else if(mem["type"].get<std::string>() == "SETTING")
            action = BUTTON_ACTION::SETTING;
        else
            action = BUTTON_ACTION::NONE;
    }
    if(mem.contains("args"))
        args = mem["args"];
}

void Button::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Button::initSprites(const json& mem)
{
    for(auto& sprite : mem) 
    {
        sprites.push_back(new Sprite(render));
        sprites.back()->linking(sprite["name"].get<std::string>());
        sprites.back()->moveX(getX());
        sprites.back()->moveY(getY());
    }
}


void Button::linking(std::string n)
{
    name = n;
    importFromJson();
}
