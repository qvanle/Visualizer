#ifndef CONTAINER
#define CONTAINER

#include <vector>

#include <SDL2/SDL.h>

#include <object.hpp>

class Container : public Object 
{
private: 
    std::vector<Object*> objects;

    SDL_Renderer* render;
protected:

public:
    Container(SDL_Renderer* r);
    ~Container();

    void rendering() override;
};

#endif 
