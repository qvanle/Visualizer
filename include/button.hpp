#ifndef BUTTON 
#define BUTTON 

#include <vector>
#include <string> 

#include <object.hpp>
#include <sprite.hpp>
#include <GLOBAL.hpp>

class Button : Object
{
private: 
    SDL_Renderer* render;

    std::string name;

    std::vector<Sprite*> sprites;
    BUTTON_STATUS status;

protected: 
    void importSprites();
    void importFromJson();
public: 
    Button(SDL_Renderer* render, SDL_Rect view);
    ~Button();

    void rendering();

    void linking(std::string n);
};

#endif 
