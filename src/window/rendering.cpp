#include <window.hpp>
#include <services.hpp>

void MyWindow::rendering()
{
    while(isOpen())
    {
        if(!display_mutex.try_lock())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        SDL_RenderClear(render);

        current_display->rendering();
        display_mutex.unlock();

        ds_mutex.lock();
        if(ds != nullptr) ds->rendering();
        ds_mutex.unlock();

        SDL_RenderSetViewport(render, &viewport);

        inputbox_mutex.lock();
        if(inputbox != nullptr) inputbox->rendering();
        inputbox_mutex.unlock();

        SDL_RenderPresent(render);

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

