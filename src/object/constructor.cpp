#include <object.hpp>

Object::Object(SDL_Renderer *& r)
{
    render = r;
    location = nullptr;
    crop = nullptr;
    color = nullptr;
    texture = nullptr;
    locating(0, 0, 0, 0);
    shapeType = SHAPE::NONE;
    visible = false;
}

