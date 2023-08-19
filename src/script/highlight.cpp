#include <script.hpp>

void Script::highlight(int index)
{
    if(index < 0 || index >= sprites.size()) return ;
    sprites[index]->setTextBoxTransparent(180);
}

void Script::unhighlight(int index)
{
    if(index < 0 || index >= sprites.size()) return ;
    sprites[index]->setTextBoxTransparent(0);
}
