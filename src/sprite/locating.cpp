#include <sprite.hpp>

void Sprite::locating(int x, int y, int w, int h)
{
    Object::locating(x, y, w, h);
    for (auto &i : objects)
    {
        i->locating(x, y, w, h);
    }
}

void Sprite::locating(SDL_Rect r) 
{
    Object::locating(r);
    for (auto &i : objects)
    {
        i->locating(r);
    }
}
void Sprite::locatingX(int x)
{
    Object::locatingX(x);
    for (auto &i : objects)
    {
        i->locatingX(x);
    }
}

void Sprite::locatingY(int y)
{
    Object::locatingY(y);
    for (auto &i : objects)
    {
        i->locatingY(y);
    }
}

void Sprite::moveX(int x)
{
    Object::moveX(x);
    for (auto &i : objects)
    {
        i->moveX(x);
    }
}

void Sprite::moveY(int y)
{
    Object::moveY(y);
    for (auto &i : objects)
    {
        i->moveY(y);
    }
}

