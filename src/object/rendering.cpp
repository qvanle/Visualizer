#include <object.hpp>

void Object::rendering()
{
    if(!visible) return ;
    if(texture == nullptr) return ;
    SDL_RenderCopy(render, texture, crop, location);
}
