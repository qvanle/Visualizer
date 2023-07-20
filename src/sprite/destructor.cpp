#include <sprite.hpp>

Sprite::~Sprite()
{
    for (auto& object : objects)
    {
        delete object;
    }
}

