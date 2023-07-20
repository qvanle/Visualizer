#include <fstream>
#include <iostream>

#include <sprite.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>


Sprite::Sprite(SDL_Renderer* r) : Object(r) 
{
    render = r;
}

void Sprite::linking(std::string n)
{
    name = n;
    initFromJson();
}

void Sprite::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Sprite::initFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::SPRITE_ + name + ".json");

    initBackground((*mem)["background"]);
    
    delete mem;
}
