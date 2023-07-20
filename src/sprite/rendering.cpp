#include <sprite.hpp>

void Sprite::rendering() 
{
    Object::rendering();
    for(auto& obj : objects)
    {
        obj->rendering();
    }
}
