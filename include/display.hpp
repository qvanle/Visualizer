#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>
#include <string>

#include <SDL2/SDL.h>

#include <services.hpp>
#include <GLOBAL.hpp>
#include <object.hpp>
#include <button.hpp>

class Display : protected Object 
{
private: 
    SDL_Renderer* render; 
    
    std::string name;
    
    SDL_Rect viewPort;
    std::vector<Button*> buts;
protected:
    void initBackground(const json& mem);
    void initButtons(const json& mem);
    void importFromJson();

    bool isButtonReceiveEvent(SDL_Event& e);
public:
    Display(SDL_Renderer* r, SDL_Rect v);
    ~Display();
    
    void linking(std::string n);
    
    bool isReceiveEvent(SDL_Event& e);
    void react(SDL_Event& e);

    void rendering();
};

#endif 
