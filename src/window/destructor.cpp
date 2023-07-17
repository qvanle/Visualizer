#include <window.hpp>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

MyWindow::~MyWindow()
{
    if(render != nullptr)
    {
        SDL_DestroyRenderer(render);
        render = nullptr;
    }
    if(window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
