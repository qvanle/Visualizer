#include <window.hpp>
#include <services.hpp>

void MyWindow::rendering()
{
    while(isOpen())
    {
        if(!renderMutex.try_lock())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            continue;
        }

        SDL_RenderClear(render);

        current_display->rendering();

        if(ds != nullptr) ds->rendering();

        SDL_RenderSetViewport(render, &viewport);

        if(inputbox != nullptr) inputbox->rendering();

        SDL_RenderPresent(render);

       renderMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

