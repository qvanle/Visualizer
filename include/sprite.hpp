#ifndef SPRITE
#define SPRITE

#include <vector>

#include <SDL2/SDL.h>

#include <nlohmann/json.hpp>

#include <object.hpp>

using json = nlohmann::json;

class Sprite : public Object 
{
private: 
    
    std::string name;

    std::vector<Object*> objects;

    SDL_Renderer* render;
protected:
    
    void initBackground(const json &mem);
    void initObjects(const json &mem);
    void importFromJson();
public:
    Sprite(SDL_Renderer* r);
    ~Sprite();
    
    void linking(std::string n);

    void rendering() override;
};

#endif 
