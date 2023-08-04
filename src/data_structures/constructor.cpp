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
    switch(type) 
    {
        case DATA_STRUCTURES_TYPE::AVL: 
            linking("AVL");
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            linking("trie");
            break;
        case DATA_STRUCTURES_TYPE::HEAP: 
            linking("HEAP");
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            linking("hash_table");
            break;
        case DATA_STRUCTURES_TYPE::GRAPH: 
            linking("graph");
            break;
        case DATA_STRUCTURES_TYPE::BTREE_4TH:
            linking("btree4th");
            break;
        case DATA_STRUCTURES_TYPE::NONE:
            break;
    }
}
