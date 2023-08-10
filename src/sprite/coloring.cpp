#include <sprite.hpp>
#include <iostream>

void Sprite::highlight()
{
    const SDL_Color* c = Object::getColor();

    if(c == nullptr) return ;

    cacheColor = {c->r, c->g, c->b, c->a};

    int maxChannel = std::max(std::max(c->r, c->g), c->b);
    Object::coloring(maxChannel * 0.4, maxChannel * 0.4, maxChannel * 0.4, c->a);
}

void Sprite::unhighlight()
{
    Object::coloring(cacheColor);
}
