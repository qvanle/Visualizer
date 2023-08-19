#include <sprite.hpp>
#include <services.hpp>

void Sprite::setTextBoxTransparent(int a)
{
    if(textBox == nullptr) return ;
    SDL_Color c = *getColor();
    c.a = a;
    coloring(c);
}

void Sprite::setText(std::string s)
{
    if(textBox == nullptr) return ;
    for(char c : s) 
    {
        if(!receiveDigit && NUMBER::isDigit(c)) return ;
        if(!receiveLetter && NUMBER::isLetter(c)) return ;
        if(!receiveSymbol && NUMBER::isSymbol(c)) return ;
    }
    if(s.size() > maxSize) s = s.substr(0, maxSize);
    textBox->setText(s);
    aligning();
}

void Sprite::typing(char c)
{
    if(textBox == nullptr) return ;
    if(!receiveDigit && NUMBER::isDigit(c)) return ;
    if(!receiveLetter && NUMBER::isLetter(c)) return ;
    if(!receiveSymbol && NUMBER::isSymbol(c)) return ;
    if(textBox->getSize() >= maxSize) return ;
    textBox->addCharacter(c);
    aligning();
}

void Sprite::typing(std::string s)
{
    if(textBox == nullptr) return ;
    if(textBox->getText().size() + s.size() >= maxSize) return ;
    for(char c : s) 
    {
        if(!receiveDigit && NUMBER::isDigit(c)) return ;
        if(!receiveLetter && NUMBER::isLetter(c)) return ;
        if(!receiveSymbol && NUMBER::isSymbol(c)) return ;
    }
    if(textBox->getSize() + s.size() > maxSize) s = s.substr(0, maxSize);
    textBox->addText(s);
    aligning();
}

void Sprite::backspace()
{
    if(textBox == nullptr) return ;
    textBox->removeCharacter();
    aligning();
}

void Sprite::backspace(int n)
{
    if(textBox == nullptr) return ;
    textBox->removeCharacter(n);
    aligning();
}


