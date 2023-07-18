#include <object.hpp>
#include <algorithm>
#include <iostream>

void Object::changeToCircle()
{
    shapeType = SHAPE::CIRCLE;
    radius = std::min(getW(), getH()) / 2;

    center.x = getX() + getW() / 2;
    center.y = getY() + getH() / 2;
    fillCircleByColor();
}

void Object::changeToCircle(SDL_Point c)
{
    shapeType = SHAPE::CIRCLE;
    center = c;
    radius = std::min(getW() - c.x, c.x - getX());
    radius = std::min(radius, std::min(getH() - c.y, c.y - getY()));
    fillCircleByColor();
}

void Object::changeToCircle(int x, int y)
{
    changeToCircle({x, y});
}

void Object::changeToCircle(SDL_Point c, int r)
{
    shapeType = SHAPE::CIRCLE;
    radius = r;
    center = c;
    fillCircleByColor();
}

void Object::changeToCircle(int x, int y, int r)
{
    shapeType = SHAPE::CIRCLE;
    radius = r;
    center.x = x;
    center.y = y;
    fillCircleByColor();
}

void Object::changeToRectangle()
{
    shapeType = SHAPE::RECTANGLE;
    fillRectangleByColor();
}

void Object::setShape(const json& mem)
{
    if(mem["type"].get<std::string>() == "CIRCLE")
    {
        if(mem.contains("center"))
        {
            if(mem.contains("radius"))
                changeToCircle(mem["center"]["x"], mem["center"]["y"], mem["radius"]);
            else changeToCircle(mem["center"]["x"], mem["center"]["y"]);
        }else changeToCircle();
        
        return ;
    }
    
    if(mem["type"].get<std::string>() == "NONE" || mem["type"].get<std::string>() == "RECTANGLE")
    {
        changeToRectangle();
        return ;
    }

}

void Object::fillRectangleByColor()
{
    if(location == nullptr) locating(0, 0, 0, 0);

    if(texture != nullptr) SDL_DestroyTexture(texture);

    SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormat(0, getW(), getH(), 32, SDL_PIXELFORMAT_RGBA32);                       
    SDL_SetSurfaceBlendMode(surf, SDL_BLENDMODE_BLEND);

    SDL_FillRect(surf, nullptr, SDL_MapRGBA(surf->format, color->r, color->g, color->b, color->a));

    texture = SDL_CreateTextureFromSurface(render, surf);

    SDL_FreeSurface(surf);
}

void Object::fillCircleByColor()
{
    if(location == nullptr) locating(0, 0, 0, 0);

    if(texture != nullptr) SDL_DestroyTexture(texture);

    Uint32 rmask, gmask, bmask, amask;
    Uint32 pixelColor;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
    pixelColor = (color->r << 24) | (color->g << 16) | (color->b << 8) | color->a;
#else 
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
    pixelColor = (color->a << 24) | (color->b << 16) | (color->g << 8) | color->r;
#endif

    SDL_Surface *surf = SDL_CreateRGBSurface(0, getW(), getH(), 32, rmask, gmask, bmask, amask);
    SDL_SetSurfaceBlendMode(surf, SDL_BLENDMODE_BLEND);

    texture = SDL_CreateTextureFromSurface(render, surf);
    SDL_FreeSurface(surf);

    Uint32 *pixels = new Uint32[getW() * getH()];
    memset(pixels, 0, getW() * getH() * sizeof(Uint32));


    for(int i = center.x - radius; i <= center.x + radius; i++)
    {
        for(int j = center.y - radius; j <= center.y + radius; j++)
        {
            if((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y) <= radius * radius)
            {
                pixels[(j - getY()) * getW() + (i - getX())] = pixelColor;
            }
        }
    }

    SDL_UpdateTexture(texture, nullptr, pixels, getW() * sizeof(Uint32));
    delete[] pixels;
}













