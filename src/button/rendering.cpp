#include <button.hpp>
#include <iostream>

void Button::rendering()
{
    Object::rendering();   
    if(status == BUTTON_STATUS::HOVER) 
    {
        sprites[1]->rendering();
    
    }else if(status == BUTTON_STATUS::RELEASED) 
        sprites[0]->rendering();
}
