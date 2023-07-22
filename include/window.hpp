#ifndef WINDOW 
#define WINDOW 

#include <vector> 
#include <thread>
#include <mutex>
#include <map>

#include <SDL2/SDL.h>

#include <GLOBAL.hpp>
#include <display.hpp>

class MyWindow 
{
private:
    
    int HEIGHT;
    int WIDTH;
    WINDOW_STATUS status;
    int FPS;

    SDL_Window* window;
    

    SDL_Renderer* render;
    std::mutex UImutex;
    SDL_Rect viewport;

    SDL_Event event;
    std::mutex EVmutex;

    std::vector<std::thread> thread_pool;
   
    std::map<std::string, Display*> display_pool;
    std::string current_display;

protected:
    void initSDL2();
    void rendering();
    void interacting();
public:
    MyWindow();
    ~MyWindow();

    bool isClosed();
    bool isOpen();

    void run();
};

#endif 
