#include <data_structures.hpp>

void DataStructures::init(std::vector<int> v)
{
    switch (type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            avl->init(v);
            break;
        default:
            break;
    }
}

void DataStructures::init(std::vector<std::string> v)
{
    switch (type)
    {
        case DATA_STRUCTURES_TYPE::TRIE: 
            trie->init(v);
            break;
        case DATA_STRUCTURES_TYPE::AVL: 
        {
            std::vector<int> temp;
            for(auto i : v) 
                temp.push_back(NUMBER::stringToInt(i));
            avl->init(temp);
        }
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
        {
            int key = NUMBER::stringToInt(v[0]);
            v.erase(v.begin());
            std::vector<int> temp;
            for(auto i : v) 
                temp.push_back(NUMBER::stringToInt(i));
            hashTable->init(temp, key);
            break;
        }
        default :
            break;
    }
}

void DataStructures::insert(std::string v)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            avl->insert(NUMBER::stringToInt(v));
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            trie->insert(v);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            hashTable->insert(NUMBER::stringToInt(v));
            break;
        default:
            break;
    }
}

void DataStructures::remove(std::string v)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            avl->remove(NUMBER::stringToInt(v));
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            trie->remove(v);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            hashTable->remove(NUMBER::stringToInt(v));
            break;
        default:
            break;
    }
}

void DataStructures::search(std::string v)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            avl->search(NUMBER::stringToInt(v));
            break;
        case DATA_STRUCTURES_TYPE::TRIE:
            trie->search(v);
            break;
        case DATA_STRUCTURES_TYPE::HASH_TABLE:
            hashTable->search(NUMBER::stringToInt(v));
            break;
        default:
            break;
    }
}

DATA_STRUCTURES_TYPE DataStructures::getDataType()
{
    return type;
}

std::string DataStructures::getName()
{
    return name;
}
