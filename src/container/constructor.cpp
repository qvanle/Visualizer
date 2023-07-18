#include <container.hpp>
#include <GLOBAL.hpp>

Container::Container(SDL_Renderer* r) : Object(r) 
{
    render = r;
}

void Container::setName(std::string n)
{
    name = n;
}
