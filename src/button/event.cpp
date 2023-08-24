#include <button.hpp>

bool Button::isReceiveEvent(SDL_Event& e)
{
    switch(e.type)
    {
        case SDL_MOUSEMOTION:
            return isChoosed(e.motion.x, e.motion.y) || status == BUTTON_STATUS::HOVER;
            break;
        case SDL_MOUSEBUTTONDOWN:
            return isChoosed(e.button.x, e.button.y);
            break;
        default:
            return false;
    }


}
