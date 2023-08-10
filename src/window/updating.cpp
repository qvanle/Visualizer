#include <window.hpp>

void MyWindow::setDisplay(std::string name)
{
    ds = nullptr;
    inputbox = nullptr;
    if(display_pool.find(name) == display_pool.end())
    {
        display_pool[name] = new Display(render, viewport);
        display_pool[name]->linking(name);
    }
    current_display = display_pool[name];
}

void MyWindow::setInputBox(std::string name)
{
    if(inputbox_pool.find(name) == inputbox_pool.end())
    {
        inputbox_pool[name] = new InputBox(render, myfont);
        inputbox_pool[name]->linking(name);
    }
    inputbox = inputbox_pool[name];
}

void MyWindow::setDataType(DATA_STRUCTURES_TYPE type)
{
    if(ds_pool.find(type) == ds_pool.end())
    {
        ds_pool[type] = new DataStructures(render, myfont);
        ds_pool[type]->setDataType(type);
    }
    ds = ds_pool[type];
}

void MyWindow::runOperator()
{
    switch(inputbox->getOperator())
    {
        case DATA_STRUCTURES_OPERATOR::INIT:
        {
            std::vector<int> value = NUMBER::stringToArray(inputbox->getText(1));
            ds->init(value);
            break;
        }
        default :
            break;
    }
}

void MyWindow::getDataFromFile(DATA_STRUCTURES_TYPE type)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::AVL_);
            if(mem.empty()) return ;
            inputbox->setText(1, mem[0]);
            break;
        }
        case DATA_STRUCTURES_TYPE::TRIE:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::TRIE_);
            break;
        }
        case DATA_STRUCTURES_TYPE::GRAPH:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::GRAPH_);
            break;
        }
        case DATA_STRUCTURES_TYPE::BTREE_4TH:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::BTREE_4TH_);
            break;
        }
        case DATA_STRUCTURES_TYPE::MIN_HEAP:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MIN_HEAP_);
            break;
        }
        case DATA_STRUCTURES_TYPE::MAX_HEAP:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MAX_HEAP_);
            break;
        }
        case DATA_STRUCTURES_TYPE::HASH_TABLE:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::HASH_TABLE_);
            break;
        }
        case DATA_STRUCTURES_TYPE::HEAP:{
            break;
        }
        case DATA_STRUCTURES_TYPE::NONE:{
            break;
        }
    }

}

void MyWindow::getDataFromRandom(DATA_STRUCTURES_TYPE type)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:{
            int n = RANDOM::getInt(1, 20);
            std::string mem = RANDOM::getInt(n, 1, 999);
            inputbox->setText(1, mem);
            break;
        }
        case DATA_STRUCTURES_TYPE::TRIE:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::TRIE_);
            break;
        }
        case DATA_STRUCTURES_TYPE::GRAPH:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::GRAPH_);
            break;
        }
        case DATA_STRUCTURES_TYPE::BTREE_4TH:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::BTREE_4TH_);
            break;
        }
        case DATA_STRUCTURES_TYPE::MIN_HEAP:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MIN_HEAP_);
            break;
        }
        case DATA_STRUCTURES_TYPE::MAX_HEAP:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MAX_HEAP_);
            break;
        }
        case DATA_STRUCTURES_TYPE::HASH_TABLE:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::HASH_TABLE_);
            break;
        }
        case DATA_STRUCTURES_TYPE::HEAP:{
            break;
        }
        case DATA_STRUCTURES_TYPE::NONE:{
            break;
        }
    }

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
        case BUTTON_ACTION::RANDOM:{
            getDataFromRandom(ds->getDataType());
            break;
        }
        case BUTTON_ACTION::FILE :{
            
            getDataFromFile(ds->getDataType());
            break;
        }

        default: 
            break;
    }
}
