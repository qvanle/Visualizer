#include <button.hpp>
#include <iostream>

bool Button::isChoosed(int x, int y)
{
    return x >= getX() && x < getX() + getW() && y >= getY() && y < getY() + getH();
}

bool Button::isHover(int x, int y)
{
    if(!isVisible())
    {
        return false;
    }
    if (isChoosed(x, y))
    {
        status = BUTTON_STATUS::HOVER;
        sprites[0]->hide();
        sprites[1]->show();
        return true;
    }
    else
    {
        sprites[0]->show();
        sprites[1]->hide();
        status = BUTTON_STATUS::RELEASED;
        return false;
    }
}

bool Button::isClicked(int x, int y)
{
    if (isChoosed(x, y))
    {
        sprites[0]->hide();
        sprites[1]->show();
        status = BUTTON_STATUS::HOVER;
        return true;
    }
    else
    {
        sprites[0]->show();
        sprites[1]->hide();
        status = BUTTON_STATUS::RELEASED;
        return false;
    }
}
