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
}

void DataStructures::remove(std::string v)
{
}

void DataStructures::search(std::string v)
{
}

DATA_STRUCTURES_TYPE DataStructures::getDataType()
{
    return type;
}

std::string DataStructures::getName()
{
    return name;
}
