#include <window.hpp>

void MyWindow::rendering()
{
    while(isOpen())
    {
        SDL_RenderClear(render);
        SDL_RenderPresent(render);
    }
}
void MyWindow::interacting()
{
    while(isOpen())
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                status = WINDOW_STATUS::IS_CLOSED;
            }
        }
    }
}
void MyWindow::run()
{
    status = WINDOW_STATUS::IS_OPEN;
    thread_pool.push_back(std::thread(&MyWindow::rendering, this));
    thread_pool.push_back(std::thread(&MyWindow::interacting, this));

    for(auto& thread : thread_pool)
    {
        thread.join();
    }
}
