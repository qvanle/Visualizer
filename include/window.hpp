#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector> 
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>
#include <queue>


#include <SDL2/SDL.h>

#include <GLOBAL.hpp>
#include <display.hpp>
#include <data_structures.hpp>
#include <inputbox.hpp>
/** 
 * @brief Window class
 * class that create a window and manage it
 *
 * Finite state machine
 *
 * handle thread
 */
class MyWindow 
{
private:
    
    int HEIGHT;
    int WIDTH;
    WINDOW_STATUS status;
    std::mutex status_mutex;
    int FPS;

    SDL_Window* window;
    TTF_Font* myfont;
    

    SDL_Renderer* render;

    SDL_Rect viewport;

    std::queue<SDL_Event> event_pool;
    std::condition_variable EVcond;

    std::vector<std::thread> thread_pool;
   
    std::map<std::string, Display*> display_pool;
    Display* current_display;

    std::map<DATA_STRUCTURES_TYPE, DataStructures*> ds_pool;
    DataStructures *ds;
    
    InputBox* inputbox;
    std::map<std::string, InputBox*> inputbox_pool;

    std::mutex step_mutex;
    bool isQueuingStep;
    std::condition_variable step_cond;
    std::mutex event_mutex;
    
    std::mutex renderMutex;
protected:
    void initSDL2();
    void rendering();
    void interacting();
    void getEvent();
    void react(Button* but);
    void setDisplay(std::string name);
    void setInputBox(std::string name);
    void setDataType(DATA_STRUCTURES_TYPE type);
    void runOperator();
    void getDataFromFile(DATA_STRUCTURES_TYPE type);
    void getDataFromRandom(DATA_STRUCTURES_TYPE type);
public:
    MyWindow();
    ~MyWindow();

    bool isClosed();
    bool isOpen();

    void run();
};

#endif 
