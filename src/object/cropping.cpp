#include <object.hpp>

const SDL_Rect* Object::getCrop()
{
    return crop;
}

void Object::cropping(int x, int y, int w, int h)
{
    if(crop == nullptr) crop = new SDL_Rect;
    crop->x = x;
    crop->y = y;
    crop->w = w;
    crop->h = h;
}

void Object::cropping(SDL_Rect c)
{
    if(crop == nullptr) crop = new SDL_Rect;
    crop->x = c.x;
    crop->y = c.y;
    crop->w = c.w;
    crop->h = c.h;
}

void Object::cropping(const json& mem)
{
    if(mem.contains("x") && mem.contains("y") && mem.contains("w") && mem.contains("h"))
        cropping(mem["x"], mem["y"], mem["w"], mem["h"]);
}

void Object::noCropping()
{
    if(crop != nullptr) delete crop;
    crop = nullptr;
}
