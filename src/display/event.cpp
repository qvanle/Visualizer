#include <display.hpp>

bool Display::mouseMotion(SDL_Event& e) 
{
    return false;
}

bool Display::isReceiveEvent(SDL_Event& e)
{
    
    switch(e.type) 
    {
        case SDL_MOUSEMOTION: 
            return mouseMotion(e);
            break;
        case SDL_QUIT: 
            return false;
            break;
        default: 
            return false;
            break;
    }
}