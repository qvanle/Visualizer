#include <object.hpp>
#include <GLOBAL.hpp>

Object::Object(SDL_Renderer *& r)
{
    render = r;
    location = nullptr;
    crop = nullptr;
    color = nullptr;
    texture = nullptr;
    locating(0, 0, 0, 0);
    shapeType = SHAPE::NONE;
    visible = false;
}


void Object::importFromJson(const json& mem)
{
    if(mem.contains("location"))
        locating(mem["location"]);
    
    if(mem.contains("crop"))
        cropping(mem["crop"]);

    if(mem.contains("color"))
        coloring(mem["color"]);

    if(mem.contains("shape"))
        setShape(mem["shape"]);

    if(mem.contains("visible"))
        visible = mem["visible"];

    if(mem.contains("image"))
        textureFromFile(PATH::ASSETS::GRAPHICS + mem["image"].get<std::string>());

    return ;
}
