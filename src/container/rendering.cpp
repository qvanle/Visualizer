#include <container.hpp>

void Container::rendering() 
{
    Object::rendering();
    for(auto& obj : objects)
    {
        obj->rendering();
    }
}
