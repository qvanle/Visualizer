#include <object.hpp>

void Object::rendering()
{
    if(texture == nullptr) return ;

    SDL_RenderCopy(render, texture, crop, location);
}
