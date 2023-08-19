#include <sprite.hpp>
#include <iostream>

void Sprite::aligning()
{
    if(textBox == nullptr) return ;
    int w = std::min(textBox->getW(), getW());
    int h = std::min(textBox->getH(), getH());

    textBox->cropping(textBox->getW() - w, textBox->getH() - h, w, h);
    textBox->locatingW(w);
    textBox->locatingH(h);
    switch(alignH)
    {
        case HORIZONTAL_ALIGN::LEFT:
            textBox->locatingX(getX());
            break;
        case HORIZONTAL_ALIGN::CENTER:
            textBox->locatingX(getX() + (getW() - w) / 2);
            break;
        case HORIZONTAL_ALIGN::RIGHT:
            textBox->locatingX(getX() + getW() - w);
            break;
    }
    switch(alignV)
    {
        case VERTICAL_ALIGN::TOP:
            textBox->locatingY(getY());
            break;
        case VERTICAL_ALIGN::CENTER:
            textBox->locatingY(getY() + (getH() - h) / 2);
            break;
        case VERTICAL_ALIGN::BOTTOM:
            textBox->locatingY(getY() + getH() - h);
            break;
    }
}

void Sprite::aligning(HORIZONTAL_ALIGN h, VERTICAL_ALIGN v)
{
    alignH = h;
    alignV = v;
    aligning();
}

void Sprite::aligning(HORIZONTAL_ALIGN h)
{
    alignH = h;
    aligning();
}

void Sprite::aligning(VERTICAL_ALIGN v)
{
    alignV = v;
    aligning();
}
