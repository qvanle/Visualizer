#include <window.hpp>
#include <services.hpp>

void MyWindow::interacting()
{
    SDL_Event event;
    std::unique_lock<std::mutex> ul(event_mutex);
    while(isOpen())
    {
        EVcond.wait(ul, [&](){return !event_pool.empty();});
        event = event_pool.front();
        event_pool.pop();

        switch(event.type)
        {
            case SDL_QUIT:
                status_mutex.lock();
                status = WINDOW_STATUS::IS_CLOSED;
                status_mutex.unlock();
                step_cond.notify_all();
                break;
            default:
                Button* but = nullptr;

                inputbox_mutex.lock();
                if(but == nullptr && inputbox != nullptr && inputbox->isReceiveEvent(event))
                    but = inputbox->react(event);
                inputbox_mutex.unlock();

                ds_mutex.lock();
                if(ds != nullptr && ds->isReceiveEvent(event) && but == nullptr)
                    but = ds->react(event);
                ds_mutex.unlock();

                display_mutex.lock();
                if(but == nullptr && but == nullptr && current_display->isReceiveEvent(event))
                    but = current_display->react(event);
                display_mutex.unlock();

                react(but);
                break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
void MyWindow::getEvent()
{
    SDL_Event event;
    while(isOpen())
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type) 
            {
                case SDL_QUIT: 
                {
                    event_mutex.lock();

                    event_pool.push(event);

                    event_mutex.unlock();
                    break;
                }
                default:
                {    
                    event_mutex.lock();

                    bool isds = false;
                    bool isdisplay = false;
                    bool isinputbox = false;
                    
                    ds_mutex.lock();
                    if(ds != nullptr && ds->isReceiveEvent(event))
                        isds = true;
                    ds_mutex.unlock();
                    
                    display_mutex.lock();
                    if(current_display->isReceiveEvent(event)) 
                        isdisplay = true;
                    display_mutex.unlock();

                    inputbox_mutex.lock();
                    if (inputbox != nullptr && inputbox->isReceiveEvent(event))
                        isinputbox = true;
                    inputbox_mutex.unlock();
                    
                    if(isds || isdisplay || isinputbox)
                        event_pool.push(event);

                    event_mutex.unlock();

                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    break;
                }
            }
            EVcond.notify_one();
        }
    }
}

