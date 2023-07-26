#include <button.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>

Button::Button(SDL_Renderer* render, SDL_Rect view) : Object(render, view)
{
    this->render = render;
    viewport = view;
}

void Button::importFromJson() 
{
    json* mem = JSON::readFile(PATH::ATB::BUTTON_ + name + ".json");
    if(mem->contains("background")) 
        initBackground((*mem)["background"]);
    if(mem->contains("sprites")) 
        importSprites((*mem)["sprites"]);
}

void Button::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}

void Button::importSprites(const json& mem)
{
    for(auto& sprite : mem) 
    {
        sprites.push_back(new Sprite(render, viewport));
        sprites.back()->linking(sprite.get<std::string>());
    }
}

void Button::linking(std::string n)
{
    name = n;
    importFromJson();
}
