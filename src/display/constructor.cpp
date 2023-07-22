#include <display.hpp>

Display::Display(SDL_Renderer* r, SDL_Rect v) : Object(r)
{
    render = r;
    viewPort = v;
}

void Display::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Display::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::DISPLAY_ + name + ".json");
    
    if(mem->contains("background"))
        initBackground((*mem)["background"]);
    delete mem;
}
    

void Display::linking(std::string n)
{
    name = n;
    importFromJson();
}
