#include <window.hpp>

void MyWindow::setDisplay(std::string name)
{
    ds = nullptr;
    inputbox = nullptr;
    if(display_pool.find(name) == display_pool.end())
        display_pool[name] = new Display(render, viewport);
    display_pool[name]->linking(name);
    current_display = display_pool[name];
}

void MyWindow::setInputBox(std::string name)
{
    if(inputbox_pool.find(name) == inputbox_pool.end())
        inputbox_pool[name] = new InputBox(render);
    inputbox_pool[name]->linking(name);
    inputbox = inputbox_pool[name];
}

void MyWindow::setDataType(DATA_STRUCTURES_TYPE type)
{
    if(ds_pool.find(type) == ds_pool.end())
        ds_pool[type] = new DataStructures(render);
    ds_pool[type]->setDataType(type);
    ds = ds_pool[type];
}

void MyWindow::react(Button* but)
{
    if(but == nullptr) return ;
    switch (but->getAction())
    {
        case BUTTON_ACTION::CHANGE_SCREEN:{
            UImutex.lock();
            setDisplay(but->getNextScreen());
            if(but->getDataType() != DATA_STRUCTURES_TYPE::NONE) 
                setDataType(but->getDataType());
            UImutex.unlock();
            break;
        }
        case BUTTON_ACTION::INIT: {
            UImutex.lock();
            setInputBox(ds->getName() + "/init");
            UImutex.unlock();
            break;
        }
        case BUTTON_ACTION::INSERT:{
            UImutex.lock();
            setInputBox(ds->getName() + "/insert");
            UImutex.unlock();
            break;
        }
        case BUTTON_ACTION::DELETE:{
            UImutex.lock();
            setInputBox(ds->getName() + "/remove");
            UImutex.unlock();
            break;
        }
        case BUTTON_ACTION::SEARCH:{
            UImutex.lock();
            setInputBox(ds->getName() + "/search");
            UImutex.unlock();
            break;
        }
        default: 
            break;
    }
}
