#include <window.hpp>

void MyWindow::setDisplay(std::string name)
{
    setInputBox("nullptr");
    display_mutex.lock();

    ds = nullptr;
    if(display_pool.find(name) == display_pool.end())
    {
        display_pool[name] = new Display(render, viewport);
        display_pool[name]->linking(name);
    }
    current_display = display_pool[name];

    display_mutex.unlock();
}

void MyWindow::setInputBox(std::string name)
{
    inputbox_mutex.lock();
    if(inputbox_pool.find(name) == inputbox_pool.end())
    {
        inputbox_pool[name] = new InputBox(render, myfont);
        inputbox_pool[name]->linking(name);
    }
    inputbox = inputbox_pool[name];
    inputbox_mutex.unlock();
}

void MyWindow::setDataType(DATA_STRUCTURES_TYPE type)
{
    ds_mutex.lock();
    if(ds_pool.find(type) == ds_pool.end())
    {
        ds_pool[type] = new DataStructures(render, myfont, ds_mutex);
        ds_pool[type]->setDataType(type);
    }
    ds = ds_pool[type];

    ds_mutex.unlock();
}

void MyWindow::runOperator()
{
    while(isOpen())
    {
        std::unique_lock<std::mutex> lock(step_mutex);
        step_cond.wait(lock, [&](){return isClosed() || isQueuingStep;});
        if(isClosed()) break;

        isQueuingStep = false;

        InputBox* temp;

        inputbox_mutex.lock();
        if(inputbox == nullptr)
        {
            inputbox_mutex.unlock();
            continue;
        }

        temp = inputbox;
        inputbox_mutex.unlock();

        setInputBox("nullptr");

        switch(temp->getOperator())
        {
            case DATA_STRUCTURES_OPERATOR::INIT:
            {
                ds_mutex.lock();
                ds->init(temp);
                ds_mutex.unlock();
                break;
            }
            case DATA_STRUCTURES_OPERATOR::INSERT:
                ds_mutex.lock();
                ds->insert(temp);
                ds_mutex.unlock();
                break;
            case DATA_STRUCTURES_OPERATOR::DELETE:
                ds_mutex.lock();
                ds->remove(temp);
                ds_mutex.unlock();
                break;
            case DATA_STRUCTURES_OPERATOR::SEARCH:
                ds_mutex.lock();
                ds->search(temp);
                ds_mutex.unlock();
                break;
            default :
                break;
        }
    }
}

void MyWindow::getDataFromFile(DATA_STRUCTURES_TYPE type)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::AVL_);
            if(mem.empty()) return ;
            inputbox_mutex.lock();
            inputbox->setText(1, mem[0]);
            inputbox_mutex.unlock();
            break;
        }
        case DATA_STRUCTURES_TYPE::TRIE:{
            std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::TRIE_);
            if(mem.empty()) return ;
            std::string total = "";
            for(int i = 0; i < mem.size(); i++)
            {
                total += mem[i];
                if(i != mem.size() - 1) total += " ";
            }
            inputbox_mutex.lock();
            inputbox->setText(1, total);
            inputbox_mutex.unlock();
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
            int n = RANDOM::getInt(1, 32);
            std::string mem = RANDOM::getInt(n, 1, 999);
            inputbox_mutex.lock();
            inputbox->setText(1, mem);
            inputbox_mutex.unlock();
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
        case BUTTON_ACTION::GO_BACK: 
        {
            ds_mutex.lock();
            //ds->goBack();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::GO_NEXT: 
        {
            ds_mutex.lock();
            //ds->goNext();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::GO_ON: 
        {
            ds_mutex.lock();
            //ds->goOn();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::GO_OFF: 
        {
            ds_mutex.lock();
            //ds->goOff();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::SPEED_UP: 
        {
            ds_mutex.lock();
            //ds->speedUp();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::SLOW_DOWN: 
        {
            ds_mutex.lock();
            //ds->slowDown();
            ds_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::DONE:{

            step_mutex.lock();
            isQueuingStep = true;
            step_mutex.unlock();
            step_cond.notify_one();

            break;
        }
        case BUTTON_ACTION::RANDOM:{
            int n = RANDOM::getInt(1, 32);
            std::string mem = RANDOM::getInt(n, 1, 999);

            inputbox_mutex.lock();
            inputbox->setText(1, mem);
            inputbox_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::RANDOM2: 
        {
            inputbox_mutex.lock();
            inputbox->setText(1, RANDOM::getInt(1, 1, 999));
            inputbox_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::RANDOM3: 
        {

            int n = RANDOM::getInt(1, 16);
            int m = RANDOM::getInt(1, 16);
            char upperbound = RANDOM::getInt(97 + 5, 97 + 25);
            std::string mem;
            mem = RANDOM::getString(m, 'a', upperbound);

            for(int i = 1; i < n; i++)
                mem += " " + RANDOM::getString(m, 'a', upperbound);

            inputbox_mutex.lock();
            inputbox->setText(1, mem);
            inputbox_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::RANDOM4: 
        {
            int m = RANDOM::getInt(1, 16);
            inputbox_mutex.lock();
            inputbox->setText(1, RANDOM::getString(m, 'a', 'z'));
            inputbox_mutex.unlock();
            break;
        }
        case BUTTON_ACTION::RANDOM5: 
        {
            int n = RANDOM::getInt(1, 64);
            std::string mem = RANDOM::getInt(n, 1, 999);

            inputbox_mutex.lock();
            inputbox->setText(2, mem);
            inputbox_mutex.unlock();
        }
        case BUTTON_ACTION::FILE :{
            
            getDataFromFile(ds->getDataType());
            break;
        }

        default: 
            break;
    }
}
