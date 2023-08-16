#include "GLOBAL.hpp"
#include <data_structures.hpp>



bool DataStructures::isReceiveEvent(SDL_Event& e)
{
    switch(e.type) 
    {
        case SDL_QUIT: 
            return false;
            break;
        default: 
            if(avl != nullptr && avl->isReceiveEvent(e))
                return true;
            if(trie != nullptr && trie->isReceiveEvent(e))
                return true;
            if(hashTable != nullptr && hashTable->isReceiveEvent(e))
                return true;
            for(auto &i : displays)
                if(i->isReceiveEvent(e))
                    return true;
            return false;
            break;
    }
}


Button* DataStructures::react(SDL_Event& e)
{
    Button* but = nullptr;
    if(avl != nullptr && avl->isReceiveEvent(e))
         avl->react(e);
    if(trie != nullptr && trie->isReceiveEvent(e))
        trie->react(e);
    if(hashTable != nullptr && hashTable->isReceiveEvent(e))
        hashTable->react(e);
    for(auto &i : displays)
        if(i->isReceiveEvent(e))
            but = i->react(e);
    return but;
}
