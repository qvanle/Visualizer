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
        default:
            break;
    }
}
