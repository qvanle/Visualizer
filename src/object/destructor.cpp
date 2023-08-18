#include <object.hpp>

Object::~Object()
{
    render = nullptr;
    if(crop != nullptr) delete crop;
    if(location != nullptr) delete location;
    if(color != nullptr) delete color;
    if(texture != nullptr) SDL_DestroyTexture(texture);
    texture = nullptr;

    crop = nullptr;
    location = nullptr;
    color = nullptr;
    texture = nullptr;
}
