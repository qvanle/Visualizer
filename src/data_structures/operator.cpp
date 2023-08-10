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
}

void DataStructures::insert(std::string v)
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            avl->insert(NUMBER::stringToInt(v));
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
