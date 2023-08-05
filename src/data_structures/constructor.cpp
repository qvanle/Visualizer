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

void DataStructures::initDisplay(const json& mem)
{

    for(auto& i : mem)
    {
        SDL_Rect viewport = {0, 0, 0, 0};
        if(i.contains("viewport"))
        {
            viewport.x = i["viewport"]["x"];
            viewport.y = i["viewport"]["y"];
            viewport.w = i["viewport"]["w"];
            viewport.h = i["viewport"]["h"];
        }
        displays.push_back(new Display(render, viewport));
        if(i.contains("name")) 
            displays.back()->linking(i["name"].get<std::string>());
    }
}

void DataStructures::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::DATA_STRUCTURES_+ name + ".json");
    
    if(mem->contains("background"))
        initBackground((*mem)["background"]);
    if(mem->contains(("sprite-structure")))
        initLinker((*mem)["sprite-structure"]);
    if(mem->contains("display"))
        initDisplay((*mem)["display"]);
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
