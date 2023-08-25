#include <data_structures.hpp>
// goBack
void DataStructures::goBack()
{

}

// goNext
void DataStructures::goNext()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->goNext();
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            if(trie == nullptr) return ;
            trie->goNext();
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->goNext();
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->goNext();
            break;
        default:
            break;
    }
}

// goOn
void DataStructures::goOn()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->goOn();
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            if(trie == nullptr) return ;
            trie->goOn();
            break; 
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->goOn();
            break; 
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->goOn();
            break;
        default:
            break;
    }
}

// goOff
void DataStructures::goOff()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->goOff();
            break;
        case DATA_STRUCTURES_TYPE::TRIE: 
            if(trie == nullptr) return ;
            trie->goOff();
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->goOff();
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->goOff();
            break;
        default:
            break;
    }
}

// speedUp 
void DataStructures::speedUp()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->speedUp();
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            if(trie == nullptr) return ;
            trie->speedUp();
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->speedUp();
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->speedUp();
            break;
        default:
            break;
    }
}

// slowDown
void DataStructures::slowDown()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->slowDown();
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            if(trie == nullptr) return ;
            trie->slowDown();
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->slowDown();
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->slowDown();
            break;
        default:
            break;
    }
}

void DataStructures::closeScript()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->closeScript();
            break;
        case DATA_STRUCTURES_TYPE::TRIE: 
            if(trie == nullptr) return ;
            trie->closeScript();
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            if(hashTable == nullptr) return ;
            hashTable->closeScript();
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            if(minheap == nullptr) return ;
            minheap->closeScript();
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            if(minheap == nullptr) return ;
            minheap->closeScript();
            break;
        case DATA_STRUCTURES_TYPE::GRAPH: 
            if(graph == nullptr) return ;
            graph->closeScript();
            break;
        default:
            break;
    }
}
