#include <script.hpp>

Script::~Script()
{
    render = nullptr;
    font = nullptr;
    for(int i = 0; i < sprites.size(); i++)
        if(sprites[i] != nullptr) delete sprites[i];
    sprites.clear();
}
