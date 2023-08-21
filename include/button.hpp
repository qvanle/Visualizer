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

    std::string name;

    std::vector<Sprite*> sprites;
    BUTTON_STATUS status;
    BUTTON_ACTION action;
    json args;

protected: 
    void initSprites(const json& mem);
    void initBackground(const json& mem);
    void initAction(const json& mem);
    void importFromJson();

    bool isChoosed(int x, int y);
public: 
    Button(SDL_Renderer* render);
    ~Button();
    
    bool isHover(int x, int y);
    bool isClicked(int x, int y);

    BUTTON_ACTION getAction();
    std::string getNextScreen();
    DATA_STRUCTURES_TYPE getDataType();
    INPUT_TYPE getInputType();

    bool isReceiveEvent(SDL_Event& e);

    void rendering();

    void linking(std::string n);
    void move(int dx, int dy);
};

#endif 
