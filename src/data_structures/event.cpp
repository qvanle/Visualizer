#include "GLOBAL.hpp"
#include <data_structures.hpp>



bool DataStructures::isReceiveEvent(SDL_Event& e)
{
    switch(e.type) 
    {
        case SDL_QUIT: 
            return false;
            break;
        default: 
            for(auto &i : displays)
                if(i->isReceiveEvent(e))
                    return true;
            return false;
            break;
    }
}


Button* DataStructures::react(SDL_Event& e)
{
    Button* but = nullptr;
    for(auto &i : displays)
        if(i->isReceiveEvent(e))
            but = i->react(e);
    if(but == nullptr) return but;

    switch (but->getAction())
    {
        case BUTTON_ACTION::INIT:
            break;
        case BUTTON_ACTION::INSERT:
            break;
        case BUTTON_ACTION::DELETE:
            break;
        case BUTTON_ACTION::SEARCH:
            break;
        default:
            break;
    }

    return nullptr;
}
