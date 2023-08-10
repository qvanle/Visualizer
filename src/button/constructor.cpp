#include <iostream>
#include <button.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>

Button::Button(SDL_Renderer* render) : Object(render)
{
    this->render = render;
    status = BUTTON_STATUS::RELEASED;
    action = BUTTON_ACTION::NONE;
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
        else if(mem["type"].get<std::string>() == "DONE")
            action = BUTTON_ACTION::DONE;
        else if(mem["type"].get<std::string>() == "RANDOM") 
            action = BUTTON_ACTION::RANDOM;
        else if(mem["type"].get<std::string>() == "RANDOM2")
            action = BUTTON_ACTION::RANDOM2;
        else if(mem["type"].get<std::string>() == "RANDOM3") 
            action = BUTTON_ACTION::RANDOM3;
        else if(mem["type"].get<std::string>() == "RANDOM4") 
            action = BUTTON_ACTION::RANDOM4;
        else if(mem["type"].get<std::string>() == "RANDOM5") 
            action = BUTTON_ACTION::RANDOM5;
        else if(mem["type"].get<std::string>() == "RANDOM6") 
            action = BUTTON_ACTION::RANDOM6;
        else if(mem["type"].get<std::string>() == "RANDOM7") 
            action = BUTTON_ACTION::RANDOM7;
        else if(mem["type"].get<std::string>() == "RANDOM8") 
            action = BUTTON_ACTION::RANDOM8;
        else if(mem["type"].get<std::string>() == "RANDOM9") 
            action = BUTTON_ACTION::RANDOM9;
        else if(mem["type"].get<std::string>() == "RANDOM10") 
            action = BUTTON_ACTION::RANDOM10;
        else if(mem["type"].get<std::string>() == "RANDOM11") 
            action = BUTTON_ACTION::RANDOM11;
        else if(mem["type"].get<std::string>() == "RANDOM12") 
            action = BUTTON_ACTION::RANDOM12;
        else if(mem["type"].get<std::string>() == "RANDOM13") 
            action = BUTTON_ACTION::RANDOM13;
        else if(mem["type"].get<std::string>() == "RANDOM14") 
            action = BUTTON_ACTION::RANDOM14;
        else if(mem["type"].get<std::string>() == "RANDOM15") 
            action = BUTTON_ACTION::RANDOM15;
        else if(mem["type"].get<std::string>() == "RANDOM16") 
            action = BUTTON_ACTION::RANDOM16;
        else if(mem["type"].get<std::string>() == "FILE") 
            action = BUTTON_ACTION::FILE;
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
