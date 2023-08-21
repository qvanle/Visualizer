#include <data_structures/AVL.hpp>

bool AVL::isReceiveEvent(SDL_Event& e)
{
    std::lock_guard<std::mutex> lk(animate_mutex);
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(currentScript != nullptr && currentScript->isReceiveEvent(e)) return true;
            if(e.motion.x < viewport.x || viewport.x + viewport.w < e.motion.x) return false;
            if(e.motion.y < viewport.y || viewport.y + viewport.h < e.motion.y) return false;
            if(e.button.button == SDL_BUTTON_LEFT) return false;
            if(root == nullptr) return false;
            return true;
            break;
        case SDL_MOUSEMOTION:
            if(isMoving) return true;
            if(currentScript == nullptr) return false;
            if(currentScript->isReceiveEvent(e)) return true;
            return false;
            break;
        default:
            return false;
            break;
    }
}

Button* AVL::react(SDL_Event& e)
{
    std::lock_guard<std::mutex> lk(animate_mutex);
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(currentScript != nullptr && currentScript->isReceiveEvent(e)) 
            {
                return currentScript->react(e);
            }
            if(isMoving)
            {
                isMoving = false;
                int dx = e.motion.x - lastMousePressed.x;
                int dy = e.motion.y - lastMousePressed.y;
                shiftX += dx;
                shiftY += dy;
            }else 
            {
                isMoving = true;
                lastMousePressed.x = e.motion.x;
                lastMousePressed.y = e.motion.y;
            }
            return nullptr;
            break;
        case SDL_MOUSEMOTION: 
        {
            if(currentScript != nullptr && currentScript->isReceiveEvent(e)) 
                return currentScript->react(e);
            if(!isMoving) return nullptr;
            int dx = e.motion.x - lastMousePressed.x;
            int dy = e.motion.y - lastMousePressed.y;
            lastMousePressed.x = e.motion.x;
            lastMousePressed.y = e.motion.y;
            shiftX += dx;
            shiftY += dy;
            if(cache != nullptr) 
            {
                cache->sprite->moveX(dx);
                cache->sprite->moveY(dy);
            }
            return nullptr;
            break;
        }
        defaut:
            return nullptr;
            break;
    }
    return nullptr;
}

void AVL::closeScript()
{
    currentScript = nullptr;
}
