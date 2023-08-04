#include <window.hpp>

void MyWindow::setDisplay(std::string name)
{
    if(ds != nullptr)
    {
        delete ds;
        ds = nullptr;
    }
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
        if(but->getDataType() != DATA_STRUCTURES_TYPE::NONE) 
        {
            ds = new DataStructures(render);
            ds->setDataType(but->getDataType());
        }
        UImutex.unlock();
    }
}
