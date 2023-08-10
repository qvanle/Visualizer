#include <window.hpp>
#include <services.hpp>

void MyWindow::rendering()
{
    while(isOpen())
    {
        if(!UImutex.try_lock()) continue;
        SDL_RenderClear(render);
        current_display->rendering();
        if(ds != nullptr) ds->rendering();
        SDL_RenderSetViewport(render, &viewport);
        if(inputbox != nullptr) inputbox->rendering();
        SDL_RenderPresent(render);
        UImutex.unlock();
    }
}

