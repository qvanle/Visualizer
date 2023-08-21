#include <script.hpp>


bool Script::isReceiveEvent(SDL_Event& e)
{
    SDL_Rect viewport = {getX(), getY(), getW(), getH()};

    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN: 
            if(e.motion.x < viewport.x || viewport.x + viewport.w < e.motion.x) return false;
            if(e.motion.y < viewport.y || viewport.y + viewport.h < e.motion.y) return false;
            if(e.button.button == SDL_BUTTON_LEFT) 
            {
                for(auto i : buts)
                {
                    if(i->isReceiveEvent(e))
                    {
                        return true;
                    }
                }
                return false;
            }
            return true;
            break;
        case SDL_MOUSEMOTION:
            if(isMoving) return true;
            for(auto i : buts)
            {
                if(i->isReceiveEvent(e))
                {
                    return true;
                }
            }
            return false;
            break;
        default: 
            return false;
            break;
    }
}

Button* Script::react(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(isMoving)
            {
                isMoving = false;
                int dx = e.motion.x - lastMousePressed.x;
                int dy = e.motion.y - lastMousePressed.y;
                moveX(dx);
                moveY(dy);
                for(auto i : buts)
                    i->move(dx, dy);
                for(auto i : sprites)
                {
                    i->moveX(dx);
                    i->moveY(dy);
                }

            }else 
            {

                for(auto i : buts)
                {
                    if(i->isReceiveEvent(e))
                    {
                        return i;
                    }
                }
                isMoving = true;
                lastMousePressed.x = e.motion.x;
                lastMousePressed.y = e.motion.y;
            }
            return nullptr;
            break;
        case SDL_MOUSEMOTION:
            {
                if(!isMoving) 
                {
                    for(auto i : buts)
                        i->isHover(e.motion.x, e.motion.y);
                    return nullptr;
                }
                int dx = e.motion.x - lastMousePressed.x;
                int dy = e.motion.y - lastMousePressed.y;
                lastMousePressed.x = e.motion.x;
                lastMousePressed.y = e.motion.y;
                moveX(dx);
                moveY(dy);
                for(auto i : buts)
                    i->move(dx, dy);
                for(auto i : sprites)
                {
                    i->moveX(dx);
                    i->moveY(dy);
                }

                return nullptr;
                break;
            }
        default:
            return nullptr;
            break;
    }
}
