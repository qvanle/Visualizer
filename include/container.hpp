#ifndef CONTAINER
#define CONTAINER

#include <vector>

#include <SDL2/SDL.h>

#include <nlohmann/json.hpp>

#include <object.hpp>

class Container : public Object 
{
private: 
    
    std::string name;

    std::vector<Object*> objects;

    SDL_Renderer* render;
protected:
    void initFromJson(nlohmann::json j);
public:
    Container(SDL_Renderer* r);
    ~Container();
    
    void setName(std::string n);

    void rendering() override;
};

#endif 
