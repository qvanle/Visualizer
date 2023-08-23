#include "GLOBAL.hpp"
#include <data_structures.hpp>

DATA_STRUCTURES_TYPE DataStructures::getDataType()
{
    return type;
}

std::string DataStructures::getName()
{
    return name;
}

void DataStructures::init(InputBox* inp)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            initAVL(inp);
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            initTrie(inp);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            initHashTable(inp);
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            initMinHeap(inp);
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            initMinHeap(inp);
            break;
        case DATA_STRUCTURES_TYPE::BTREE_4TH:
            //initBTree4th(inp);
            break;
        case DATA_STRUCTURES_TYPE::GRAPH:
            //initGraph(inp);
            break;
        case DATA_STRUCTURES_TYPE::NONE:
            break;
    }
}

void DataStructures::insert(InputBox* inp)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            insertAVL(inp);
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            insertTrie(inp);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            insertHashTable(inp);
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            insertMinHeap(inp);
            break;
        default:
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            insertMinHeap(inp);
            break;
        case DATA_STRUCTURES_TYPE::BTREE_4TH:
            break;
        case DATA_STRUCTURES_TYPE::GRAPH:
            break;
        case DATA_STRUCTURES_TYPE::NONE:
            break;
    }
}

void DataStructures::remove(InputBox* inp)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            removeAVL(inp);
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            removeTrie(inp);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            removeHashTable(inp);
            break;
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            removeMinHeap(inp);
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            removeMinHeap(inp);
            break;
        case DATA_STRUCTURES_TYPE::BTREE_4TH:
            break;
        case DATA_STRUCTURES_TYPE::GRAPH:
            break;
        case DATA_STRUCTURES_TYPE::NONE:
            break;
    }
}

void DataStructures::search(InputBox* inp)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            searchAVL(inp);
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            searchTrie(inp);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            searchHashTable(inp);
            break;
        default:
            break;
    }
}

void DataStructures::top()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            minheap->top();
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            minheap->top();
            break;
            break;
        default:
            break;
    }
}


void DataStructures::size()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::MIN_HEAP:
            minheap->size();
            break;
        case DATA_STRUCTURES_TYPE::MAX_HEAP:
            minheap->size();
            break;
        default:
            break;
    }
}

