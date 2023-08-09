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
        inputbox_pool[name] = new InputBox(render, myfont);
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

void MyWindow::runOperator()
{
}

void MyWindow::react(Button* but)
{
    if(but == nullptr) return ;
    switch (but->getAction())
    {
        case BUTTON_ACTION::CHANGE_SCREEN:{
            setDisplay(but->getNextScreen());
            if(but->getDataType() != DATA_STRUCTURES_TYPE::NONE) 
                setDataType(but->getDataType());
            break;
        }
        case BUTTON_ACTION::INIT: {
            setInputBox(ds->getName() + "/init");
            break;
        }
        case BUTTON_ACTION::INSERT:{
            setInputBox(ds->getName() + "/insert");
            break;
        }
        case BUTTON_ACTION::DELETE:{
            setInputBox(ds->getName() + "/remove");
            break;
        }
        case BUTTON_ACTION::SEARCH:{
            setInputBox(ds->getName() + "/search");
            break;
        }
        case BUTTON_ACTION::DONE:{
            runOperator();
            inputbox = nullptr;
            break;
        }

        default: 
            break;
    }
}
