#include <sprite.hpp>

void Sprite::typing(char c)
{
    if(textBox == nullptr) return ;
    textBox->addCharacter(c);
}

void Sprite::typing(std::string s)
{
    if(textBox == nullptr) return ;
    textBox->addText(s);
}

void Sprite::backspace()
{
    if(textBox == nullptr) return ;
    textBox->removeCharacter();
}

void Sprite::backspace(int n)
{
    if(textBox == nullptr) return ;
    textBox->removeCharacter(n);
}


