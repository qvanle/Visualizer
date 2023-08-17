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
        default:
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
        default:
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
        default:
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


