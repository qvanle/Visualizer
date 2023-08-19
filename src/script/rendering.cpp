#include <script.hpp>

void Script::rendering()
{
    Object::rendering();
    for(auto& i : sprites)
        i->rendering();
    return ;
}
