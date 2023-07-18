#include <fstream>
#include <iostream>

#include <container.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>


Container::Container(SDL_Renderer* r) : Object(r) 
{
    render = r;
}

void Container::setName(std::string n)
{
    name = n;
    initFromJson();
}

void Container::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Container::initFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::CONTAINER_ + name + ".json");

    initBackground((*mem)["background"]);
    
    delete mem;
}
