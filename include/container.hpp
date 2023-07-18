#ifndef CONTAINER
#define CONTAINER

#include <vector>

#include <SDL2/SDL.h>

#include <nlohmann/json.hpp>

#include <object.hpp>

using json = nlohmann::json;

class Container : public Object 
{
private: 
    
    std::string name;

    std::vector<Object*> objects;

    SDL_Renderer* render;
protected:
    
    void initBackground(const json &mem);
    void initFromJson();
public:
    Container(SDL_Renderer* r);
    ~Container();
    
    void setName(std::string n);

    void rendering() override;
};

#endif 
