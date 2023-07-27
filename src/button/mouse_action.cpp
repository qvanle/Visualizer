#include <button.hpp>

bool Button::isChoosed(int x, int y)
{
    return x >= getX() && x < getX() + getW() && y >= getY() && y < getY() + getH();
}

bool Button::isHover(int x, int y)
{
    if (isChoosed(x, y))
    {
        status = BUTTON_STATUS::HOVER;
        return true;
    }
    else
    {
        status = BUTTON_STATUS::RELEASED;
        return false;
    }
}

bool Button::isClicked(int x, int y)
{
    if (isChoosed(x, y))
    {
        status = BUTTON_STATUS::HOVER;
        return true;
    }
    else
    {
        status = BUTTON_STATUS::RELEASED;
        return false;
    }
}
