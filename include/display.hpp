#ifndef DISPLAY
#define DISPLAY 

#include <vector>
#include <string>

#include <SDL2/SDL.h>

#include <services.hpp>
#include <GLOBAL.hpp>
#include <object.hpp>

class Display : protected Object 
{
private: 
    SDL_Renderer* render; 
    
    std::string name;
    
    SDL_Rect viewPort;
protected:
    void initBackground(const json& mem);
    void importFromJson();
public:
    Display(SDL_Renderer* r, SDL_Rect v);
    ~Display();
    
    void linking(std::string n);

    void rendering();
};

#endif 
