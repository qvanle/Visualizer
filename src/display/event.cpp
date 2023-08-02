#include <display.hpp>

bool Display::isButtonReceiveEvent(SDL_Event& e)
{
    for(auto& but : buts)
        if(but->isReceiveEvent(e)) return true;
    return false;
}

bool Display::isReceiveEvent(SDL_Event& e)
{
    
    switch(e.type) 
    {
        case SDL_QUIT: 
            return false;
            break;
        default: 
            if(isButtonReceiveEvent(e)) return true;
            return false;
            break;
    }
}

Button* Display::react(SDL_Event& e)
{
    switch(e.type) 
    {
        case SDL_MOUSEMOTION: 
            for(auto& but : buts)
                but->isHover(e.motion.x, e.motion.y);
            return nullptr;
        case SDL_MOUSEBUTTONDOWN: 
            for(auto& but :buts) 
                if(but->isClicked(e.motion.x, e.motion.y)) return but;
            return nullptr;
        default: 
            return nullptr;
    }
}
