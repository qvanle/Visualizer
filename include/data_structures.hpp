#ifndef DATA_STRUCTURES_HPP
#define DATA_STRUCTURES_HPP

#include <iostream>
#include <vector>
#include <string> 

#include <SDL2/SDL.h>

#include <GLOBAL.hpp>

#include <object.hpp>
#include <display.hpp>

class DataStructures : protected Object
{
private:
    SDL_Renderer* render;
    std::string name;
    std::vector<Sprite*> node;
    std::string spriteLinker;
    DATA_STRUCTURES_TYPE type;

protected:
    void initBackground(const json& mem);
    void initLinker(const json& mem);
    void importFromJson();
public:
    DataStructures(SDL_Renderer* r);
    ~DataStructures();

    void linking(std::string n);
    void setDataType(DATA_STRUCTURES_TYPE t);

    void rendering();
};

#endif 
