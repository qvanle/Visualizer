#include <object.hpp>

bool Object::isLieInside(int x, int y)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    return (x >= location->x && x < location->x + location->w && y >= location->y && y < location->y + location->h);
}

bool Object::isLieInside(SDL_Point p)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    return (p.x >= location->x && p.x < location->x + location->w && p.y >= location->y && p.y < location->y + location->h);
}

bool Object::isLieInside(SDL_Rect r)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    return (r.x >= location->x && r.x + r.w <= location->x + location->w && r.y >= location->y && r.y + r.h <= location->y + location->h);
}

bool Object::isLieInside(int x, int y, int w, int h)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    return (x >= location->x && x + w <= location->x + location->w && y >= location->y && y + h <= location->y + location->h);
}

const SDL_Rect* Object::getLocation()
{
    return location;
}

int Object::getX()
{
    return location->x;
}

int Object::getY()
{
    return location->y;
}

int Object::getW()
{
    return location->w;
}

int Object::getH()
{
    return location->h;
}

void Object::locating(int x, int y, int w, int h)
{
    if(location == nullptr) location = new SDL_Rect;
    location->x = x;
    location->y = y;
    location->w = w;
    location->h = h;
}

void Object::locating(SDL_Rect l)
{
    if(location == nullptr) location = new SDL_Rect;
    location->x = l.x;
    location->y = l.y;
    location->w = l.w;
    location->h = l.h;
}

void Object::locating(const json& mem)
{
    if(mem.contains("x") && mem.contains("y") && mem.contains("w") && mem.contains("h"))
        locating(mem["x"], mem["y"], mem["w"], mem["h"]);
}

void Object::locatingX(int x)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->x = x;
}

void Object::locatingY(int y)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->y = y;
}

void Object::locatingW(int w)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->w = w;
}

void Object::locatingH(int h)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->h = h;
}

void Object::moveX(int delta)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->x += delta;
}

void Object::moveY(int delta)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->y += delta;
}

void Object::zoomW(int delta)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->w += delta;
}

void Object::zoomH(int delta)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->h += delta;
}
void Object::zoom(double delta)
{
    if(location == nullptr) location = new SDL_Rect({0, 0, 0, 0});
    location->w *= delta;
    location->h *= delta;
}

void Object::fitTheTexture() 
{
    SDL_QueryTexture(texture, nullptr, nullptr, &location->w, &location->h);
}
