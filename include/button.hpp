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
    BUTTON_ACTION action;

protected: 
    void initSprites(const json& mem);
    void initBackground(const json& mem);
    void importFromJson();

    bool isChoosed(int x, int y);
public: 
    Button(SDL_Renderer* render, SDL_Rect view);
    ~Button();
    
    bool isHover(int x, int y);
    bool isClicked(int x, int y);

    BUTTON_ACTION getAction();

    void rendering();

    void linking(std::string n);
};

#endif 
