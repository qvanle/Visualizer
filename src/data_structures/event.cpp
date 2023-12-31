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
            if(minheap != nullptr && minheap->isReceiveEvent(e))
                return true;
            if(graph != nullptr && graph->isReceiveEvent(e))
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
         but = avl->react(e);
    if(but == nullptr && trie != nullptr && trie->isReceiveEvent(e))
        but = trie->react(e);
    if(but == nullptr && hashTable != nullptr && hashTable->isReceiveEvent(e))
        but = hashTable->react(e);
    if(but == nullptr && minheap != nullptr && minheap->isReceiveEvent(e))
        but = minheap->react(e);
    if(but == nullptr && graph != nullptr && graph->isReceiveEvent(e))
        but = graph->react(e);
    if(but != nullptr) return but;
    for(auto &i : displays)
        if(i->isReceiveEvent(e))
            but = i->react(e);
    return but;
}

void HashTable::closeScript()
{
    currentScript = nullptr;
}
