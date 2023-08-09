#include <inputbox.hpp>

bool InputBox::isReceiveEvent(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_QUIT: 
            return false;
            break;
        default:
            if(isButtonReceiveEvent(e) || isInputReceiveEvent(e))
                return true;
            return false;
            break;
    }
}

bool InputBox::isInputReceiveEvent(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN: 
            for(auto& inp : inputs) 
                if(inp->isLieInside(e.motion.x, e.motion.y)) 
                    return true; 
            return false;
            break;
        case SDL_MOUSEMOTION: 
            for(auto& inp : inputs) 
                if(inp->isLieInside(e.motion.x, e.motion.y)) 
                    return true; 
            return false;
            break;
        case SDL_KEYDOWN: 
            if(typingIndex == -1) 
                return false;
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool InputBox::isButtonReceiveEvent(SDL_Event& e)
{
    for(auto& but : buts)
    {
        if(but->isReceiveEvent(e))
        {
            return true;
        }
    }
    return false;
}

Button* InputBox::react(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_KEYDOWN:
        {
            if(typingIndex == -1)
                return nullptr;
            if(e.key.keysym.sym == SDLK_BACKSPACE)
            {
                inputs[typingIndex]->backspace();
            }
            if(SDLK_SPACE <= e.key.keysym.sym && e.key.keysym.sym <= SDLK_z)
            {
                inputs[typingIndex]->typing(e.key.keysym.sym);
            }
            return nullptr;
            break;
        }
        case SDL_MOUSEMOTION: 
        {    
            for(auto& but : buts)
                but->isHover(e.motion.x, e.motion.y);
            return nullptr;
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            int i = 0;
            for(auto& inp : inputs)
            {
                if(inp->isLieInside(e.motion.x, e.motion.y))
                {
                    typingIndex = i;
                    return nullptr;
                }
                i++;
            }
            typingIndex = 0;
            for(auto& but : buts)
                if(but->isClicked(e.motion.x, e.motion.y))
                    return but;
            return nullptr;
            break;
        }
        default:
            return nullptr;
    }
}

