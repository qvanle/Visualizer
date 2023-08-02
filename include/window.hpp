#ifndef WINDOW 
#define WINDOW 

#include <vector> 
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>
#include <queue>


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

    std::queue<SDL_Event> event_pool;
    std::mutex EVmutex;
    std::condition_variable EVcond;

    std::vector<std::thread> thread_pool;
   
    std::map<std::string, Display*> display_pool;
    Display* current_display;

protected:
    void initSDL2();
    void rendering();
    void interacting();
    void getEvent();
    void react(Button* but);
    void setDisplay(std::string name);
public:
    MyWindow();
    ~MyWindow();

    bool isClosed();
    bool isOpen();

    void run();
};

#endif 
