#include <object.hpp>

Object::Object(SDL_Renderer *& r)
{
    ren = r;
    location = nullptr;
    crop = nullptr;
    color = nullptr;
    texture = nullptr;
    locating(0, 0, 0, 0);
}

