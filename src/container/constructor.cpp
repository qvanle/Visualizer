#include <container.hpp>
#include <GLOBAL.hpp>
#include <fstream>



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

}

void Container::initFromJson()
{
    std::string PATH = PATH::ATB::CONTAINER_ + name + ".json";
    json mem; 

    std::ifstream fin(PATH);

    fin >> mem;
    
    initBackground(mem["background"]);

}
