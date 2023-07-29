#include <display.hpp>

bool Display::mouseMotion(SDL_Event& e) 
{
    for(auto& i : buts) 
    {
        if(i->isHover(e.motion.x, e.motion.y)) 
        {
            return true;
        }
    }
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
