#include <window.hpp>
#include <sstream>

void MyWindow::setDisplay(std::string name)
{
    setInputBox("nullptr");
    renderMutex.lock();

    ds = nullptr;
    if(display_pool.find(name) == display_pool.end())
    {
        display_pool[name] = new Display(render, viewport);
        display_pool[name]->linking(name);
    }
    current_display = display_pool[name];

    renderMutex.unlock();
}

void MyWindow::setInputBox(std::string name)
{
    renderMutex.lock();
    if(name == "graph/edges")
    {
        auto i = inputbox_pool.find("graph/edges");
        if(i != inputbox_pool.end())
        {
            auto t = i->second;
            inputbox_pool.erase(i);
            delete t;
        }
        {
            inputbox_pool["graph/edges"] = new InputBox(render, myfont);
            inputbox_pool["graph/edges"]->setDuplicate(ds->capacity, ds->capacity);
            inputbox_pool["graph/edges"]->linking("graph/edges");
        }
    }
    if(inputbox_pool.find(name) == inputbox_pool.end())
    {
        inputbox_pool[name] = new InputBox(render, myfont);
        inputbox_pool[name]->linking(name);
    }
    inputbox = inputbox_pool[name];
    renderMutex.unlock();
}

void MyWindow::setDataType(DATA_STRUCTURES_TYPE type)
{
    renderMutex.lock();
    if(ds_pool.find(type) == ds_pool.end())
    {
        ds_pool[type] = new DataStructures(render, myfont, renderMutex);
        ds_pool[type]->setDataType(type);
    }
    ds = ds_pool[type];

    renderMutex.unlock();
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

        renderMutex.lock();
        if(inputbox == nullptr)
        {
            renderMutex.unlock();
            continue;
        }

        temp = inputbox;
        renderMutex.unlock();

        setInputBox("nullptr");

        renderMutex.lock();

        switch(temp->getOperator())
        {
            case DATA_STRUCTURES_OPERATOR::INIT:
                {
                    ds->init(temp);
                    break;
                }
            case DATA_STRUCTURES_OPERATOR::INSERT:
                ds->insert(temp);
                break;
            case DATA_STRUCTURES_OPERATOR::DELETE:
                ds->remove(temp);
                break;
            case DATA_STRUCTURES_OPERATOR::SEARCH:
                ds->search(temp);
                break;
            case DATA_STRUCTURES_OPERATOR::TOP: 
                ds->top();
                break;
            case DATA_STRUCTURES_OPERATOR::SIZE:
                ds->size();
            case DATA_STRUCTURES_OPERATOR::SETTING:
                ds->setting(temp);
            case DATA_STRUCTURES_OPERATOR::DIJKSTRA:
                ds->dijkstra(temp);
                break;
            case DATA_STRUCTURES_OPERATOR::MST:
                ds->mst();
                break;
            case DATA_STRUCTURES_OPERATOR::SCC:
                ds->scc();
                break;
        }
        renderMutex.unlock();
    }
}

void MyWindow::getDataFromFile(DATA_STRUCTURES_TYPE type)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:{
                                           std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::AVL_);
                                           if(mem.empty()) return ;
                                           renderMutex.lock();
                                           inputbox->setText(1, mem[0]);
                                           renderMutex.unlock();
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
                                            renderMutex.lock();
                                            inputbox->setText(1, total);
                                            renderMutex.unlock();
                                            break;
                                        }
        case DATA_STRUCTURES_TYPE::GRAPH:{
                                             std::ifstream fin(PATH::SAVING::GRAPH_);

                                             renderMutex.lock();
                                            
                                             fin >> ds->capacity;
                                             
                                             renderMutex.unlock();

                                             setInputBox("graph/edges");

                                             renderMutex.lock();

                                             for(int i = 0; i < ds->capacity; i++)
                                                 for(int j = 0; j < ds->capacity; j++)
                                                 {
                                                     int x;
                                                     fin >> x;
                                                     inputbox->setText(i * ds->capacity + j + 1, NUMBER::intToString(x));
                                                 }

                                             renderMutex.unlock();
                                             fin.close();
                                             break;
                                         }
        case DATA_STRUCTURES_TYPE::BTREE_4TH:{
                                                 std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::BTREE_4TH_);
                                                 break;
                                             }
        case DATA_STRUCTURES_TYPE::MIN_HEAP:{
                                                std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MIN_HEAP_);
                                                renderMutex.lock();
                                                inputbox->setText(1, mem[0]);
                                                renderMutex.unlock();
                                                break;
                                            }
        case DATA_STRUCTURES_TYPE::MAX_HEAP:{
                                                std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::MAX_HEAP_);
                                                renderMutex.lock();
                                                inputbox->setText(1, mem[0]);
                                                renderMutex.unlock();
                                                break;
                                            }
        case DATA_STRUCTURES_TYPE::HASH_TABLE:{
                                                  std::vector<std::string> mem = FILEE::readFile(PATH::SAVING::HASH_TABLE_);
                                                  renderMutex.lock();
                                                  inputbox->setText(1, mem[0]);
                                                  inputbox->setText(2, mem[1]);
                                                  renderMutex.unlock();
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
                                           renderMutex.lock();
                                           inputbox->setText(1, mem);
                                           renderMutex.unlock();
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
        case BUTTON_ACTION::CHANGE_SCREEN:
            setDisplay(but->getNextScreen());
            if(but->getDataType() != DATA_STRUCTURES_TYPE::NONE) 
                setDataType(but->getDataType());
            break;

        case BUTTON_ACTION::INIT: 
            setInputBox(ds->getName() + "/init");
            break;
        
        case BUTTON_ACTION::SETTING: 
            setInputBox("setting");
            break;

        case BUTTON_ACTION::INSERT:
            setInputBox(ds->getName() + "/insert");
            break;

        case BUTTON_ACTION::DELETE:
            setInputBox(ds->getName() + "/remove");
            break;

        case BUTTON_ACTION::SEARCH:
            setInputBox(ds->getName() + "/search");
            break;

        case BUTTON_ACTION::SIZE:
            setInputBox(ds->getName() + "/size");
            break;

        case BUTTON_ACTION::TOP:
            setInputBox(ds->getName() + "/top");
            break;

        case BUTTON_ACTION::CONNECTED_COMPONENTS:
            setInputBox(ds->getName() + "/scc");
            break;

        case BUTTON_ACTION::DIJKSTRA: 
            setInputBox(ds->getName() + "/dijkstra");
            break;

        case BUTTON_ACTION::MST: 
            setInputBox(ds->getName() + "/mst");
            break;

        case BUTTON_ACTION::GO_BACK: 

            //ds->goBack();
            break;

        case BUTTON_ACTION::GO_NEXT: 

            //ds->goNext();
            break;

        case BUTTON_ACTION::GO_ON: 

            //ds->goOn();
            break;

        case BUTTON_ACTION::GO_OFF: 

            //ds->goOff();
            break;

        case BUTTON_ACTION::SPEED_UP: 

            //ds->speedUp();
            break;

        case BUTTON_ACTION::SLOW_DOWN: 

            //ds->slowDown();
            break;

        case BUTTON_ACTION::DONE:

            step_mutex.lock();
            isQueuingStep = true;
            step_mutex.unlock();
            step_cond.notify_one();

            break;

        case BUTTON_ACTION::EDGES: 

            int n;
            renderMutex.lock();

            n = NUMBER::stringToInt(inputbox->getText(1));
            n = std::min(n, 9);
            n = std::max(n, 2);
            if(ds != nullptr) ds->capacity = n;

            renderMutex.unlock();
            setInputBox("graph/edges");
            break;

        case BUTTON_ACTION::CLOSE: 

            renderMutex.lock();
            ds->closeScript();
            renderMutex.unlock();
            break;

        case BUTTON_ACTION::RANDOM:{
                                       int n = RANDOM::getInt(1, 32);
                                       std::string mem = RANDOM::getInt(n, 1, 999);

                                       renderMutex.lock();
                                       inputbox->setText(1, mem);

                                       renderMutex.unlock();
                                       break;
                                   }
        case BUTTON_ACTION::RANDOM2: {

                                         renderMutex.lock();
                                         inputbox->setText(1, RANDOM::getInt(1, 1, 999));
                                         renderMutex.unlock();
                                         break;
                                     }
        case BUTTON_ACTION::RANDOM3:{
                                        int n = RANDOM::getInt(1, 16);
                                        int m = RANDOM::getInt(1, 16);
                                        char upperbound = RANDOM::getInt(97 + 5, 97 + 25);
                                        std::string mem;
                                        mem = RANDOM::getString(m, 'a', upperbound);

                                        for(int i = 1; i < n; i++)
                                            mem += " " + RANDOM::getString(m, 'a', upperbound);

                                        renderMutex.lock();
                                        inputbox->setText(1, mem);
                                        renderMutex.unlock();
                                        break;
                                    }
        case BUTTON_ACTION::RANDOM4: 
                                    {
                                        int m = RANDOM::getInt(1, 16);
                                        renderMutex.lock();
                                        inputbox->setText(1, RANDOM::getString(m, 'a', 'z'));
                                        renderMutex.unlock();
                                        break;
                                    }
        case BUTTON_ACTION::RANDOM5: {
                                         int n = RANDOM::getInt(1, 64);
                                         std::string mem = RANDOM::getInt(n, 1, 999);

                                         renderMutex.lock();
                                         inputbox->setText(2, mem);
                                         renderMutex.unlock();
                                         break;
                                     }
        case BUTTON_ACTION::RANDOM6: {
                                         renderMutex.lock();
                                         for(int i = 0; i < ds->capacity; i++)
                                             for(int j = 0; j < ds->capacity; j++)
                                             {
                                                 if(i == j) continue;
                                                 if(RANDOM::getInt(1, 100) <= 30) 
                                                     inputbox->setText(i * ds->capacity + j + 1, RANDOM::getInt(1, 1, 99));
                                                 else 
                                                     inputbox->setText(i * ds->capacity + j + 1, "0");
                                             }
                                         renderMutex.unlock();
                                         break;
                                     }
        case BUTTON_ACTION::RANDOM7: { 
                                         renderMutex.lock();
                                         inputbox->setText(1, NUMBER::intToString(RANDOM::getInt(0, ds->capacity - 1)));
                                         renderMutex.unlock();
                                         break;
                                     }
        case BUTTON_ACTION::RANDOM8: { 
                                         renderMutex.lock();
                                         inputbox->setText(2, NUMBER::intToString(RANDOM::getInt(0, ds->capacity - 1)));
                                         renderMutex.unlock();
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
