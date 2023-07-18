#include <object.hpp>
#include <SDL2/SDL_image.h>

void Object::textureFromFile(std::string dir)
{
    SDL_Surface *surface = IMG_Load(dir.c_str());

    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
}
