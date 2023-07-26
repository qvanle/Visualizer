#include <display.hpp>
#include <SDL2/SDL.h>

void Display::rendering()
{
    SDL_RenderSetViewport(render, &viewPort);
    Object::rendering();
    for(auto& i : buts)
        i->rendering();
}
