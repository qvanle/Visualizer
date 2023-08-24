#include <data_structures/graph.hpp>


bool Graph::isReceiveEvent(SDL_Event& e)
{
    std::lock_guard<std::mutex> lk(animate_mutex);
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(e.motion.x < viewport.x || viewport.x + viewport.w < e.motion.x) return false;
            if(e.motion.y < viewport.y || viewport.y + viewport.h < e.motion.y) return false;
            if(e.button.button == SDL_BUTTON_LEFT) return false;
            for(auto i : nodes)
                if(i->sprite->isLieInside(e.motion.x, e.motion.y))
                    return true;
            return false;
            break;
        case SDL_MOUSEMOTION:
            if(isMoving) return true;
            return false;
            break;
        default:
            return false;
            break;
    }
}


Button* Graph::react(SDL_Event& e)
{
    std::lock_guard<std::mutex> lk(animate_mutex);
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(isMoving)
            {
                isMoving = false;
                chosenNode = nullptr;
            }else 
            {
                isMoving = true;

                lastMousePressed.x = e.motion.x;
                lastMousePressed.y = e.motion.y;
                for(auto i : nodes)
                    if(i->sprite->isLieInside(e.motion.x, e.motion.y))
                    {
                        chosenNode = i;
                        break;
                    }
            }
            return nullptr;
            break;
        case SDL_MOUSEMOTION: 
            {
                if(!isMoving) return nullptr;
                int dx = e.motion.x - lastMousePressed.x;
                int dy = e.motion.y - lastMousePressed.y;
                lastMousePressed.x = e.motion.x;
                lastMousePressed.y = e.motion.y;
                if(chosenNode == nullptr) return nullptr;
                chosenNode->sprite->moveX(dx);
                chosenNode->sprite->moveY(dy);
                return nullptr;
                break;
            }
defaut:
            return nullptr;
            break;
    }
    return nullptr;
}

