#include <data_structures.hpp>

DataStructures::DataStructures(SDL_Renderer* r) : Object(r)
{
    render = r;
}

void DataStructures::initBackground(const json& mem) 
{
    Object::importFromJson(mem);
}

void DataStructures::linking(std::string n)
{
    name = n;
    importFromJson();
}

void DataStructures::initLinker(const json& mem)
{
    if(!mem.contains("name"))
        return ;
    spriteLinker = mem["name"];
}

void DataStructures::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::DATA_STRUCTURES_+ name + ".json");
    
    if(mem->contains("background"))
        initBackground((*mem)["background"]);
    if(mem->contains(("sprite-structure")))
        initLinker((*mem)["sprite-structure"]);
}

void DataStructures::setDataType(DATA_STRUCTURES_TYPE t)
{
    type = t;
}
