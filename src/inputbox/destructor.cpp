#include <inputbox.hpp>

InputBox::~InputBox()
{
    for(auto& i : buts) delete i;
    for(auto& i : inputs) delete i;
}
