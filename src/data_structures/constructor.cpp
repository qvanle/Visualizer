#include <data_structures.hpp>

DataStructures::DataStructures(SDL_Renderer* r, TTF_Font * f, std::mutex& m) : Object(r), ds_mutex(m)
{
    font = f;
    render = r;
    avl = nullptr;
    trie = nullptr;
    hashTable = nullptr;
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
            avl = new AVL(render, ds_mutex, font, {10, 10, 800, 600}, 128);
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            linking("trie");
            trie = new Trie(render, ds_mutex, font, {10, 10, 800, 600}, 3000);
            break;
        case DATA_STRUCTURES_TYPE::HEAP: 
            linking("HEAP");
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            linking("hash_table");
            hashTable = new HashTable(render, font, {10, 10, 800, 600}, 128);
            break;
        case DATA_STRUCTURES_TYPE::GRAPH: 
            linking("graph");
            break;
        case DATA_STRUCTURES_TYPE::BTREE_4TH:
            linking("btree4th");
            break;
        case DATA_STRUCTURES_TYPE::NONE:
            break;
        default:
            break;
    }
}
