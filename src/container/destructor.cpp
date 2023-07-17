#include <container.hpp>

Container::~Container()
{
    for (auto& object : objects)
    {
        delete object;
    }
}

