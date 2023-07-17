#include <object.hpp>

void Object::show() 
{
    visible = true;
}

void Object::hide()
{
    visible = false;
}

bool Object::isVisible()
{
    return visible;
}

