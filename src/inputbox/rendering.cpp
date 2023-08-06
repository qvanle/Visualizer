#include <inputbox.hpp>

void InputBox::rendering()
{
    Object::rendering();
    for(auto& i : buts) i->rendering();
    for(auto& i : inputs) i->rendering();
}
