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
        if(inputbox != nullptr) inputbox->rendering();
        SDL_RenderPresent(render);
        UImutex.unlock();
    }
}
void MyWindow::interacting()
{
    SDL_Event event;
    std::unique_lock<std::mutex> ul(EVmutex);
    while(isOpen())
    {
        EVcond.wait(ul, [&](){return !event_pool.empty();});
        event = event_pool.front();
        event_pool.pop();

        switch(event.type)
        {
            case SDL_QUIT:
                status = WINDOW_STATUS::IS_CLOSED;
                break;
            default:
                Button* but = nullptr;
                if(ds != nullptr && ds->isReceiveEvent(event))
                    but = ds->react(event);
                if(inputbox != nullptr && inputbox->isReceiveEvent(event))
                    but = inputbox->react(event);
                if(but == nullptr && current_display->isReceiveEvent(event))
                    but = current_display->react(event);
                react(but);
                break;
        }
    }
}
void MyWindow::getEvent()
{
    SDL_Event event;
    while(isOpen())
    {
        while(SDL_PollEvent(&event))
        {
            EVmutex.lock();
            switch(event.type) 
            {
                case SDL_QUIT: 
                    event_pool.push(event);
                    break;
                default:
                    if(ds != nullptr && ds->isReceiveEvent(event))
                        event_pool.push(event);
                    else
                    if(current_display->isReceiveEvent(event)) 
                        event_pool.push(event);
                    else if (inputbox != nullptr && inputbox->isReceiveEvent(event))
                        event_pool.push(event);
                    break;
            }
            EVcond.notify_one();
            EVmutex.unlock();
        }
    }
}
void MyWindow::run()
{
    status = WINDOW_STATUS::IS_OPEN;
    thread_pool.push_back(std::thread(&MyWindow::rendering, this));
    thread_pool.push_back(std::thread(&MyWindow::getEvent, this));
    //thread_pool.push_back(std::thread(&MyWindow::interacting, this));

    interacting();

    for(auto& thread : thread_pool)
    {
        thread.join();
    }
}
