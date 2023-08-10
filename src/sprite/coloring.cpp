#include <sprite.hpp>

void Sprite::highlight()
{
    const SDL_Color* c = Object::getColor();

    if(c == nullptr) return ;

    cacheColor = *c;

    int maxChannel = std::max(std::max(c->r, c->g), c->b);
    Object::coloring(maxChannel * 0.5, maxChannel * 0.5, maxChannel * 0.5, c->a);
}

void Sprite::unhighlight()
{
    Object::coloring(cacheColor.r, cacheColor.g, cacheColor.b, cacheColor.a);
}
