#include <object.hpp>
#include <SDL2/SDL_image.h>

void Object::importFromFile(std::string dir)
{
    SDL_Surface *surface = IMG_Load(dir.c_str());

    texture = SDL_CreateTextureFromSurface(ren, surface);

    SDL_FreeSurface(surface);
}
