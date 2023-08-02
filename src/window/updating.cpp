#include <window.hpp>

void MyWindow::setDisplay(std::string name)
{
    if(display_pool.find(name) == display_pool.end())
        display_pool[name] = new Display(render, viewport);
    display_pool[name]->linking(name);
    current_display = display_pool[name];
}

void MyWindow::react(Button* but)
{
    if(but == nullptr) return ;
    if(but->getAction() == BUTTON_ACTION::CHANGE_SCREEN) 
    {
        UImutex.lock();
        setDisplay(but->getNextScreen());
        UImutex.unlock();
    }
}
