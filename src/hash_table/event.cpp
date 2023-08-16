#include <data_structures/hash_table.hpp>

bool HashTable::isReceiveEvent(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(e.motion.x < viewport.x || viewport.x + viewport.w < e.motion.x) return false;
            if(e.motion.y < viewport.y || viewport.y + viewport.h < e.motion.y) return false;
            if(e.button.button == SDL_BUTTON_LEFT) return false;
            if(table == nullptr) return false;
            return true;
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

void HashTable::react(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
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
            break;
        case SDL_MOUSEMOTION: 
        {
            if(!isMoving) return ;
            int dx = e.motion.x - lastMousePressed.x;
            int dy = e.motion.y - lastMousePressed.y;
            lastMousePressed.x = e.motion.x;
            lastMousePressed.y = e.motion.y;
            shiftX += dx;
            shiftY += dy;
            locating(table, 0, 0);
            break;
        }
        defaut:
            break;
    }
}

