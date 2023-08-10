#include <object.hpp>

const SDL_Color* Object::getColor()
{
    return color;
}

void Object::coloring(int r, int g, int b, int a)
{
    if(color == nullptr) color = new SDL_Color;
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;

    fillWithColor();
}

void Object::coloring(SDL_Color c)
{
    if(color == nullptr) color = new SDL_Color;
    color->r = c.r;
    color->g = c.g;
    color->b = c.b;
    color->a = c.a;

    fillWithColor();
}

void Object::coloring(const json& mem)
{
    if(mem.contains("r") && mem.contains("g") && mem.contains("b"))
    {
        if(mem.contains("a")) coloring(mem["r"], mem["g"], mem["b"], mem["a"]);
        else coloring(mem["r"], mem["g"], mem["b"], 255);
    }
}

void Object::fillWithColor()
{
    if(shapeType == SHAPE::NONE) return fillRectangleByColor();
    if(shapeType == SHAPE::RECTANGLE) return fillRectangleByColor();
    if(shapeType == SHAPE::CIRCLE) return fillCircleByColor();
}
