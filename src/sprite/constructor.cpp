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
    importFromJson();
}

void Sprite::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Sprite::initObjects(const json &mem)
{
    objects.clear();
    for(auto& i : mem)
    {
        Object* obj = new Object(render);
        if(i.contains("name")) obj->linking(i["name"]);

        obj->importFromJson(i);

        obj->moveX(getX());
        obj->moveY(getY());

        objects.push_back(obj);
    }
}

void Sprite::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::SPRITE_ + name + ".json");

    initBackground((*mem)["background"]);
    
    if(mem->contains("objects")) initObjects((*mem)["objects"]);
    delete mem;
}
