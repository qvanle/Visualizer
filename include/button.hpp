#ifndef BUTTON 
#define BUTTON 

#include <vector>
#include <string> 

#include <object.hpp>
#include <sprite.hpp>
#include <GLOBAL.hpp>

class Button : protected Object
{
private: 
    SDL_Renderer* render;
    SDL_Rect viewport;

    std::string name;

    std::vector<Sprite*> sprites;
    BUTTON_STATUS status;

protected: 
    void importSprites(const json& mem);
    void initBackground(const json& mem);
    void importFromJson();
public: 
    Button(SDL_Renderer* render, SDL_Rect view);
    ~Button();

    void rendering();

    void linking(std::string n);
};

#endif 
