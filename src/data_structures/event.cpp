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
    switch(e.type) 
    {
        default: 
            for(auto &i : displays)
                if(i->isReceiveEvent(e))
                    return i->react(e);
            return nullptr;
            break;
    }
}
