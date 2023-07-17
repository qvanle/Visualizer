#include <object.hpp>

const SDL_Color* Object::getColor()
{
    return color;
}

void Object::coloring(int r, int g, int b, int a)
{
    if(color == nullptr) color = new SDL_Color;
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;

    fillWithColor();
}

void Object::coloring(SDL_Color c)
{
    if(color == nullptr) color = new SDL_Color;
    color->r = c.r;
    color->g = c.g;
    color->b = c.b;
    color->a = c.a;

    fillWithColor();
}

void Object::fillWithColor()
{
    if(location == nullptr) locating(0, 0, 0, 0);

    if(texture != nullptr) SDL_DestroyTexture(texture);

    SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormat(0, getW(), getH(), 32, SDL_PIXELFORMAT_RGBA32);                       
    SDL_SetSurfaceBlendMode(surf, SDL_BLENDMODE_BLEND);
    
    SDL_FillRect(surf, nullptr, SDL_MapRGBA(surf->format, color->r, color->g, color->b, color->a));

    texture = SDL_CreateTextureFromSurface(ren, surf);
    
    SDL_FreeSurface(surf);

}
