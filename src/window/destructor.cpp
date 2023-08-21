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
    if(myfont != nullptr) TTF_CloseFont(myfont);

    for(auto &i : thread_pool)
    {
        if(i.joinable())
        {
            i.join();
        }
    }

    for(auto &i : display_pool)
    {
        delete i.second;
    }
    
    for(auto &i : ds_pool)
    {
        delete i.second;
    }

    for(auto &i : inputbox_pool)
    {
        delete i.second;
    }
    
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
