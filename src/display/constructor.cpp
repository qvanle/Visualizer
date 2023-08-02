#include <display.hpp>
#include <iostream>

Display::Display(SDL_Renderer* r, SDL_Rect v) : Object(r)
{
    render = r;
    viewport = v;
}

void Display::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Display::initButtons(const json& mem)
{
    for(auto& i : mem)
    {
        Button* b = new Button(render);
        b->linking(i["name"].get<std::string>());
        buts.push_back(b);
    }
}

void Display::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::DISPLAY_ + name + ".json");
    
    if(mem->contains("background"))
        initBackground((*mem)["background"]);
    if(mem->contains("buttons"))
        initButtons((*mem)["buttons"]);
    delete mem;
}
    

void Display::linking(std::string n)
{
    name = n;
    importFromJson();
}
