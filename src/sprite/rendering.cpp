#include <sprite.hpp>

void Sprite::rendering() 
{
    SDL_RenderSetViewport(render, &viewport);
    Object::rendering();
    for(auto& obj : objects)
    {
        obj->rendering();
    }
}
