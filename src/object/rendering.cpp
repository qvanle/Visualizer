#include <object.hpp>

void Object::rendering()
{
    if(!visible) return ;
    if(texture == nullptr) return ;
    SDL_RenderSetViewport(render, &viewport);
    SDL_RenderCopy(render, texture, crop, location);
}
